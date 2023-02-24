#include<iostream>
using namespace std;

// function to generate the input Matrix
int Matrix_Input(int a[6][6])
{

  cout << "Enter the Elements of the Matrix(Input) : " << endl;
  
  // Loop to get values for input matrix
  for (int i = 0; i < 6; i++)
  {

    for (int j = 0; j < 6; j++)
    {
      cout << "Element ( "<< i << "," << j << " ) => ";
      cin >> a[i][j];
    }

  }

  //Printing of input Matrix
  cout << "\nMatrix(Input) : " << endl << endl;

  for (int i = 0; i < 6; i++)
  {

    for (int j = 0; j < 6; j++)
    {

      if (j == 0)
      {
        cout << " | ";

      }

      cout << a[i][j];

      if (j != 5) {
        cout << '\t';
      }

      if (j == 5)
      {
        cout << " | ";
      }

    }

    cout<<endl;

  }

  return a[6][6];  //returning the input Matrix
}


// function to generate the output Matrix
void Matrix_Output (int b[6][6] , float c[6][6])
{
  int sum = 0;
  float value;
  
  // I am unable to build the logic, it is too lengthy , sorryy
  
}

int main()
{
  //initializing input and output arrays
  int array_input[6][6];
  float array_output[6][6];

  //function calling
  array_input[6][6] = Matrix_Input(array_input);
  Matrix_Output(array_input , array_output);

  return 0;
}