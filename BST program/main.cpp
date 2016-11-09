/////////////////////
// Doanh Tran Caraballo
// CS163 
// 02/28/16
/////////////////////
// Program 4 is an extension of program three. The only difference is the
// data structure. In this program a tree will be used instad of a hash_table.
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
	subject found_items[10];		// found_items is going to be an array of subjects when the retrive 
					    //funtion is called. It's going to return the first 10 matches 	

	
	// get_info reads in all the information from the user in main
	int get_info(char course_names[], char course_numbers[], int & sections, int & crns, char day_and_times[]);

	// temp variables to read in the info
	char course_names[40], course_numbers [40], day_and_times [40];
	int sections, crns = 0;
	char temp[40];						
	bool repeat = true;	
	int choice = 0;

	
	
	do
	{	cout<<"Please select an option"<<endl;
		cout<<"1: Insert"<<endl;
		cout<<"2: Retrieve by range" <<endl; 
		cout<<"3: Display all"<<endl;
		cout<<"4: Search"<<endl;
		cout<<"5: Delete course"<<endl; 
		cout<<"6: Exit"<<endl;
		cin>>choice;
		cin.ignore(100,'\n');	

		switch(choice)
		{
			case 1:	{
					get_info(course_names, course_numbers, sections, crns, day_and_times);
					a_subject.create(course_names, course_numbers, sections, crns, day_and_times);   // creates a subjecy
					a_table.add(a_subject);								 // add a subject into the tree
				}	
				break;
			
			case 2: {
					char range1[40];    char range2[40];
					cout<<"Enter subject in the lowest range"<<endl;
					cin.get(range1,100); cin.ignore(100,'\n');
					
					cout<<"Enter subject in the highest range"<<endl;
					cin.get(range2,100); cin.ignore(100,'\n');

					int temp_count = a_table.retrieve(found_items, range1, range2);   // retrieves the matches within the range
								
					for(int i = 0; i < temp_count; ++i)			     // display the matches
					{
						found_items[i].display();
					}
				}
				break;

			case 3: {
					a_table.display_all();						// display all the subjects in the tree
				}	
				break;
			
			case 4: {
					cout<<"Enter course number to search"<<endl;
					cin.get(temp,100); cin.ignore(100,'\n');

					a_table.retrieve_by_num(an_entry, temp);			// return the match
					an_entry.display();
				}
				break;
			case 5: {	
					cout<<"Enter course number to delete"<<endl;
					cin.get(temp,100); cin.ignore(100,'\n');

					a_table.delete_course(temp);					// deletes a course in the tree
				}
				break;
			case 6: {
					repeat = false;	
				}
				break;
		
			default: cout<<"Not a valid option"<<endl;	
		}

	}while(repeat);	

	return 0;

}


// gets the info from the user
int get_info(char course_names[], char course_numbers[], int & sections, int & crns, char day_and_times[])
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


