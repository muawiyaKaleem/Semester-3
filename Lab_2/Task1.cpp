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

    void Mode()
    {
        int count = 0;
        node *temp = head;

        while(temp != NULL)
        {
            int count1 = 0;
            node *temp1 = head;

            while(temp1 != NULL)
            {
                if (temp->data == temp1->data)
                {
                    count1++; 
                    // if (count >= count1)
                    // {
                    //    count = count1;
                    //    break;
                    // }
                }
                temp1 = temp1->next;
            }
            if(count1 >=count)
            {
                count = count1;
            }
            
            if(count == count1)
            {
                
                int mode = temp->data;

                // if (mode != temp->data)
                // {
                //     cout << "Mode  => " << mode << endl << endl;
                // }
            
            // }
            temp = temp->next;
        }
    }

    float Mean()
    {
        node *temp = head;

        if (length % 2 != 0)
        {
            for(int i = 1; i < (length+1)/2; i++)
            {
                temp = temp->next;
            }

            return temp->data;
        }

        else if (length % 2 == 0)
        {
            for(int i = 1; i < length/2; i++)
            {
                temp = temp->next;
            }

            float mean = (temp->data + temp->next->data)/2;

            return mean;
        }   
    }

    void printing()
    {
        cout << endl << endl;

        cout << "Length of Link List => " << length << endl << endl;
        
        if(length != 0)
        {
            cout << "Head--> ";
        
            node *temp = head;

            while (temp != NULL)
            {
                cout << temp->data << " --> ";
                temp = temp->next; 
            }

            cout << "NULL\n\n";

            cout << "Head = " << head->data << endl << endl;
        }

        else
        {
            cout << "\n\nThere is no Node in the link list\n\n";
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
    
    L.printing();
    
    L.Mode();
    
    float mean = L.Mean();

    cout << "Mean of the given List => " << mean;

    return 0;
}