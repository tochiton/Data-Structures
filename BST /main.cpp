#include"bst.h"

using namespace std;

int main()
{
	BST my_trees;
	int treeskey[10] = {12,45,56,89,6,99,87,14,11,27};

	for(int i = 0; i < 10; ++i)
	{
		my_trees.add_leaf(treeskey[i]);
	}	

	my_trees.print_in_order();

	return 0;
}
