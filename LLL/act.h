// Doanh Tran Caraballo
// CS162 
// 01/20/2016
// The purpose of the porgram is to help the users buy their favorite cars.
// The users would be able to search for a partciular model depending on the
// features. For instance, if the user wants a car with airbags, the system
// will diplay a count for each match with the highest priority that has
// the customer's specification. The higher the the priority, the better
// the deal. In addition the program has a display function which shows all the cars
// sorted my name.


#include<iostream>

#include<cctype>
#include<cstring>
#include<fstream> 
struct feature
{
	char * description;
	feature * next;
	 	
};


struct info
{
	
	char * manufacturer;
	char * model;
	int year;
	int price;
	int num_of_features;
	int priority;
	
	feature * head;
	info();
	int copy(char temp_feature);
	int insert(char temp_feature[]);	
	
	int copy(info & to_add);
	int compare(info & to_compare);
	int display();
	int delete_features();
	int compare_features(char * keyword);
};

struct node
{
	info data;
	node * next;
};

struct s_node
{
	node * data;
	s_node * next;
};


class list_of_cars 
{
	public:
		list_of_cars();
		
		int load_file();
		int add_to_lll(info & to_add);
		int add(node * previous, node * current, node * temp);
		int display_lll ();
		int compare_features(char * keyword);
	
		int insert_sorted(node * to_add);
		int call_insert_sorted();			
		int display_priority_list();	
		
		int search_model(char * make, char * model);		

		~list_of_cars();
	
	
	private:
		node * head;
		node * tail;
		int display_lll(node * head);
		s_node * sorted_head;

};
