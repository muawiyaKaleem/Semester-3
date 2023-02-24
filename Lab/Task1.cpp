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
    node *front , *rear;
    int count;
    
    public:
        Queue()
        {
            count = 0;
            front = rear = NULL;
        }

    bool Empty()
    {
        if (rear == NULL)
        {
            return true;
        }
        return false;
    }

    void Enqueue(int value)
    {  
        Queue x;
        node *t = new node(value);

        if(rear == NULL)
        {
            rear = t;
            rear->next = NULL;
            front = rear;
        }

        else
        {
            rear = front = t;
            rear->next = NULL;
        }

           while (front->data != value)
            {
                //Dequeue();
                
                x.Enqueue(this->Dequeue());
                front = front->next;
            }   
        
            while (x.front != NULL)
            {
               // x.Dequeue();

                this->Enqueue(x.Dequeue());
                front = front->next;
            }
    }

    int Dequeue()
    {
        int d;
        
        if(front == NULL)
        {
            cout << "\n\nQueue is Empty" << endl << endl;
        }

        else
        {
            node *temp = front;

            front = temp->next;
            d = temp->data;
            delete temp;

            if (front == NULL)
            {
                rear = front;
            }
        }

        return d;
    }

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
    Queue Q1;

    Q1.Enqueue(1);
    Q1.Enqueue(2);
    Q1.Enqueue(3);
    Q1.Enqueue(4);

    Q1.Printing();

    return 0;
}