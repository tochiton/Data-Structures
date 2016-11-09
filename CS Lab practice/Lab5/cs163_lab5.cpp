#include "cs163_list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int count_of_2;

 //   count_of_2 = insert_before(head);
 //   cout<<count_of_2<<endl;

    display_last_two(head);

    remove_last_two(head);

    display(head);
    
    return 0;
}
