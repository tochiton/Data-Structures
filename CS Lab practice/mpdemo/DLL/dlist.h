//doubly linked list
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    node * previous;
    node * next;
};

/* These functions are already written and can be called to test out your code */
void build(node * & head);  //supplied
void display(node * head);  //supplied
void destroy(node * &head); //supplied

/* *****************YOUR TURN! ******************************** */
/* place your prototype here */

int find_smallest(node * head);

int wrap_delete_small(node *& head, int temp);

int remove_smallest(node *& head, int temp);


int insert_before(node *& head, int num_temp);

int wrap_insert(node *& head, int number);

int delete_after(node *& head);

int count_node(node * head);

int sum_data(node * head);

float calculate_average(node * head);

