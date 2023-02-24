// Binary Search Tree Implementation..  
#include<iostream>
using namespace std;
    class node {
    public:
    int data;
    node* left, *right;
    node(int data){
        this->data=  data;
        left= right= NULL;
        }
    };
   
class Tree{
    private:

    node* root;
    node* Insert( node* root, int val);
    node* InOrderTraversal( node* root , Tree tree2);
    node* print(node* root);

    public:
    
    Tree()
    {
        root= NULL;
    }
    
    void    Insert(int val)
    {
       
       Insert(this->root,  val);
    }

    void InOrderTraversal(Tree tree2)
    {
       
        InOrderTraversal(this->root , tree2);
    }

    void print()
    {
        print(this->root);
    }
};


int main()
{
    Tree tree1 , tree2;
    
    tree1.Insert(10);
    tree1.Insert(8);
    tree1.Insert(14);
    tree1.Insert(9);
    
    
    tree2.Insert(15);
    tree2.Insert(7);
    tree2.Insert(20);
    tree2.Insert(21);

    tree1.InOrderTraversal(tree2);
    tree2.print();
}

node *Tree::InOrderTraversal( node* r , Tree tree2)
    
    {

     if (r == NULL)
     {
        return NULL;
     }

    this->InOrderTraversal(r->left , tree2);
    
    tree2.Insert(tree2.root , r->data);
    
    this->InOrderTraversal(r->right , tree2);

    }

    node *Tree::print(node* r)
    {
     if (r == NULL)
        return NULL;
    //first recur on left child
    print(r->left);
   //then print the data of node
    cout << " "<< r->data << " -> ";
  // now recur on right child
    print(r->right);
}


node* Tree::Insert(node* r, int val )
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