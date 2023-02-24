#include<iostream>
using namespace std;

int func(int x)
{
    if (x==1)
    {
        cout<<x<<"---"<<endl;
        return x;
    }
    
    cout<<x<<"+"<<"func("<<x-1<<")"<<endl;
    return x+func(x-1);
}

int Even(int x)
{
    if(x==1)
    {
        return x;
    }

    if(x%2==0)
    cout<<x<<endl;
    return Even(x-1);
}