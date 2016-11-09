#include"list.h"

int destroy_except_last(node *& head)
{
    if(!head -> next)
        return 0;
   
    node * temp = head -> next;
    delete head;
    head = NULL;
    
    head = temp;

    return destroy_except_last(head);
    
}

int clone(node * head, node *& source)
{
    if(!head)
        return 0;
    
    source = new node;
    source -> next = NULL;
    source -> data = head -> data;
    clone(head -> next, source -> next);
  
    
    return 1;
}


int copy(node * head, node *& source)
{
    if(!head)
        return 0;

    node * current = head;
    node * previous = NULL;
      

    while(current)
    {
        if(!source)
        {
            source = new node;
            source -> data = head -> data;
            source -> next = NULL;
            previous = source;
        }
        else
        {
            node * temp = new node;
            temp -> data = current -> data;
            
            previous -> next = temp;
            temp -> next = NULL;
            previous = temp;
        }
        current = current -> next;
    }
    return 1;
}


int display_reverse(node * head)
{
    if(!head)
        return 0;
    display_reverse(head -> next);

    cout<< head->data;

    return 1;
}
/*
int remove_biggest(node * head)
{   
    int biggest = 0;

    find_biggest(head, biggest);
    
    remove_biggest(head, biggest);

}

node * remove_biggest(node * head, int biggest)
{
    if(!head)
        return 0;

    node * temp = head -> next;
    if(head ->data == biggest)
    {
        delete head;
        head = temp;
    }
    
    if(head) head->next = remove_biggest(temp);
    return head;
}
int  find_biggest(node * head, int & biggest)
{

  if(!head)
       return 0;

   if( head -> data >= biggest)
   {
        biggest = head -> data;
   }
   find_biggest(head -> next, biggest);
   return biggest;

}

*/

int count_node(node * head)
{
    int count = 0;

    if(!head)
        return 0;

    ++count;
    return count + count_node(head -> next);
}  
 
int find_smallest(node * head)
{
    
    if(!head)
        return 1000;
    int temp = find_smallest(head -> next);

    if (temp <= head -> data)
        return temp;
    else return head -> data;
}


node * reverse(node * head)
{
    if(!head)
        return NULL;

}

bool compare_length(node * head, node * source)
{
    if(!head || !source)
        return false;
    if(!head -> next && !source -> next)
        return true;

     (head -> next, source -> next); 
}

int count_of_two(node*head)
{
 if(!head)
     return 0;
 if(head -> data ==2)
     return 1 + count_of_two(head -> next);
 else
     return count_of_two(head -> next);
}

/*
 * int copy_to_array(node * head, int *& table, int & count )
{  
    int count = 0
    if(!head)
    {
        return count;
        table = new int [count];
    }
    ++ count
    copy_to_array(head -> next, table)
    

}
*/

int copy_into_array(node * head, int count, int temp[])
{
    if(!head)
        return 0;
    copy_into_array(head -> next, --count, temp);

    temp[count] = head -> data;
    return 1;
}












