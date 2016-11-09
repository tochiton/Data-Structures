#include "list.h"
using namespace std;



int main()
{
    node * head = NULL;
  
    node * source = NULL;
   

    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned


    
//    copy(head, source);

//    clone(head, source);

//    destroy_except_last(head);

    display(head);

/*    if(compare_length(head, source))
        cout<<"The same lenght"<<endl;
    else
        cout<<"NOt the same"<<endl;
*/
//    display_reverse(head);

 
    int temp = count_node(head);
    
    int table[temp];

    copy_into_array(head, temp, table);

    cout<<"From table: "<<table[temp - 1]<<endl;

    
    
 //   find_smallest(head, temp);

    cout<<temp<<endl;
//

    display(head); //redisplay the list after your function
    destroy(head); 
    return 0;
}
