// Doanh Tran Caraballo
// CS162 
// 02/06/2016
// The purpose of the porgram is to simulate messaging application where
// the user can send a text, save a text and delete previous text.

#include<iostream>

#include<cctype>
#include<cstring>
#include<fstream> 

class entry_message
{
	public:
		entry_message();
		~entry_message();
		
		int create_message(char * temp_name, int phone, char * temp_text);
		int display();
		
		int copy_entry(entry_message & copy_from);

	private: 
		char * name;
		int phone;
		char * text;
};
