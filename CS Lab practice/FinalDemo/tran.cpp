#include"table.h"

int count_node(node * root) 
{
    if(!root)
        return 0;
    return 1 + count_node(root -> left) + count_node(root -> right);
}

int sum_up(node * root)
{
    if(!root)
        return 0;
    return root -> data + sum_up(root -> left) + sum_up(root -> right);
}

int get_height(node * root)
{
    if(!root)
        return 0;
    
    return 1 + max(get_height(root -> left), get_height(root -> right));
}

int is_full(node * root)
{
    if(!root)
        return 0;
   
    if(!is_full(root -> left))
        return 0;
    if(!is_full(root -> right))
        return 0;
 
    if(get_height(root -> left) != get_height(root -> right))
        return 0;
    else
      return 1;
    
  }

int count_child(node * root)
{
    if(!root)
        return 0;
    
    if(!root -> left && !root -> right)
        return 1;

    return count_child(root -> left) + count_child(root -> right);


}

int count_one_child(node * root)
{
    if(!root)
        return 0;
    if((!root -> left && root -> right) || (root -> left && !root -> right))
        return 1;
    return count_one_child(root -> left) + count_one_child(root -> right);
}

int display_leaf(node * root)
{
    if(!root)
        return 0;
    if(!root -> left && !root -> right)
        cout<<"Leaf: "<<root -> data<<endl;

    display_leaf(root -> left);
    display_leaf(root -> right);
    return 1;
}

int remove_smallest(node *& root)
{
    if(!root)
        return 0;
    if(!root -> left && root -> data != 2 )
    {
        if(!root -> right)
        {
            delete root;
            root = NULL;
            return 1;
        }
        else
        {
            node * temp = root;
            root = root -> right;
            delete temp;
            temp = NULL;
            return 1;
        }
    }
    remove_smallest(root -> left);
    return 1;
}

int count_successor(node * root)
{
    if(!root)
        return 0;
  
    return 1 + count_successor(root -> left); 

}

int is_complete(node * root)
{
    if(!root)
        return 0;
    if((root -> left && root -> right) || (!root -> left && !root -> right))
    {
        return is_complete(root -> left);
        return is_complete(root -> right);
        return 1;
    }
    else
        return 0;

}

/*
int is_balance(node * root)
{
    if(!root)
        return 0;
    if(!get_complete(root -> left))
        return 0;
    if(!get_complete(root -> right))
        return 0; 
    int left = get_height(root -> left);
    int right = get_height(root -> right);
    if(abs(left - right) > 1)
        return 0;
    else 
        return 1;
}
*/

int my_display(node * root)
{
    if(!root)
        return 0;
    my_display(root -> left);

    cout<<".."<< root -> data;

    my_display(root -> right);

    return 1;
}

int insert(node1 *& head, int num)
{
    if(!head)
    {
        head = new node1;
        head -> data = num;
        head -> next = NULL;
    }
    else
    {
        node1 * current = head;
        node1 * previous = current;

        while(current -> next)
        {
            previous = current;
            current = current -> next;
        }

        node1 * temp = new node1;
        temp -> data = num;
        temp -> next = NULL;

        previous -> next = temp;
    }

    return 1;
}




int get_successor(node * root)
{
    if(!root)
        return 0;
    if(!root -> left)
        return root -> data;

    get_successor(root -> left);
}

int count_bigger_two(node * root)
{
    if(!root)
        return 0;

    if(root -> data == 2)
        return 1;

    return count_bigger_two(root -> left) + count_bigger_two(root -> right);

}

int delete_node(node *& root)
{
    if(!root)
        return 0;
    else if(!root -> left && !root -> right)
    {
        delete root;
        root =NULL;
        return 1;
    }
    else if(!root -> left && root -> right)
    {
        node * temp = root;
        root = root -> right;
        delete temp;
        return 1;
    }
    else if(root -> left && !root -> right)
    {
        node * temp = root;
        root = root -> left;
        delete temp;
        return 1;
    }
    else
    {
        node * current = root -> right;
        if(!current -> left)
        {
            root -> data = current -> data;
            root -> right = current -> right;
            delete current;
            return 1;
        }

        else 
        {
                node * previous = current;
                while(current -> left)
                {
                    previous = current;
                    current = current -> left;
                }
                root -> data = current -> data;
                previous -> left = current -> right;
                delete current;
                return 1;
        }
        
    }

}


int delete_num(node *& root, int value)
{
    if(!root)
        return 0;
    if(root -> data == value)
    {
        return delete_node(root);
    }
    return delete_num(root -> left, value) + delete_num(root -> right, value);
}

bool check_valid(node * root)
{
    if(!root)
        return true;
    if(root -> left -> data < root -> data && root -> right -> data > root -> data)
    {
        if(check_valid(root -> left))
            return check_valid(root -> right);
    }

    return false;
}

