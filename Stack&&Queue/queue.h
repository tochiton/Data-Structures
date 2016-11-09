#include"stack.h"

struct q_node
{
	entry_message entry;
	q_node * next;
};

class queue
{
	public:
		queue();
		~queue();
	
		int enqueue(entry_message & to_add);
		int dequeue();
	//	int remove_all();
		 	
	
	private:
		q_node * rear;
		int remove_entries(q_node *& rear);
		
};
