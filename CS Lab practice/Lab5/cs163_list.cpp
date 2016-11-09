#include "cs163_list.h"

using namespace std;

/* These are the functions you will be implementing */
/* USE RECURSION! */
int insert_after(node * & head)
{
    int count =0;
    if(!head)
        return 0;
    if(head -> data == 2)
    {   
        ++count;
        node * temp = new node;
        temp -> data =0;

        if(head -> next)
        {
            temp -> next = head -> next;
            temp -> next -> previous = temp;
        }
        
        head -> next = temp;
        temp -> previous = head;
    }

    return count + insert_after(head -> next);
}

int insert_before(node * & head)
{
   /* int count = 0;
    if(!head)
        return 0;
    ++count;
    if(head -> data == 2)
    {
        node * temp = new node;
        temp -> data =0;
        ++count;

        temp -> previous = head -> previous;

        if(head -> previous)
        {
            head -> previous -> next = temp;
        }
        head -> previous = temp;
        temp -> next = head;
    }
     return count + insert_before(head -> next);    */
}

int display_last_two(node * head)
{
    if(!head) 
        return 0;
    if(!head -> next)
        return 0;
    if(!head -> next -> next)
    {
        cout<<head -> data<<endl;
        cout<<head -> next -> data<<endl;
        return 1;
    }
    display_last_two(head -> next);
}
int remove_last_two(node * & head)
{
   if(!head) 
        return 0;
    if(!head -> next)
    {
        delete head;
        head = NULL;
        return 1;
    }
    if(!head -> next -> next)
    {
        remove_last_two(head -> next);
        remove_last_two(head);
        return 1;
        
    }
    return remove_last_two(head -> next);
}


//challenge:
bool same_length(node * head1, node * head2)
{

}

