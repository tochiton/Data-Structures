#include "cs163_2-3.h"
using namespace std;

//These are the functions that you will be writing for Lab #8

// **** STEP 1
//First write the wrapper functions:
//Display all nodes with no children in 2-3 tree
int table::display_23()      
{
    //call the recursive function here
    return display_23(root23);
}

//Now implement the recursive function to display all leaves
int table::display_23(node23 * root)
{
    if(!root)
        return 0;
    if(!root -> child[0] && !root -> child[1] && !root -> child[2])
    {
        if(root -> data[0] != 0)
            cout<< root -> data[0]<<endl;
        if(root -> data[1] != 0)
            cout<< root -> data[1]<<endl;
    }

    display_23(root -> child[0]);
    display_23(root -> child[1]);
    display_23(root -> child[2]);

}     



// **** STEP 2
// Implement the recursive function to deallocate all items.
// The destructor already calls this function
int table::deallocate_23(node23 * & root)
{
    if(!root)
        return 0;
    deallocate_23(root -> child[0]);
    deallocate_23(root -> child[1]);
    deallocate_23(root -> child[2]);
    delete root;
    root = NULL;
} 



// **** STEP 3
//First write the wrapper functions:
//Return true if the root's largest value appears more than once

int table::return_largest(root23)
{
    if(!root23)
        return 0;
    if(root23 -> data[1])
        return root23 -> data[1];
    else
        return root23 -> data[0];
}

bool table::find_largest()   
{

    return find_largest(root23 -> child[0], return_largest(root23)) || find_largest(root23 -> child[1], return_largest(root23)) || find_largest(root23 -> child[2], return_largest(root23));
            

}

//Return true if the root's largest value appears more than once
//Write this function recursively
bool table::find_largest(node23 * root, int match)
{
    if(!root)
        return 0;
    if(root -> data[0] == match || root -> data[1] == match)
        return true;
    find_largest(root -> child[0]);
    find_largest(root -> child[1]);
    find_largest(root -> child[2]);
}


// **** STEP 4
//First write the wrapper functions:
//Copies the argument's tree into the current object's tree
int table::copy(const table & source) 
{
   
    //call the recursive function here
}


//Now implement the recursive function to copy the tree
int table::copy(node23 * & dest_root, node23 * source_root){}      
