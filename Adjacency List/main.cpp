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

#include "table.h"

using namespace std;


int main()
{

	city a_city, an_entry;        		// creates two variables type city 
	table a_table;			   	// creates an object of type table	
//	city found_items[10];			// found_items is going to be an array of citys when the retrive 
						//funtion is called. It's going to return the first 10 matches 	

	
	// get_info reads in all the information from the user in main
	int get_info(char city_names[]);

	// temp variables to read in the info
	char city_names[40]; 

	char temp[40];						
	bool repeat = true;	
	int choice = 0;

	
	
	do
	{	cout<<"Please select an option"<<endl;
		cout<<"1: Insert"<<endl;
		cout<<"2: Make connection" <<endl; 
		cout<<"3: Display adjacent"<<endl;
		cout<<"4: Check for complete graph or connected"<<endl;
		cout<<"5: Exit"<<endl;
		cin>>choice;
		cin.ignore(100,'\n');	

		switch(choice)
		{
			case 1:	{
					get_info(city_names);
					a_city.create(city_names);   			// creates an object
					a_table.insert_vertex(a_city);			// insert the city in a graph	
				}	
				break;
			
			case 2: {
					char range1[40];    char range2[40];		// insert an edge between two cities	
					cout<<"Enter city destination one"<<endl;
					cin.get(range1,100); cin.ignore(100,'\n');
					
					cout<<"Enter city destination two"<<endl;
					cin.get(range2,100); cin.ignore(100,'\n');
					
					a_table.insert_edge(range1, range2);
				}
				break;

			case 3: {	
					cout<<"Enter city "<<endl;
					cin.get(temp,100); cin.ignore(100,'\n');
					a_table.display_adjacent(temp);			// display all the citys 
				}	
				break;
			
			case 4: {
					if(a_table.check_complete())			// checks for a complete or connected graph	
						cout<<"It's a complete graph"<<endl;
					else
						cout<<"Not a full graph"<<endl;
				}
				break;
	
			case 5: {
					repeat = false;	
				}
				break;
		
			default: cout<<"Not a valid option"<<endl;	
		}

	}while(repeat);	

	return 0;

}


// gets the info from the user
int get_info(char city_names[])
{
	cout<<"Please enter a city name"<<endl;
	cin.get(city_names,100); cin.ignore(100,'\n');
	return 1;
}


