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

class Queue
{
    int limit , count;
    node *front , *rear;
    
    public:
        Queue(int l)
        {
            limit = l;
            front = rear = NULL;
        }

    void Enqueue(int value)
    {
        if (count == limit)
        {
            cout << "\n\nQueue is Full" << endl << endl;
            return;
        }
        
        node *t = new node(value);

        if(rear == NULL)
        {
            rear = t;
            rear->next = NULL;
            front = rear;
            count++;
        }

        else
        {
            rear->next = t;
            rear = t;
            t->next = NULL;
            count++;
        }
    }

    void Dequeue()
    {
        if(front == NULL)
        {
            cout << "\n\nQueue is Empty" << endl << endl;
        }

        else
        {
            node *temp = front;

            front = temp->next;
            delete temp;

            if (front == NULL)
            {
                rear = front;
            }
            
            count--;
        }
    }

    // Queue does not allow to see all its members at once, it is illegal
    // printing is just for programers satisfaction

    void Printing()
    {
        cout << "length of the stack => " << count << endl << endl;

        if (front == NULL)
        {
            cout << "Stack is Empty" << endl << endl;
        }

        else
        {
            node *temp = front;
            cout<< "Front" << endl << " --> ";
            
            while (temp != NULL)
            {
                if (temp != rear)
                {
                    cout << temp->data << " --> ";
                }
                temp = temp->next;
            }

            cout << rear->data << " <-- Rear" << endl << endl;
        }
    }
};

int main()
{
    int limit , choice , value;
    char c;

    cout<<"\n\nEnter the Limit of the Link List Queue => ";
    cin >> limit;
    
    Queue Q(limit);

    do
    {
        cout << "\n\nOperations on Link List Queue :-\n\n";

        cout << "Press 1 => Enqueue\n";
        cout << "Press 2 => Dequeue\n";
        cout << "Press 3 => Show the Queue\n\n";
        
        cout << "Enter Your Choice => ";
        cin >> choice;

        cout<< endl;

        if (choice == 1)
        {
            cout << "Enter the value of the Node to Enqueue => ";
            cin >> value;
            
            Q.Enqueue(value);
        }

        else if (choice == 2 )
        {
            Q.Dequeue();
        }

        else if (choice == 3)
        {
            Q.Printing();
        }

        cout << endl;
        cout << "Press y/Y => Repeat the Procedure\n";
        cout << "Press Any Key to exit\n\n";
        cout<< "Enter Your Choice => ";
        cin >> c;

    } while (c == 'y' || c == 'Y');

    return 0;
}