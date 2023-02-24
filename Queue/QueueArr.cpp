#include<iostream>
using namespace std;

class Stack
{

    int *arr,limit,count,front,rear;

public:
    
    Stack(int l)
    {
        count = 0;
        limit = l;
        arr = new int[limit];
        front = rear = -1;
    }

    void Enqueue(int value)
    {
        if (count == limit )
        {
            cout << "Queue is Full" << endl << endl;
            return;
        }

        arr[++rear] = value;
        count++;

    }

    void Dequeue()
    {
        if (count == 0)
        {
            cout << "Stack is Empty" << endl;
            return;
        }

            arr[front--];
            count--;
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
            cout<< "Front" << "--->";
            
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << "--->";
            }
            
            cout << "Rear" << endl << endl;
        }
    }
};

int main()
{
    int limit , choice , value;
    char c;

    cout<<"\n\nEnter the Limit of the Queue => ";
    cin >> limit;
    
    Stack S(limit);

    do
    {
        cout << "\n\nOperations on Array Queue :-\n\n";

        cout << "Press 1 => Push\n";
        cout << "Press 2 => Pop\n";
        cout << "Press 3 => Show the Array Queue\n\n";
        
        cout << "Enter Your Choice => ";
        cin >> choice;

        cout<< endl;

        if (choice == 1)
        {
            cout << "Enter the value of the Node to Push => ";
            cin >> value;
            
            S.Enqueue(value);
        }

        else if (choice == 2 )
        {
            S.Dequeue();
        }

        else if (choice == 3)
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