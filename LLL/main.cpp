// Doanh Tran Caraballo
// CS162 
// 01/20/2016
// The purpose of the porgram is to help the users buy their favorite cars.
// The users would be able to search for a partciular model depending on the
// features. For instance, if the user wants a car with airbags, the system
// will diplay a count for each match with the highest priority that has
// the customer's specification. The higher the the priority, the better
// the deal. In addition the program has a display function which shows all the cars
// sorted my name.

#include "act.h"

using namespace std;


int main()
{
	int option = 0;
	bool repeat = true;
	char temp_manuf[] ="honda";						// the specific manufacturer for the search 	
	char * temp_manufacturer = new char[strlen(temp_manuf) + 1];           
	strcpy(temp_manufacturer,temp_manuf);
	
			
	char tempmodel[] ="civic";						// the specific model to look for in the list
	char * temp_model = new char[strlen(temp_model) + 1];
	strcpy(temp_model,tempmodel);


	char tempfeature[] ="airbags";						// the feature wanted
	char * temp_feature = new char[strlen(tempfeature) + 1];
	strcpy(temp_feature,tempfeature);



	list_of_cars a;							// creates an objec of type list_of_cars
	a.load_file();							// reads file with car's information
	
	while(repeat)
	{
		cout<<"1:Diplay sorted list by Manufaturer 2: Search Make and Model 3: Display wishing list 4: Exit"<<endl;
		cin>>option;						// gets input for the user
		cin.ignore(100,'\n');
	
		switch (option) 
		{
			case 1:
				a.display_lll();			// displays the list of cars sorted my manufacturers
				break;
			case 2:
			
				a.search_model(temp_manufacturer,temp_model);     //looks for specific manufacturer and model Ex: honda , civic
				break;
			case 3:		
				a.compare_features(temp_feature);                 // compares the wanted feature and increments the count for priority  
				a.call_insert_sorted();				  // makes a list with the best match in terms of features	
				a.display_priority_list();			  // displays the list 	
				
				break;
			case 4: 
				repeat = false;
				break;
		}
		
	}	

	return 0;

}




