#include "bst.h"


BST::BST()
{
	root = NULL;
}
BST::node * BST::create_leaf(int key)
{
	node * n = new node;
	n -> key = key;
	
	n -> left = NULL;
	n -> right = NULL;

	return n;
}
void BST::add_leaf(int key)
{
	add_leaf_private(key, root);
}


void BST::add_leaf_private(int key, node * ptr)
{
	if(!root)	            		// no element in the trees, create the first one
	{
		root = create_leaf(key);	
	}
	else if(key < ptr -> key)		// if the key values is smaller, go to left
	{
		if(ptr -> left != NULL)		// if the left value is not at the end, call myself again		
		{
			add_leaf_private(key, ptr -> left);
		}
		else					// if I'm at the end, and still smaller, create a leaf
		{
			ptr -> left = create_leaf(key);
		}
	}	

	else if(key > ptr -> key) 			// if the value is bigger, moves the right
	{
		if(ptr -> right != NULL)		// not at the end yet, call myself
		{
			add_leaf_private(key, ptr -> right);
		}
		else
		{
			ptr -> right = create_leaf(key);
		}
	}
	
	else 
	{
		cout<<"The key is in the list already"<<endl;
	}
}

void BST::print_in_order()
{
	print_in_order_private(root);
}

void BST::print_in_order_private(node * ptr)
{
	if(root)	
	{
		if(ptr -> left)
		{
			print_in_order_private(ptr -> left);
		}			
		cout<<"Value: "<<ptr -> key <<endl;

		if(ptr -> right)
		{
			print_in_order_private(ptr -> right);
		}
	}
	else
	{	
		cout<<"The tree is empty"<<endl;
	}
}

BST::node * BST::return_node(int key)
{
	return return_node_private(key, root);
}

BST::node * BST::return_node_private(int key, node * ptr)
{
	if(ptr)
	{
		if(ptr -> key == key)
		{
			return ptr;
		}
		else
		{
			if(key < ptr -> key)
			{
				return return_node_private(key, ptr -> left);
			}
			else
			{	return return_node_private(key, ptr -> right);
			}
		}
	}
	else
		return NULL;
}


