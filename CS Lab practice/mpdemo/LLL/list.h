//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;
    node * next;
};


/* These functions are already written and can be called to test out your code */
void build(node * & head);  //supplied
void display(node * head);  //supplied
void destroy(node * &head); //supplied

int destroy_except_last(node *& head);

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:

int clone(node * head, node *& source);

int copy(node * head, node *& source);

int display_reverse(node * head);

int remove_biggest(node * head);
int find_biggest(node * head, int & biggest);

int count_node(node * head);

int wrap_smallest();

int find_smallest(node * head, int & temp);


node * reverse (node * head);

bool compare_length(node * head, node * source);

int count_of_two(node*head);

int copy_into_array(node * head, int count, int temp []);
