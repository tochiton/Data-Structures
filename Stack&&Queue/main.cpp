// Doanh Tran Caraballo
// CS162 
// 02/06/2016
// The purpose of the porgram is to simulate messaging application where
// the user can send a text, save a text and delete previous text.

#include "queue.h"

using namespace std;


int main()
{
	int option = 0;
	entry_message object;      // creates an object of my entry message
	
	bool repeat = true;

	stack my_stack;           // creates an object of my stack
	queue my_queue;		  // creates a queue object	
	entry_message * msg; 	  // msg will point to the peek on the stack in order to display content
	
	char nombre [] = "April";
	char texto [] = "Happy Day";
	
	char * name = new char[strlen(nombre)+1];
	strcpy(name,nombre);

	int phone_num = 50344422;				// to block contact, change num to 503999999
		
	char * text = new char[strlen(texto)+1];
	strcpy(text,texto);

	while(repeat)
	{
		cout<<"1: Create a text 2: Save text 3: Dislplay latest text 4: Delete lastest text 5: Delete oldest text"<<endl;
		cin>>option;
		cin.ignore(100,'\n');
		
		switch(option)
		{
			case 1:
				if(phone_num == 503999999)					// blocks contact
					cout<<"Block contact"<<endl;
				else
				{				
					object.create_message(name,phone_num,text);                    // creates a message
					if(my_stack.push(object))					    // pushes the message into the stack			
					cout<<"Message created"<<endl;
				}
				break;
			case 2: 
				if(my_queue.enqueue(object))						// saves it into the queue
					cout<<"Message saved"<<endl;
				else 
					cout<<"Have to send a text first"<<endl;			
				break;
			
			case 3:	
				msg = my_stack.peek();									
				if(msg)
					msg -> display();
				else
					cout<<"Empty file"<<endl;
				break;
			case 4: 
				if(my_stack.pop())
					cout<<"Message deleted"<<endl;
				else
					cout<<"Empty box"<<endl;
				break;
			case 5: 
				if(my_queue.dequeue())							// delete oldest text
					cout<<"Oldest text deleted"<<endl;
				else
					cout<<"Empty box"<<endl;
				break;		
		
			default : 
				cout<<"Invalid option"<<endl;
		}
		
	}	

	return 0;

}




