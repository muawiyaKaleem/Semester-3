#include<iostream>
using namespace std;

class Stack
{

    int *arr,front,rear;
    int id , time;
    string status;

public:
    
    Stack()
    {
        arr = new int;
        front = rear = -1;
    }

    void Enqueue(int value)
    {
        arr[++rear] = value;
    }

    void Dequeue()
    {
            arr[front--];
    }

    void Printing()
    {

                        
            for (int i = front; i <= rear; i++)
            {
                cout << "process id : " << arr[i]. Completed: " << arr[i] << "--->";
            }
            
            cout << "Rear" << endl << endl;

    }
};

int main()
{

    return 0;
}