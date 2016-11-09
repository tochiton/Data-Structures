//clist.h
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
void build(node * & rear);  //supplied
void display(node * rear);  //supplied
void destroy(node * & rear); //supplied

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:

int make_linear(node *& rear, node *& head);

int link_again(node *& rear, node *& head);

int sum_except(node * head);

int display_after_two(node * head);

node * print(node * head);
