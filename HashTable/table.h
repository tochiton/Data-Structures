#include"act.h"

struct node           	
{
	subject entry;
	node * next;
	bool flag;
};

class table
{
	public:
		table(int size = 5); 		//constructor
		~table();			// destructor
		int add(subject & copy_from);   //  adds a subject to the the table
		int insert(char * key_value, subject & copy_from, bool set_flag);   // inserts into the table
		int retrieve( char * subject_to_find, subject *& found);		// retrieves from the table		
		int display();
		int display_all();							// display all the subjects in the table

	private:
		node ** hash_table;
		int hash_table_size;
		int hash_function(char * title) const;				// retruns an index based on the keyword
		void delete_nodes(node *& temp);				// deletes the nodes in the table	
		int display_lll(node * temp);					// displays all the nodes in the table
};	

