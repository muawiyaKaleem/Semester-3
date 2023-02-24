#include<iostream>
using namespace std;
    
class node
{
    public:
    int data;
    node* left, *right;
    node(int data)
    {
        this->data=  data;
        left= right= NULL;
    }
};
   
class BinarySearchTree{
    private:
    
    int count;
    node* root;
    node* Insert( node* root, int val);
    node* Parent( node* root );
    
    public:
    
    BinarySearchTree()
    {
        count = 0;
        root= NULL;
    }
    void    Insert(int val){
       
       Insert(this->root,  val);
   }
   void Parent()
    {
        Parent(this->root);
    }
    void print()
    {
        cout<<endl<<"Parent Nodes = " << count;
    }
};

int main ()
{
    BinarySearchTree tree1, tree2;
    tree1.Insert(10);
    tree1.Insert(8);
    tree1.Insert(6);
    tree1.Insert(9);
    tree1.Insert(15);
    tree1.Insert(14);
    tree1.Insert(20);
    tree1.Insert(21);
    tree1.Insert(13);
    tree1.Insert(7);

    tree1.Parent();
    tree1.print();
}

node* BinarySearchTree::Parent( node* r)
{
     if (r == NULL)
        return NULL;
   
    if(r->left != NULL || r->right != NULL)
    {
        cout<<r->data<<"-->";
        count++;
    }
    
    Parent(r->left);
    Parent(r->right);    
}

node* BinarySearchTree::Insert(node* r, int val )
{
 if (r==NULL)
    {
        node* t= new node(val);
        if (r==root)
            root=t;
        else
        r=t;
    }
    else if (r->data== val){
        cout<<"Record already exist"<<val;
    }
    else if (val < r->data) // insert on left s
    r->left = Insert(r->left , val );
    else if (val > r->data)
        r->right= Insert( r->right,val);
    return r;
}