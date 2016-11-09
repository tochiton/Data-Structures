#include "cs163_queue.h"


//Implement these functions using a Circular Linked List
//Add at the rear
int queue::enqueue(const journal_entry & to_add)
{
	//Write the function here
    if (!rear)
    {
        q_node * temp = new q_node;
        temp -> entry.copy_entry(to_add);
        temp -> next = temp;
        rear = temp;
        return 1;
    }
    else 
    { 
        q_node * temp = new q_node;
        temp -> entry.copy_entry(to_add);

        temp = rear -> next;
        rear -> next = temp;
        rear = temp;
        return 1;

    }
}

//Remove the node at the front
int queue::dequeue ()
{

	//Write the function here
    if(!rear)
        return 0;

    if(rear -> next == rear)
    {
        delete rear;
        rear = NULL;
        return 1;
    }
    else
    {
        q_node * temp = rear -> next;
        rear -> next = temp -> next;
        delete temp;
        return 1;
    }
}

