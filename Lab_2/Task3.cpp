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

class List
{
    private:

    int length;
    node *head;

    
    public:

    List()
    {
        head = NULL;
        length = 0;
    }

    void insert(int value)
    {
        node *t = new node(value);

        if(head == NULL)
        {
            head = t;
            length++;
        }

        else
        {
            node *temp = head;
            
            while (temp->next != NULL)
            {
                temp = temp->next;

            }

            temp->next = t;
            length++;
        }
    }

    bool Palindrome(List a)
    {
        node *temp = a.head;

        while ()
        {
            /* code */
        }
        
    }
};

int main()
{
    List L;
    int value;
    
    for (int i = 0; i < 15; i++)
    {
            value = rand() % 15;
            L.insert(value);
    }

    return 0;
}