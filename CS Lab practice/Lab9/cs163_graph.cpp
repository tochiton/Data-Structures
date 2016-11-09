#include "cs163_graph.h"
using namespace std;

/* Implement these three functions for this lab */
table::table(int size)
{
      //Allocate the adjacency list and set each
      //head pointer to NULL

    list_size = size;
    adjacency_list = new vertex[list_size];

    for(int i =0; i < list_size; ++i)
    {
        adjacency_list[i].entry = NULL;
        adjacency_list[i].head = NULL;
    }

}

//Store the vertex at this location.
int table::insert_vertex(const journal_entry & to_add)
{

        //Place your code here
for(int i =0; i < list_size; ++i)
    {
        if(adjacency_list[i].entry == NULL)
        {
            adjacency_list[i].entry = new journal_entry;
            adjacency_list[i].entry -> copy_entry(to_add);
            return 1;
        }
    }
    return 0;
}

//Attach an edge to a vertex
int table::insert_edge(char * current_vertex, char * to_attach)
{
       //Attach this vertices edge to the specified vertex
    int index_vertex, index_to_attach = -1000;
    
    index_vertex = find_location(current_vertex);
    index_to_attach = find_location(to_attach);

    if(index_vertex <0 || index_to_attach < 0 )
    {
        return 0;
    }
    else
    {
        node * temp =  new node;
        temp -> adjacent = & adjacency_list[index_to_attach];
        temp -> next = adjacency_list[index_to_attach].head;
        adjacency_list[index_to_attach].head = temp;
    }
    return 1;
}

//Display all vertices adjacent to the one specified
int table::display_adjacent(char * key_value)
{
    int temp_index = find_location(key_value);
    if(temp_index < 0)
        return 0;
    if(adjacency_list[temp_index].head == NULL)
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

//Find a location in the graph
//Consider this a helper function foro all of the other member functions!
int table::find_location(char * key_value)
{
      //return the location of this particular key value 
    for(int i =0; i < list_size; ++i)
        {
            if(adjacency_list[i].entry && adjacency_list[i].entry -> compare(key_value))
            {
                return i;
            }
        } 
    return -1000;
}


