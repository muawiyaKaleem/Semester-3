#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<fstream>
using namespace std;

int main()
 {
  int array[5][5];
  int output[5];
  int value , sum;

  fstream my_file;
  my_file.open("my_file.txt",ios::out);

  for(int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
        do
        {
            value = rand();
        }while(value > 50);
        
        my_file << value << '\t';
    }
    my_file << endl;
  }

  my_file.close();

  my_file.open("my_file.txt",ios::in);

	for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            my_file >> array[i][j];
            sum += array[i][j];
        }
        
        output[i] = sum;
        sum=0;
    }
	
    my_file.close();
	
	for(int i = 0; i < 5; i++)
    {
		for(int j=0;j<5;j++)
        {
			cout << array[i][j] << "\t\t";
		}
		cout << " => " << output[i] << endl;
    }

  return 0;
}