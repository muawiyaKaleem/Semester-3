#include<iostream>
using namespace std;

class Stack
{

    int *arr,limit,count,top;

public:
    
    Stack(int l)
    {
        count = 0;
        limit = l;
        arr = new int[limit];
        top = -1;
    }

    void Push(int value)
    {
        if (count == limit )
        {
            cout << "Stack is Full" << endl << endl;
            return;
        }

        arr[++top] = value;
        count++;

    }

    void Pop()
    {
        if (count == 0)
        {
            cout << "Stack is Empty" << endl;
            return;
        }

            arr[top--];
            count--;
    }

    void Peak()
    {
        if (count == 0)
        {
            cout << "Stack is Empty" << endl << endl;
        }

        else
        {
            cout<<"Data on the Top => " << arr[top] << endl<< endl;
        }
    }

    // stack does not allow to see all its members at once, it is illegal
    // printing is just for programers satisfaction

    void Printing()
    {
        cout << "Height of the stack => " << count << endl << endl;

        if (count == 0)
        {
            cout << "Stack is Empty" << endl << endl;
        }

        else
        {
            cout<< "TOP" << endl << "---" << endl;
            
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl << "---" << endl;
            }
            
            cout << "END" << endl << endl;
        }
    }
};

int main()
{
    int limit , choice , value;
    char c;

    cout<<"\n\nEnter the Limit of the Stack => ";
    cin >> limit;
    
    Stack S(limit);

    do
    {
        cout << "\n\nOperations on Array Stack :-\n\n";

        cout << "Press 1 => Push\n";
        cout << "Press 2 => Pop\n";
        cout << "Press 3 => Peak\n";
        cout << "Press 4 => Show the Array Stack\n\n";
        
        cout << "Enter Your Choice => ";
        cin >> choice;

        cout<< endl;

        if (choice == 1)
        {
            cout << "Enter the value of the Node to Push => ";
            cin >> value;
            
            S.Push(value);
        }

        else if (choice == 2 )
        {
            S.Pop();
        }
        
        else if (choice == 3)
        {
            S.Peak();
        }

        else if (choice == 4)
        {
            S.Printing();
        }

        cout << endl;
        cout << "Press y/Y => Repeat the Procedure\n";
        cout << "Press Any Key to exit\n\n";
        cout<< "Enter Your Choice => ";
        cin >> c;

    } while (c == 'y' || c == 'Y');

    return 0;
}