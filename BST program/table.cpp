#include"table.h"

using namespace std;

table::table() 				// sets all the values in table to NULL
{
	root = NULL;
}

table::~table()					// deletes my whole table
{
	delete_all(root);			// calls the private funtion to delete the entire tree
}


int table:: add(subject & copy_from)
{
	add_leaf(copy_from, root);			// class the private function add_leaf to insert
}

int table::add_leaf(subject & copy_from, node *& root)		// inserts a leaf in the tree
{
	if(!root)
	{
		root = create_leaf(copy_from);			// once the right place is found, it creates a leaf
	}	
	else if(root -> entry.compare(copy_from) <= 0)          // goes through the tree finding the right place
	{
		add_leaf(copy_from, root -> right);
	}
	else if(root -> entry.compare(copy_from) > 0)
	{
		add_leaf(copy_from, root -> left);
	}
}
//////////
// The function takes an object type subject
// as a parameter. Creates a new node and copies
// the information into the new node.
// Returns a pointer where the new object
// was created
//////////

node * table::create_leaf(subject & copy_from)
{
	node * leaf = new node;
	leaf -> entry.copy_subject(copy_from);
	
	leaf -> left = NULL;
	leaf -> right = NULL;
		
	return leaf;
}

int table::display_all()
{
	display(root);	
}
////////
// displays every single node
// in the tree
///////
int table::display(node * root)
{
	if(!root)
		return 0;
	
		if(root -> left)
		{
			display(root -> left);
		}
		
		root ->entry.display();
	
		if(root -> right)
		{
			display(root -> right);
		}

}

///////
// calls the private function find_matches and
// passes an arry of subjects where all the
// matches will be copied
//////	
int table::retrieve(subject found_items [], char range1 [], char range2 [])
{
	int count = 0;
	return find_matches( root,found_items, count, range1, range2);
}

/////////
// if the subject in the tree is within the range,
// makes a copy in the array passed from main
// and increments the count which would be 
// return to main to know how many items to display
// in the array.
////////

int table::find_matches(node * root, subject found_items [], int &count, char range1 [], char range2 [])
{
	if(!root)
		return 0;
	if(root -> entry.compare_range(range1) >= 0 && root -> entry.compare_range(range2) <= 0)
	{	
		found_items[count].copy_subject(root -> entry);				
		++count;

		find_matches(root -> left, found_items, count, range1, range2);
		find_matches(root -> right, found_items, count, range1, range2);
	}	

	else if(root -> entry.compare_range(range1) < 0)
	{
		find_matches(root -> right, found_items, count, range1, range2);
	}
	else
	{
		find_matches(root -> left, found_items, count, range1, range2);
	}
	return count;
}

int table::retrieve_by_num(subject & found, char cour_num [])
{
	retrieve_num(root, found, cour_num);	
}

///////////
// compares each single item in the tree to search
// for a match. If the course is in the tree, a copy
// will be return to main in the object found
///////////
int table::retrieve_num(node * root, subject & found, char cour_num [])
{
	if(!root)
		return 0;
	if(root -> entry.compare_range(cour_num) == 0)
	{	
		root -> entry.retrieve(found);
		return 1;	
	}
	else if(root -> entry.compare_range(cour_num) <= 0)
	{
		retrieve_num(root -> right, found, cour_num);
	}
	else if(root -> entry.compare_range(cour_num) > 0)
	{
		retrieve_num(root -> left, found, cour_num);
	}
}
	
int table::delete_course(char temp_course[])
{
	find_match(root, temp_course);	
}

/////////
// takes two parameters. The root of the tree and
// the course the user wants to delete.
// once the course is found, the delete funtion will
// take care of the deletion process
////////
int table::find_match(node *& root, char temp_course[])
{
	if(!root)
		return 0;
	if(root -> entry.compare_range(temp_course) == 0)
	{
		return delete_node(root) + find_match(root, temp_course);	// deletes the match and call itself again to see if 
	}									// there is a duplicate file
	find_match(root -> left, temp_course);       
	find_match(root -> right, temp_course);	      
}
/////////
// deletes a node depending on the cases
// case 1: no child
// case 2 one child in either side
// case 3: a parent node
/////////
int table::delete_node(node *& root)
{	
	node * temp = NULL;

	if(!root)
		return 0;

	if(!root -> left && !root -> right)	
	{
		delete root;
		root = NULL;
		return 1;
	}
	else if(!root -> left && root -> right)
	{
		temp = root -> right;
		delete root;

		root = NULL;
		root = temp;
	}
	else if(root -> left && !root -> right)
	{
		temp = root -> left;
		delete root;
		root = NULL;
		root = temp;
	}
	else
	{
		node * current = root -> right;					// finds in order successor to be moved where the deletion
										// is going to be
		if(!current -> left)						// first case, there is nothing to my left so we need to move
		{								// the one to the right
			root -> entry.copy_subject(current -> entry);
			root -> right = current -> right;
			delete current;
			current = NULL;
		}
		else 
		{
			node * previous = current;
			while(current -> left)
			{
				previous = current;
				current = current -> left;	
			}
		
			root -> entry.copy_subject(current -> entry);
			previous -> left = current -> right;
			delete current;
			current = NULL;	
					
		}	
	}
}

///////
// deletes everything recursively
///////
int table::delete_all(node *& root)
{
	if(!root)
		return 0;
	delete_all(root -> left);
	delete_all(root -> right);
	
	delete root;
	root = NULL;
	return 1;
}
