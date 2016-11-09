#include"cs163_queue.h" 

void queue::removal_entire(q_node *& rear)
{
    if(!rear)
        return;
    if(rear -> next == rear)
    {
        delete rear;
        rear = NULL;
    }
    else
    {
        q_node * temp = rear -> next;
        rear -> next = temp -> next;
        delete temp;
        removal_entire(rear);
    }
}

void queue::removal_all()
{
    removal_entire(rear);
}

int queue::count()
{
    if(!rear)
        return 0;
    if(rear -> next == rear)
        return 1;
    else
    {
        
    }

}
