#include <iostream>
#include <cstdlib>


using namespace std;

class BST
{
	private:
		struct node
		{	
			int key;
			node * left;
			node * right;	
		};	
			
		node * root;
		
		void add_leaf_private(int key, node * ptr);
		void print_in_order_private(node * ptr);
		node * return_node_private(int key, node * ptr);
	
	public:
		BST();
		node * create_leaf(int key);
		void add_leaf(int key);
		void print_in_order();
		node * return_node(int key);
};
