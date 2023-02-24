#include<iostream>
using namespace std;

class node
{
    public:

        int data;
        node *next;

        node(int value)
        {
            data = value;
            next = NULL;
        }
};

class Stack
{

    int limit , count;
    node *top;

public:
    
    Stack(int l)
    {
        count = 0;
        limit = l;
        top = NULL;
    }

    void Push(int value)
    {
        if (count == limit )
        {
            cout << "Stack is Full" << endl << endl;
            return;
        }
        
        node *t = new node(value);

        if (top == NULL)
        {
            top = t;
            top->next = NULL;
            count++;
        }

        else
        {
            t->next = top;
            top = t;
            count++;
        }
    }

    void Pop()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty" << endl << endl;
        }
        
        else
        {
            node *temp = top;

            top = temp->next;
            delete temp;
            count--;
        }
    }

    void Peak()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty" << endl << endl;
        }

        else
        {
            cout<<"Data on the Top => " << top->data << endl<< endl;
        }
    }

    // stack does not allow to see all its members at once, it is illegal
    // printing is just for programers satisfaction

    void Printing()
    {
        cout << "Height of the stack => " << count << endl << endl;

        if (top == NULL)
        {
            cout << "Stack is Empty" << endl << endl;
        }

        else
        {
            node *temp = top;
            cout<< "TOP" << endl << "---" << endl;
            
            while (temp != NULL)
            {
                cout << temp->data << endl << "---" << endl;
                temp = temp->next;
            }

            cout << "NULL" << endl << endl;
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
        cout << "\n\nOperations on Link List Stack :-\n\n";

        cout << "Press 1 => Push\n";
        cout << "Press 2 => Pop\n";
        cout << "Press 3 => Peak\n";
        cout << "Press 4 => Show the Link List Stack\n\n";
        
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