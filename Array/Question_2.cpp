#include<iostream>
using namespace std;

//function to print the table 
void Table(int *a , int *b) // pointer for value and limit of the table
{
  for (int i = 1 ; i <= *b ;  i++)
  {
    cout << *a << " * " << i << " => " << *a * i << endl;
  }
}

int main()
{
  //initializing the pointers and there corresponding values
  int n , l, *x = &n , *y = &l;
  char c , *z;

 //loop to take values 
  do
  {
    if(*z == 'y' || *z == 'Y')
    {
      cout << endl << endl << "xxx======xxx======xxx======xxx======xxx" << endl<<endl;
    }

    cout << "Enter the Table Number => ";
    cin >> *x;

    cout << "Enter the Table Limit => ";
    cin >> *y;

    cout<<endl<<endl;
    
    //function calling
    Table(x , y);

    cout<<endl;
    
    // for repeatation
    cout << "Do you want to Repeat the Program?\nEnter your choice (y/n) => ";
    cin>>*z;

  } while(*z == 'y' || *z == 'Y'); // repeat on this condition

  return 0;

}