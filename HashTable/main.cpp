/////////////////////
// Doanh Tran Caraballo
// CS163 
// 02/21/16
/////////////////////
// The purpose of this program is to allow students to seach for classes.
// In order to test the program, the user would have to input the subject
// name, the course number, section as well as day and time.
// The user would also be able to to display all the classed offered during 
// the term by using the display all function.
////////////////////

#include "table.h"

using namespace std;


int main()
{

	subject a_subject, an_entry;        // creates two variables type subject 
	table a_table;			    // creates an object of type table	
 	subject * found_items;		    // found_items is going to be an array of subjects when the retrive 
					    //funtion is called 	

	
	// get_info reads in all the information from the user in main
	int get_info(char course_names[], char course_numbers[], int sections, int crns, char day_and_times[]);

	// temp variables to read in the info
	char course_names[40], course_numbers [40], day_and_times [40];
	int sections, crns = 0;
	bool repeat = true;	
	int choice = 0;

	
	
	do
	{
		cout<<"1: Insert 2: Retrieve 3: Display all 4: Exit"<<endl;
		cin>>choice;
		cin.ignore(100,'\n');	

		switch(choice)
		{
			case 1:	{
					get_info(course_names, course_numbers, sections, crns, day_and_times);
					a_subject.create(course_names, course_numbers, sections, crns, day_and_times);   // creates a subjecy
					a_table.add(a_subject);								 // add a subject into the table
				}	
				break;
			
			case 2: {
					char key_words[40];
					cout<<"Search either by course name or course number"<<endl;
					cin.get(key_words,100); cin.ignore(100,'\n');
				
					int temp_count = a_table.retrieve(key_words, found_items);   // retrieves the matches from my search
												
					for(int i = 0; i < temp_count; ++i)			     // display the matches
					{
						found_items[i].display();
					}
				}
				break;

			case 3: {
					a_table.display_all();						// display all the subjects in the table
				}	
				break;
			
			case 4: {
					repeat = false;
				}
				break;
		
			default: cout<<"Not a valid option"<<endl;	
		}

	}while(repeat);

	
	if(found_items)											//cleans the memory
	{
		delete [] found_items;
	}
	found_items = NULL;
		
	return 0;

}


// gets the info from the user
// this function is separately
int get_info(char course_names[], char course_numbers[], int sections, int crns, char day_and_times[])
{
	cout<<"Please enter a course name"<<endl;
	cin.get(course_names,100); cin.ignore(100,'\n');
	cout<<"Please enter the course number"<<endl;
	cin.get(course_numbers,100); cin.ignore(100,'\n');
	cout<<"Please enter the section"<<endl;
	cin>>sections; cin.ignore(100,'\n');
	cout<<"Please enter the CRN"<<endl;
	cin>>crns; cin.ignore(100,'\n');
	cout<<"Please enter the day and time"<<endl;
	cin.get(day_and_times,100); cin.ignore(100,'\n');
	return 1;
}


