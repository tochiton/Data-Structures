#include "cs163_tree.h"
using namespace std;



//These are the functions that you will be writing for the BST


void table::display_largest()
{
    display_largest(root);
}      	//STEP 1
void table::display_largest(node * root) 
{
    if(!root)
        return;
    if(!root -> right -> left && !root -> right -> right)
    {
        cout<<"Biggest: "<< root -> right -> data<<endl;
        cout<<"Biggest: "<< root -> data<<endl;
    }
    if(!root -> right)
        cout<<"Biggest: "<< root -> data <<endl;
        display_largest(root -> left);
    display_largest(root -> right);
}

int table::count_root() {}		//STEP 2
int table::count_root(node * root, int match) {}

int table::find_successor(node * root)
{
    if(!root)
        return 0;
    if(!root -> left)
        return root -> data;
   
    find_successor(root -> left);
}

void table::copy_bst(node * root, node *& root2)
{
    if(!root)
    {   
        root2 = NULL;
        return;
    }
    root2 = new node;
    root2 -> data = root -> data;
    copy_bst(root -> left, root2 -> left);
    copy_bst(root -> right, root2 -> right);
}

void table::copy(table & source) {}  	//STEP 3
void table::copy(node * & destination, node * source) {}



//Now for the 2-3-4 Tree		//STEP 4
int table::count_3_data()   //sample wrapper function that return the count
{
      return count_3_data(root234);
}	     
     
int table::count_3_data(node234 * root){}	                    


//STEP 5
int table::height(){}                    //Return the height
int table::height(node234 * root){}                    

//STEP 6
//Copy from the argument into the data members...
int table::copy_234(table & copy_from) {}
int table::copy(node234 * & destination, node234 * source){}      
