#include"dlist.h"

int find_smallest(node * head)
{
    if(!head)
        return 1000;
    int temp = find_smallest(head -> next);

    if(temp <= head -> data)
        return temp;
    else
        return head -> data;
}

int remove_smallest(node *& head, int temp)
{
    if(!head)
    {
        return 0;
    }

/*    if(!head->next && head->data == temp)
    {
        delete head;
        head = NULL;
        return 0;
    }

*/    
    if(head->data == temp)
    {
        node * last = head -> previous;
        node * first = head -> next;
        head->next = head->previous = NULL;
        delete head;
        if(last)
            last->next = first;
        if(first)
            first->previous = last;
        head = first;
        return remove_smallest(head,temp);
/*
        if(last)
            last -> next = first;
        else
            first->previous = NULL;
        
        if(first)
        {
            first -> previous = last;
            head = first;
            return remove_smallest(head, temp);
        }
        else
            last->next = NULL;
*/
    }

    return remove_smallest(head->next, temp);

}

int wrap_delete_small(node *& head, int temp)
{
    if(!head)
    {
        return 0;
    }

    return remove_smallest(head, temp);
}

int insert_before(node *& head, int num_temp)
{
    if(!head)
        return 0;
    if(head -> data == num_temp)
    {
        node * temp = new node;
        temp -> data = 0;

        temp -> previous = head -> previous;

        if(!temp -> previous)
        {
            temp -> next = head;
            head -> previous = temp;
            head = temp;
            return insert_before(head -> next -> next, num_temp);
        }
        else
        {
            temp -> next = head;
            head -> previous -> next = temp;
            head -> previous = temp;
        }

    }
    return insert_before(head -> next, num_temp);
}

int wrap_insert(node *& head, int number)
{
    if(!head)
        return 0;

    return insert_before(head, number);
}

int delete_after(node *& head)
{
    if(!head)
        return 0;

    if(head -> data == 2 && head -> next)
    {
        node * temp =  head -> next;
        head -> next = temp -> next;
        if(temp -> next)
        {
            temp -> next -> previous = temp -> previous;
        }
        delete temp;
        temp = NULL;
        return delete_after(head -> next);
    }
    else 
        return delete_after(head -> next);

}

int count_node(node * head)
{
    if(!head)
        return 0;

    return 1 + count_node(head -> next);
}

int sum_data(node * head)
{
    if(!head)
        return 0;
    
    return head -> data + sum_data(head -> next);
}

float calculate_average(node * head)
{
    return sum_data(head)/count_node(head);
}
