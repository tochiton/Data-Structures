#include"stack.h"


stack::stack()
{
	head = NULL;
	top_index = 0;
}

stack::~stack()
{
	remove_all(head);	
}

int stack::remove_all(node *& head)
{
	if(!head)
		return 0;
	
	node * temp = head -> next;
	if(head)
	{	
		if(head -> entries)	
			delete [] head -> entries;
		delete head;
		head = NULL;
	}
	head = temp;
	
	remove_all(head);
}

// pushes the content into the stack
int stack::push(entry_message & to_add)
{
	if(!head)	
	{
		head = new node;
		head -> entries = new entry_message[MAX];
		head -> next = NULL;
		head -> entries[top_index].copy_entry(to_add);
		++top_index;
		return 1;
	}
	if(top_index == MAX)
	{
		node * temp = new node;
		temp -> next = head;
		head = temp;
		top_index = 0;
		head -> entries = new entry_message[MAX];
		head -> entries[top_index].copy_entry(to_add);
		++top_index;
		return 1;

	}
	else
	{
		head -> entries[top_index].copy_entry(to_add);
		++top_index;
		return 1;

	}
}

entry_message * stack:: peek()
{
	if(!head)
		return NULL;
	if(top_index == 0)
	{
		node * temp = head -> next;
		if (temp)
			return & temp->entries[top_index];
		else
			return NULL;
		
	}
	else
	{	
		return & head -> entries[top_index - 1];
	}
}
int stack:: pop()
{
	if(!head)
		return 0;
	if(top_index == 0)
	{
		node * temp = head -> next;
		delete [] head -> entries;
		delete head;
		head = temp;
		top_index = MAX - 1;
		return 1;
	}	
	else
	{
		top_index = top_index - 1;
		return 1;
	}
	
}
