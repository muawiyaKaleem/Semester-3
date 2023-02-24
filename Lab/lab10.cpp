#include<iostream>
using namespace std;

void largest(int a[],int *l)
{
    for(int i = 0; i < *l ; i++)
    {
        cout<<*a<<endl;
        a++;
    }
}
int main()
{
    int *k;

    int b;
    k = &b;
    
    int a[10] = {2,5,6,4,-1,10,5,7,4,9};

    for(int i = 0; i<10 ; i++)
    {
        for(int j = 0; j<10 ; j++)
        {
            if( *(a+i) < *(a+j) )
            {
                continue;
            }

            else
            {
                swap(*(a+i),*(a+j));
            }
        
        }    
    }

    cout<<"Enter the Value of K => ";
    cin>>*k;

    largest(a,k);
}