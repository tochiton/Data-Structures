//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;;
};

struct node1
{
    int data;
    node1 * next;
};

void build(node * & root);  //supplied
void display(node *  root); //supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
 
int count_node(node * root); 

int sum_up(node * root);

int get_height(node * root);

int is_full(node * root);

int count_child(node * root);

int count_one_child(node * root);

int display_leaf(node * root);

int remove_smallest(node *& root);

int count_successor(node * root);

int is_complete(node * root);

int is_balance(node * root);

int my_display(node * root);

int insert(node1 *& head, int num);

int display_lll(node1 * head);

int insert_bst(node *& root2);

int get_successor(node * root);

int count_bigger_two(node * root);

int delete_node(node *& root);

int delete_num(node *& root, int value);
bool check_valid(node * root);
