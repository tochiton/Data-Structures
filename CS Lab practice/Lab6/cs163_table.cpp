#include "cs163_table.h"
using namespace std;

/* Implement these three functions for this lab */
table::table(int size)
{
      //Allocate the hash table and initialize each
      //element and data member.
    hash_table_size = size;
    hash_table = new node * [size];

    for(int i = 0; i < size; ++i)
    {
        hash_table[i] = NULL;
    }
}

//Using a hash function, insert a new value into the 
//head of the chain
int table::insert(char * key_value, const journal_entry & to_add)
{
    node * temp;
    int index = hash_function(key_value);

    temp = new node;
    temp -> entry.copy_entry(to_add);

    temp -> next = hash_table[index];

    hash_table[index] = temp;

}

//Using a hash function determine which chain to search
//then return 0 if no match is found
int table::retrieve(char * title_to_find, journal_entry & found) const
{

    int index = hash_function(title_to_find);
    
    if(!hash_table[index])
        return 0;

    node * temp = hash_table[index];
    
    while(temp && !temp ->entry.retrieve(title_to_find,found))
    {  
        temp = temp -> next;
    }
    if(!temp)
        return 0;
    else
        return 1;

}

int table::hash_function(char * title) const
{
    if(!title)
        return 0;
    int sum =0;
    for(int i =0; i < strlen(title); ++i)
    {
        sum = sum + title[i];
    }
    return sum % hash_table_size;
}
