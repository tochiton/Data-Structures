#include"table.h"

using namespace std;

table::table(int size) 				// sets all the values in table to NULL
{
	hash_table_size = size;
	hash_table = new node * [size];
	
	for(int i = 0 ; i < size; ++i)
	{
		hash_table[i] = NULL;
	}
}

table::~table()					// deletes my whole table
{
	for(int i = 0; i < hash_table_size; ++i)
	{
		if(hash_table[i])
		{ 
			delete_nodes(hash_table[i]);    // calls the private function to delete recursively
			hash_table[i] = NULL;
		}
	}
	
	delete [] hash_table;
	hash_table = NULL;
}

void  table::delete_nodes(node *& temp)			// deletes the nodes recursively
{
	if(!temp)
	{
		return;
	}
	
	delete_nodes(temp -> next);
	delete temp;
	temp = NULL;
	return;

}


int table::hash_function(char * title) const 		// returns an index for my table based on a keyword
{
	if(!title)
		return 0;
	
	int sum = 0;

	for(int i = 0; i < strlen(title); ++i)
	{	
		sum = sum + title [i];
	}

	return sum % hash_table_size;	
}
int table:: add(subject & copy_from)
{
	char * temp_name;	

	copy_from.get_course_name(temp_name);		// gets the course name from my object
					
	insert(temp_name, copy_from, true);		// calls the insert function and get the index based on course name
	
	char * temp_num;
	
	copy_from.get_course_number(temp_num);

	insert(temp_num, copy_from, false);		// calls the insert function and get the index based on course number

	if(temp_name)	
		delete [] temp_name;

	if(temp_num)
		delete [] temp_num;

	temp_name = temp_num = NULL;
}




int table::insert(char * key_value, subject & copy_from, bool set_flag)			// builds the list based on the index
{
	node * temp;
	int index = hash_function(key_value);	

	temp = new node;
	temp -> flag = set_flag; 							// sets a flag to avoid displaying twice 
	temp -> entry.copy_subject(copy_from);						// since the program inserts in the same table

	temp -> next = hash_table[index];						// points to whatever hash_table is pointing before inserting 
	hash_table[index] = temp;
}

int table::display_all()								// display all recursively
{
	for(int i = 0; i < hash_table_size; ++i)
	{
		node * temp = hash_table[i];
		if(temp)
			display_lll(temp);		
	}
	
	return 1;

}
int table::display_lll(node * temp)
{
	if(!temp)
		return 0;
	if(temp -> flag)
	{
		temp -> entry.display();
	}
	display_lll(temp -> next);
	return 1;
}

int table::retrieve( char * subject_to_find, subject *& found)				// the beauty of life
{											// returns an array of subjects with all the matches
	int index = hash_function(subject_to_find);
	if(!hash_table[index])	
		return 0;
	node * temp = hash_table[index];
	
	int count = 0;
	
	while(temp)
	{
		if(temp -> entry.check_item(subject_to_find))
			++count;

		temp = temp -> next;
	}	
	if(count == 0)
		return 0;

	found = new subject[count];

	temp = hash_table[index];
	int found_index = 0;

	while(temp)
	{
		
		if(temp ->entry.retrieve(subject_to_find, found[found_index]))
			++found_index;
		temp = temp ->next;
	}
	return count;
}

