#include"act.h"

struct node
{
	entry_message * entries;
	node * next;
};

const int MAX = 5;

class stack
{
	public:
		stack();
		~stack();

		entry_message *  peek();
	
	//	int peek(entry_message & top_message);
	
		int push(entry_message & to_add);
		int pop();
	private:
		node * head;
		int top_index;
		int remove_all(node *& head);
	
};

