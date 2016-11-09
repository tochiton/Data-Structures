#include "act.h"

using namespace std;

entry_message::entry_message()
{
	name = NULL;
	phone = 0;
	text = NULL;
}

entry_message::~entry_message()
{
	if(name)
	{
		delete [] name;	
		name = NULL;
	}
	phone = 0;

	if(text)
	{
		delete [] text;
		text = NULL;
	}
}

// creates an entry

int entry_message::create_message(char * temp_name, int temp_phone, char * temp_text)
{

	if(name)
		delete [] name;
	if(text)
		delete [] text;

	name = new char[strlen(temp_name)+1];
	strcpy(name,temp_name);
	
	phone = temp_phone;
		
	text = new char[strlen(temp_text) + 1];
	strcpy(text, temp_text);	

	return 1;
}

// display content

int entry_message::display()
{
	cout<<"Name: " << name <<endl;
	cout<<"Phone: "<< phone<< endl;
	cout<<"Text: "<< text <<endl;

	cout<<"-----------"<<endl;

	return 1;
}

// make a copy

int entry_message::copy_entry(entry_message & copy_from)
{
	name = new char[strlen(copy_from.name)+ 1];
	strcpy(name,copy_from.name);
	
	phone = copy_from.phone;
	
	text = new char[strlen(copy_from.text)];
	strcpy(text, copy_from.text);	
}

