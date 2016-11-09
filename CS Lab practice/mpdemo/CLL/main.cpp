#include "clist.h"
using namespace std;

int main()
{
    node * rear = NULL;
    node * head = NULL;
    int temp = 0;
    build(rear);
    display(rear);

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    make_linear(rear,head);

//    temp = sum_except(head);

//    cout<<temp<<endl;


    display_after_two(head); 
    

    link_again(rear, head);


    

    display(rear); //resulting list after your function call!
    destroy(rear);
    
    return 0;
}
