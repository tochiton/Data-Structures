#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
   
 //   int smallest_num = find_smallest(head);

 //   cout<<smallest_num<<endl;

 //    wrap_delete_small(head, smallest_num);

//    wrap_insert(head,2);

//    delete_after(head);

//    float temp = calculate_average(head);

//   cout<<"Average: "<<temp<<endl;
    
    
    display(head);
    destroy(head);    
    return 0;
}
