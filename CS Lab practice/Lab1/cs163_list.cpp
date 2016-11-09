#include "cs163_list.h"
using namespace std;

//Sum  all of the data together in a LLL
int list::sum_total()
{
 	//FIRST do this iteratively here. Then recursively
        //COMMENT out the iterative version when  rewriting
        //the solution recursively

        //To solve this recursively write another
        //function:   int sum_total(node * head);
        //and call it from this function
/*
    if(!head)
        return 0;
    int sum_total;
    node * current = head;

    while (current)
    {
        sum_total= sum_total + current -> data;
        current = current ->next;
    }
*/
    return sum_total(head);

}

//Now implement the function recursively!
int list::sum_total(node * head)
{
    if(!head)
        return 0;

    return head->data + sum_total(head -> next);


    /*
     int result=0;
    if(!head)
        return result;

     result = sum_total(head -> next);
     result = result + head -> data;
     return result;
     */

}

// *************************************************
//Remove the last node in a LLL. Return false if the
//list is empty and nothing is removed
bool list::remove_last()
{
        //Write your code here
 	//FIRST do this iteratively here. Then recursively
        //COMMENT out the iterative version when  rewriting
    return remove_last(head, tail);
}

//Now implement the function recursively!
bool list::remove_last(node * & head, node * & tail)
{
    if(!head)
        return 0;
    if(head ->next == tail)
    {
        node * temp = tail;
        tail = head;
        delete temp;
        temp = NULL;
        tail -> next = NULL;
        return 1;
    }

    remove_last(head -> next, tail);

}

// ************************************************
//Remove all nodes in a LLL. Remove false if there is
//nothing to remove
bool list::remove_all()
{
        //Remove all nodes in a LLL
 	//FIRST do this iteratively here. Then recursively
        //COMMENT out the iterative version when  rewriting

}

//Now implement the function recursively!
bool list::remove_all(node * & head)
{


}


// ************************************************
//Return true if the requested item (sent in as an argument)
//is in the list, otherwise return false
bool list::find_item(int item_to_find)
{
        //Write your code here
    return find_item(head, item_to_find);
}

//Now implement the function recursively!
bool list::find_item(node * head, int item_to_find)
{

    if(!head)
        return 0;
    if(head ->data == item_to_find)
        return true;

   return find_item(head -> next, item_to_find);

}


// ************************************************
//Make a complete copy of a LLL
bool list::copy(list & from)
{
        //Write your code here

}

//Now implement the function recursively
bool list::copy(node * & dest_head, node * & dest_tail, node * source)
{

    //if(!source)
      //  return 0;
    

}

bool list:: find_last2nd_node(node * head, node * & temp_copy)
{
    if(head -> next == tail)
    {   
        temp_copy = head;
        return 1;
    }
    find_last2nd_node(head -> next, temp_copy);
  
}


bool list::swap_2nd_last()
{
    return swap_2nd_last(head, tail);
}



bool list::swap_2nd_last(node * head, node * & tail)
{
    node * temp_last2nd = NULL; 
    find_last2nd_node(head, temp_last2nd);           // gets the 2nd last node from the list

    node * temp_2ndnode = head -> next;                      // gets the second node from the list
    tail -> next = temp_2ndnode -> next;
    head -> next = tail;

    temp_last2nd -> next = temp_2ndnode;
    temp_2ndnode -> next = NULL;
    tail = temp_2ndnode;

}

