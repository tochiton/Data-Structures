#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>


//The data structure is a linear linked list of integers
//with a head AND tail pointer!
struct node
{
       int  data;
       node * next;
};

class list
{
      public:
             //These functions are supplied for you
             list();
             ~list();
             void build();
             void display_all();
            
             //****************************************************
             //Write each of these functions Iteratively and Recursively
             int sum_total();		  //Step #4 Iterative
             int sum_total(node * head);  //Step #5 Recursive

	     bool remove_last();          //Step #6 Iterative
             bool remove_last(node * & head, node * & tail);  //Step #7 Recursive

             bool remove_all();                 //Step #8 Iterative
             bool remove_all(node * & head);    //Step #8 Recursive

             bool find_item(int item_to_find);  //Step #9 Iterative
             bool find_item(node * head, int item_to_find);   //Step #9 Recursive

             bool copy(list & from);            //Step #10 Iterative
             bool copy(node * & dest_head, node * & dest_tail, node * source); //Step #11 Recursive

             bool find_last2nd_node(node * head, node * & temp_copy);

             bool swap_2nd_last();
             bool swap_2nd_last(node * head, node * & tail);
                  
      private:
             //Notice there is BOTH a head and tail pointer
             //Make sure to keep both properly maintained
              node * head;
	      node * tail;
};
             
