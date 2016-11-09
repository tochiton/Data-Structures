#include "cs163_bst.h"
using namespace std;

int main()
{
    table BST;	
    BST.build();
    BST.display();

    /*  PLACE YOUR FUNCTION CALL HERE */

    int temp = BST.sum();

    cout<<"BST with no children: "<<temp<<endl;



    BST.display();

    return 0;
}
