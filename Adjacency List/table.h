#include"act.h"

struct vertex
{
	city * entry;
	struct node * head;
};

struct node           	
{
	vertex * adjacent;           						// destination
	node * next;
	int distance;
};

class table
{
	public:
		table(int size = 5); 						//constructor
		~table();							// destructor
		
		int insert_vertex(city & to_add);                      		// inserts a vertex
		int find_location(char * key_value);                            // find location
		int insert_edge(char * current_vertex, char * to_attach);	// creates an edge
		int display_adjacent(char * key_value);				// display the adjacent
		
		int check_complete();						// checks for a complete graph
		int check_adj(node * head, int mark []);			// fills in the array to check for completion	
		int check_vertex(vertex * adjacent, int mark []);

		int delete_list(node * head);					// deletes the array and the list
			
	private:
		vertex * adjacency_list;
		int list_size;	
							
};	

