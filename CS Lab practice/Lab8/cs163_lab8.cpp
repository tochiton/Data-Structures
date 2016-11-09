#include "cs163_2-3.h"
using namespace std;

int main()
{
    table trees;
    trees.build();
    trees.display();

    /*  PLACE YOUR FUNCTION CALL HERE */
    
   // trees.display_23();

    if(trees.find_largest())
        cout<<"Yea"<<endl;
    else
        cout<<"Nope"<<endl;
    
    return 0;
}
