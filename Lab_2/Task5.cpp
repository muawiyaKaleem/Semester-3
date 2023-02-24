#include<iostream>
using namespace std;

class node
{
    public:

    int data;
    node *next, *prev;

    node(int value)
    {
        data = value;
        next = prev = NULL;
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

    void Split(List a)
    {
        if (length % 2 == 0)
        {
            node *temp = a.head; 
            for(int i = 0; i <= (length/2); i++)
            {
                temp = temp->next;
            }

            temp->next->prev = NULL;

            temp->next = NULL;
        }

        else if (length % 2 != 0 )
        {
            int variable = length+1;
            node *temp = a.head; 
            for(int i = 0; i <= (variable/2); i++)
            {
                temp = temp->next;
            }

            temp->next->prev = NULL;

            temp->next = NULL;
        }
    }
};

int main()
{
    List L;
    int value;
    
    for (int i = 0; i < 5; i++)
    {
            value = rand() % 15;
            L.insert(value);
    }
    
    L.Split(L);
}
