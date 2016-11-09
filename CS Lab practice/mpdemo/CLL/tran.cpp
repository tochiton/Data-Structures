#include"clist.h"


int make_linear(node *& rear, node *& head)
{
    head = rear -> next;
    rear -> next = NULL;
    return 1;
}

int link_again(node *& rear, node *& head)
{
    rear -> next = head;
    if(head)
    {
        head = NULL;
    }
    return 1;
}

int sum_except(node * head)
{
    if(!head)
        return 0;
    if(head -> data != 2)
    { cout << head->data << endl; return head -> data + sum_except(head -> next);}
    
    else
        return sum_except(head -> next);
}

int display_after_two(node * head)
{
    if(!head)
        return 0;

    if(head -> data == 2 && !head -> next && head -> next -> data != 2)
    {
       return display_after_two(print(head -> next));
    }
    else
        return display_after_two(head -> next);
}
node * print(node * head)
{
    cout<<head -> data<<endl;

    if(head -> next -> data == 2 || !head -> next)

        return head -> next;
    else
        return print(head -> next);

}
