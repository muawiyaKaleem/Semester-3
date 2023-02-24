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

// All Posible Insertions

    void insert_At_Last(int value)
    {
        node *t = new node(value);

        if(head == NULL)
        {
            head = t;
            t-
            length++;
        }

        else
        {
            node *temp = head;
            
            while (temp->next != head)
            {
                temp = temp->next;

            }

            temp->next = t;
            length++;
        }
    }

    void insert_After_A_Value(int key , int value)
    {
        if(head == NULL)
        {
            cout << "\n\nThere is no Node exists with Value " << key <<" in the list after which you want to Insert the value\n\n";
            return;
        }
        
        else
        {
            node *t = new node(value);
            node *temp = head;

            while (temp->data != key)
            {
                if (temp->next == NULL)
                {
                    cout << "\n\nThere is no Node exists with Value " << key <<" in the list after which you want to Insert the value\n\n";  
                    break;
                }
                
                temp = temp->next;
            }
            
            if (temp->data == key)
            {
                t->next = temp->next;
                temp->next = t;
                length++;
            }
            
            
        }
        
    }

    void insert_At_Head(int value)
    {
        node *t = new node(value);
        node *temp = head;
        head = t;
        t->next = temp;
        length++;
    }

//Searching

    void Search(int value)
    {
        if(head == NULL)
        {
            cout << "\n\nThere is no Node in the link list\n\n";
        }

        else
        {
            node *temp = head;

            while (temp->data != value)
            {
        
                if(temp->next == NULL)
                {
                    cout << "\n\nThere is no Node with Value " << value << endl << endl;
                    break;
                }

                temp = temp->next;

            }

            if (temp->data == value)
            {
                cout << "\n\nThere is a Node exists with Value " << value << endl << endl;    
            }
        }
    }

    void Delete_From_Last()
    {
        if (head == NULL)
        {
            cout << "\n\nThere is no Node in the link list\n\n";
        }

        else
        {
            node *temp = head;

            while (temp->next->next != NULL)
            {

                temp = temp->next;
            }

            
            delete temp->next;
            temp->next = NULL;
            length--;
        }
        
    }

    void Delete_A_Value(int value)
    {
        if (head == NULL)
        {
            cout <<"\n\nThere is no Node in the link list\n\n";
        }

        else
        {
            node *temp = head;

            while (temp->next->data != value)
            {
                temp = temp->next;
            }

            node *temp1 = temp->next;

            temp->next = temp1->next;
            delete temp1;
            length--;
        }
        
    }

    void Delete_Head()
    {
        if (head == NULL)
        {
            cout << "\n\nThere is no Node in the link list\n\n";
        }

        else
        {
            node *temp = head;

            head = head->next;
            delete temp;
            length--;
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
    List o;
    int choice , value , key;
    char c;

    do
    {
        cout << "\n\nOperations on Single Link List :-\n\n";

        cout << "Press 1 => Insert Node at the head\n";
        cout << "Press 2 => Insert Node at the last\n";
        cout << "Press 3 => Insert Node after a value\n";
        cout << "Press 4 => Search a Node\n";
        cout << "Press 5 => Delete the head\n";
        cout << "Press 6 => Delete the last Node\n";
        cout << "Press 7 => Delete Node after a value\n";
        cout << "Press 8 => Print the List\n\n";
        
        cout << "Enter Your Choice => ";
        cin >> choice;

        cout<< endl;

        if (choice == 1)
        {
            cout << "Enter the value of the Node to Insert => ";
            cin >> value;
            o.insert_At_Head(value);
        }

        else if (choice == 2)
        {
            cout << "Enter the value of the Node to Insert => ";
            cin >> value;
            o.insert_At_Last(value);
        }

        else if (choice == 3)
        {
            cout << "Enter the value of the Node to Insert => ";
            cin >> value;
            cout << "Enter the value of the Node after which you want to Insert => ";
            cin >> key;
            o.insert_After_A_Value(key , value);
        }

        else if (choice == 4)
        {
            cout << "Enter the value of the Node to Search => ";
            cin >> value;
            o.Search(value);
        }

        else if (choice == 5)
        {
            o.Delete_Head();
        }

        else if (choice == 6)
        {
            o.Delete_From_Last();
        }

        else if (choice == 7)
        {
            cout << "Enter the value of the Node to Delete => ";
            cin >> value;
            o.Delete_A_Value(value);
        }
        
        else if (choice == 8)
        {
            o.printing();
        }

        cout << endl;
        cout << "Press y/Y => Repeat the Procedure\n";
        cout << "Press Any Key to exit\n\n";
        cout<< "Enter Your Choice => ";
        cin >> c;

    } while (c == 'y' || c == 'Y');
    
    
    
    return 0;
}