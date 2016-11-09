#include"act.h"

struct node           	
{
	subject entry;
	node * left;
	node * right;
};

class table
{
	public:
		table(); 		//constructor
		~table();			// destructor
		int add(subject & copy_from);   //  adds a subject to the the tree
		int display_all();		// displays all the courses
		int retrieve(subject found_items[], char range1 [], char range2 []);  // retrieves courses within the range.
		int retrieve_by_num(subject & found, char cour_num []);			// retrieves a course
		int delete_course(char temp_course[]);					// deletes a course from the tree

	private:
		node * root;	
		node * create_leaf(subject & copy_from);				// creates a leaf
		int add_leaf(subject & copy_from, node *& root);			// adds a leaf in the tree
		int display(node * root);

		int find_matches(node * root, subject found_items [], int &count, char range1 [], char range2 []);  // finds the matches in the tree
		int retrieve_num(node * root, subject & found, char cour_num []);
		
		int find_match(node *& root, char temp_course[]);					// finds the match for the delete function
		int delete_node(node *& root);								// deletes a node in the tree

		int delete_all(node *& root);								// deletes all the nodes in the tree
};	

