#include "act.h"

using namespace std;

//////////
// constructor
/////////

city::city()
{
	city_name = NULL;
}

/////////
// destructor
////////

city::~city()
{
	if(city_name)
		delete [] city_name;
}


//////////////
// the function intitializes all the variables and 
// copy the information
/////////////

int city::create(char * temp_city_name)
{
	if(city_name)
		delete [] city_name;
	
	city_name = new char[strlen(temp_city_name) + 1];
	strcpy(city_name, temp_city_name);
	return 1;
}

////////////
// display the content of my object
///////////

int city::display()
{
	cout<<"City name: "<<city_name<<endl;
	cout<<"-------------------"<<endl;
	return 1;
}
/////////
// initializes the variables and copies them
////////
int city::copy_city(city & copy_from)
{

	if(!copy_from.city_name)
		return 0;
	if(city_name)
		delete [] city_name;
	
	city_name = new char[strlen(copy_from.city_name)+ 1];
	strcpy(city_name, copy_from.city_name);


	return 1;
}


// if there is a match, makes a copy in found

int city::retrieve(city & found)
{
	found.city_name = new char[strlen(city_name) +1];
	strcpy(found.city_name, city_name);

	return 1;

}


int city::get_city_name(char *& temp_course)
{
	temp_course = new char[strlen(city_name)+1];
	strcpy(temp_course, city_name);
	return 1;
}

int city::compare(char * key_value)
{
	return strcmp(city_name, key_value);
}

