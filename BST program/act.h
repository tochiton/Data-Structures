/////////////////////
// Doanh Tran Caraballo
// CS163 
// 02/21/16
/////////////////////
// Program 4 is an extension of program three. The only difference is the
// data structure. In this program a tree will be used instad of a hash_table.
// The purpose of this program is to allow students to seach for classes.
// In order to test the program, the user would have to input the subject
// name, the course number, section as well as day and time.
// The user would also be able to to display all the classed offered during 
// the term by using the display all function.
////////////////////

#include<iostream>

#include<cctype>
#include<cstring>
#include<fstream> 


class subject
{
	public:
		subject();          // constructor
		~subject();		// destructor		
		int create(char * temp_course_name, char * temp_course_num, int temp_section, int temp_crn, char * temp_day_and_time); // initializes all the values
		int copy_subject(subject & copy_from);     				// copy the info from the object that is passed in
		int retrieve(subject & found);						// checks if there is a match and makes a copy
		bool check_item(char * title);						// checks for matches 
		int display();								// displays my local variables 
		int get_course_name(char *& temp_course);				// returns the name of the course
		int get_course_number(char *& temp_num);				// returns the course number
		
		int compare(subject & to_compare);					// compare the course name of each object for the insertion

		int compare_range(char temp_range[]);					// compare the object's course name to a temp char to see if there 											  // is a match

	private:
	 	char * course_name;
		char * course_num;
		int section;
		int crn;
		char * day_and_time;
};
