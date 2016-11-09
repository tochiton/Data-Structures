#include "cs163_entry.h"

//The data structure is a CLL of journal entries
struct q_node
{
       journal_entry entry; 
       q_node * next;
};


class queue
{
      public:
             //These functions have ALREADY been written for you
             queue(void);     
             ~queue(void);     
             int display_all(void) const; 
            

             //**************************************
             //Implement these functions
             int enqueue(const journal_entry & to_add); //Implement this
 	     int dequeue (); //Implement this     
             void remove_all();
             int count();
  
      private:
              q_node * rear;
              void removal_entire(q_node *& rear);
};
             
