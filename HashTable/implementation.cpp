#include "act.h"

using namespace std;

//////////
// constructor
/////////

subject::subject()
{
	course_name = NULL;
	course_num = NULL;
	section = 0;
	crn = 0;
	day_and_time = NULL;	
}

/////////
// destructor
////////

subject::~subject()
{
	if(course_name)
		delete [] course_name;
		course_name = NULL;
	if(course_num)
		delete [] course_num;
		course_num = NULL;
	if(day_and_time)
		delete [] day_and_time;
		day_and_time = NULL;
	section = 0;
	crn = 0;

}


//////////////
// the function intitializes all the variables and copy the information
/////////////

int subject::create(char * temp_course_name, char * temp_course_num, int temp_section, int temp_crn, char * temp_day_and_time)
{
	if(course_name)
		delete [] course_name;
	if(course_num)
		delete [] course_num;
	if(day_and_time)
		delete [] day_and_time;
	
	course_name = new char[strlen(temp_course_name) + 1];
	strcpy(course_name, temp_course_name);

	course_num = new char[strlen(temp_course_num) + 1];
	strcpy(course_num, temp_course_num);
	
	section = temp_section;
	crn = temp_crn;		

	day_and_time = new char[strlen(temp_day_and_time) + 1];
	strcpy(day_and_time, temp_day_and_time);
	return 1;
}

////////////
// display the content of my object
///////////

int subject::display()
{
	cout<<"Course name: "<<course_name<<endl;
	cout<<"Course number: "<<course_num<<endl;
	cout<<"Section: "<<section<<endl;
	cout<<"CRN: "<<crn<<endl;
	cout<<"Day & Time: "<<day_and_time<<endl;
	cout<<"-------------------"<<endl;
	return 1;
}
/////////
// initializes the variables and copies them
////////
int subject::copy_subject(subject & copy_from)
{

	if(!copy_from.course_name || !copy_from.course_num || !copy_from.day_and_time)
		return 0;
	if(course_name)
		delete [] course_name;
	if(course_num)
		delete [] course_num;
	if(day_and_time)
		delete [] day_and_time;
	
	course_name = new char[strlen(copy_from.course_name)+ 1];
	strcpy(course_name, copy_from.course_name);

	course_num = new char[strlen(copy_from.course_num)+1];
	strcpy(course_num, copy_from.course_num);
	
	section = copy_from.section;
	crn = copy_from.crn;
	
	day_and_time = new char[strlen(copy_from.day_and_time)+1];
	strcpy(day_and_time, copy_from.day_and_time);	
	return 1;
}


// if there is a match, makes a copy in found

int subject::retrieve(char * matching_course, subject & found)
{
	if(strcmp(matching_course, course_name) == 0 || strcmp(matching_course, course_num) == 0)
	{
		found.course_name = new char[strlen(course_name) +1];
		strcpy(found.course_name, course_name);

		found.course_num = new char[strlen(course_num) +1];
		strcpy(found.course_num, course_num);

		found.section = section;
		found.crn = crn;

		found.day_and_time = new char[strlen(day_and_time) +1];
		strcpy(found.day_and_time, day_and_time);
		return 1;
	}
	else 
		return 0;
}

// compares tittles

bool subject::check_item(char * title)
{	
	if(strcmp(title, course_name) == 0|| strcmp(title, course_num) == 0)
	return true;
	else
	return false;
}

// returns a course name for the hash function

int subject::get_course_name(char *& temp_course)
{
	temp_course = new char[strlen(course_name)+1];
	strcpy(temp_course, course_name);
	return 1;
}

// returns a course number
int subject::get_course_number(char *& temp_num)
{
	temp_num = new char[strlen(course_num)+1];
	strcpy(temp_num, course_num);
	return 1;

}

