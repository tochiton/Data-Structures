/////////////////////
// Doanh Tran Caraballo
// CS163 
// 03/8/16
/////////////////////
// The purpose of program 5 is to implement a graph which simulates
// flights between cities using an adjacency list. The adjacency list
// is an array of pointers in which each element has a head pointer
// to a linear linked list.
// The user would have to input the cities in order to make the
// the connection between them.
////////////////////

#include<iostream>

#include<cctype>
#include<cstring>
#include<fstream> 


class city
{
	public:
		city();        							// constructor
		~city();							// destructor		
		int create(char * temp_city_name); 				// initializes all the values
		int copy_city(city & copy_from);     				// copy the info from the object that is passed in
		int retrieve(city & found);					// checks if there is a match and makes a copy
		int display();							// displays my local variables 
		int get_city_name(char *& temp_course);				// returns the name of the course
		
		int compare(char * key_value);

	private:
	 	char * city_name;

};
