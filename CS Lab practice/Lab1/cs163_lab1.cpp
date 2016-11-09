#include "cs163_list.h"
using namespace std;

int main()
{
    
    //First try this out as is. Then start adding in your function calls!
    list my_list;
    my_list.build();
    my_list.display_all();

    //PLACE YOUR FUNCTION CALL HERE!
    int sum =0;

    sum = my_list.sum_total();
    cout<<sum<<endl;
    
    //my_list.remove_last();

    /*
    if(my_list.find_item(0))
        cout<<"Found!!"<<endl;
    else
        cout<<"Not found!!"<<endl;
    */
    
    if(my_list.swap_2nd_last())
        cout<<"Swap!!"<<endl;
    else
        cout<<"No SWap!!"<<endl;

    my_list.display_all();
    return 0;    
}
