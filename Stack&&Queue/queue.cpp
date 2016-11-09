#include"queue.h"

// add an object of type entry_message into the queue
	
int queue:: enqueue(entry_message & to_add)
{
	if(!rear)
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
		
		q_node * temp2 = rear -> next;
		rear -> next = temp;
		temp -> next = temp2;
		rear = temp;
		return 1;
	}	

}

// delete the oldest item in the queue

int queue:: dequeue()
{
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
		temp = NULL;
         	return 1;
	}

}


// destructor

queue::~queue()
{
	q_node * head = rear->next;
	rear->next = NULL;
	remove_entries(head);		
}

int  queue::remove_entries(q_node *& rear)
{
	if(!rear)
		return 0;
	
	q_node * temp = rear -> next;
	delete rear;
	rear = NULL;

	rear = temp;
	
	remove_entries(rear);
}
		
queue::queue()
{
	rear = NULL;
}
