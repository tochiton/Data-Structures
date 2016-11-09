#include"table.h"

using namespace std;

// sets all the values in table to NULL
table::table(int size) 				
{
	list_size = size;
	adjacency_list = new vertex[list_size];
	
	for(int i = 0; i < list_size; ++i)
	{
		adjacency_list[i].entry = NULL;
		adjacency_list[i].head = NULL;
	}
}

// deletes the  whole table
table::~table()					
{
	for(int i = 0; i < list_size; ++i)
	{
		delete_list(adjacency_list[i].head);
	} 

	delete [] adjacency_list;
}

// deletes the list in the array
int table::delete_list(node * head)
{
	if(!head)
		return 0;
	delete_list(head -> next);
	delete head;
	head = NULL;
}

// insert a vertex
int table::insert_vertex(city & to_add)
{
	for(int i = 0; i < list_size; ++i)
	{
		if(adjacency_list[i].entry == NULL)	
		{
			adjacency_list[i].entry = new city;
			adjacency_list[i].entry -> copy_city(to_add);

			return 1;
		}
	}
	return 0;
}
// find the location in the array
int table::find_location(char * key_value)
{
	for(int i =0; i < list_size; ++i)
	{
		if(adjacency_list[i].entry && adjacency_list[i].entry -> compare(key_value))
		{
			return i;
		}
	}	
	return -1000;
}
// insert an edge between cities
int table::insert_edge(char * current_vertex, char * to_attach)
{
	int index_vertex, index_to_attach = -1000;
	
	index_vertex = find_location(current_vertex);
	index_to_attach = find_location(to_attach);
	
	if(index_vertex < 0 || index_to_attach <0)
	{
		return 0;
	}
	else
	{
		node * temp = new node;
		temp -> adjacent = & adjacency_list[index_to_attach];
		temp -> next = adjacency_list[index_vertex].head;
		adjacency_list[index_vertex].head = temp;
	}
}

// checks for a complete graph
int table::check_complete()
{
	int mark[list_size];
	for(int i = 0; i < list_size; ++i)
	{
		for(int j = 0; j < list_size; ++j)
		{
			mark[j] = 0;
		}
		mark[i] = 1;
		check_adj(adjacency_list[i].head, mark);	
		
		for(int j = 0; j < list_size; ++j)
		{
			if(mark[j] == 0)
			return 0;
		}
	}
	return 1;
}

// checks for a complete graphs
int table::check_adj(node * head, int mark [])
{
	if(head)
	{
		check_vertex(head -> adjacent, mark);
		check_adj(head -> next, mark);
	}
}

// fills one in the array to check
// if it is a complete graph
int table::check_vertex(vertex * adjacent, int mark [])
{	
	for(int i = 0; i < list_size; ++i)
	{
		if(adjacent == & adjacency_list[i])
		{
			mark[i] = 1;
			return 1;
		}
	}

}

// display the list
int table::display_adjacent(char * key_value)
{
	int temp_index = find_location(key_value);
	
	if(temp_index < 0)
		return 0;
	if(!adjacency_list[temp_index].head)
		return 0;
	else
	{
		node * current = adjacency_list[temp_index].head;
		
		while(current)
		{
			current -> adjacent -> entry -> display();
			current = current -> next;
		}
		
	}
}
