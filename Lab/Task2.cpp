#include<iostream>
using namespace std;

class node
{
    public:

        int data;
        node *next , *prev;

        node(int value)
        {
            data = value;
            next = prev = NULL;
        }
};

class Queue
{
    node *front , *rear;
    
    public:
        Queue()
        {
            front = rear = NULL;
        }

    void Enqueue(int value)
    {   
        for (int i = 1; i <= value; i++)
        {
            node *t = new node(value);

            if(rear == NULL)
            {
                rear = t;
                rear->next = rear->prev = NULL;
                front = rear;
            }

            else
            {
                rear->next = t;
                t->prev = rear;
                t->next = NULL;
                rear = t;
            }
        }
    }

    // void Dequeue()
    // {
    //     if(front == NULL)
    //     {
    //         cout << "\n\nQueue is Empty" << endl << endl;
    //     }

    //     else
    //     {
    //         node *temp = front;

    //         front = temp->next;
    //         delete temp;

    //         if (front == NULL)
    //         {
    //             rear = front;
    //         }
    //     }
    // }

    void Printing()
    {

        if (front == NULL)
        {
            cout << "Queue is Empty" << endl << endl;
        }

        else
        {
            node *temp = front;
            cout<< "Front" << " --> ";
            
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
    Queue Q;

    cout<<endl;
    
    Q.Enqueue(3);
    Q.Enqueue(5);
    Q.Printing();


    return 0;
}