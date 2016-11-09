#include "table.h"

// Practice different functions in a BST

int main()
{
    node * root = NULL;

//    node * root2 = NULL;

  //  node1 * head = NULL;

    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */

//    int temp = count_node(root);

    int temp = count_successor(root -> right);
    cout<<"Total child: "<< temp<<endl;

//    my_display(root);

//    insert(head, 1);
//    insert(head, 2);
//    insert(head, 3);

//    display_lll(head);

//    delete_num(root, 2);    

    if(check_valid(root))
        cout<<"It's a tree"<<endl;
    else 
        cout<<"Not a tree"<<endl;

//    if(is_complete(root))
//        cout<<"Full tree"<<endl;
//    else
//        cout<<"Not full"<<endl;
//   display_leaf(root);
//   remove_smallest(root);

    display(root);

    return 0;
}

