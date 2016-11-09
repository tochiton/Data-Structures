#include "act.h"

using namespace std;


info::info()				// constructor
{
	head = NULL;
}

/////////////////
// takes a feature from the list 
// and puts it at the beginnig of 
// a linear linked list
////////////////


int info::insert(char temp_feature[])
{
	feature * temp = new feature;
	temp -> description = new char[strlen(temp_feature)+1];
	strcpy(temp -> description,temp_feature);

	if(!head)
	{
		head = temp;
		temp -> next = NULL;
	}	
	else 
	{
		temp -> next = head;
		head = temp;
	}
	
}


///////////////////
// takes a keyword and compares it through all the 
// features in the car list. It adds two points to
// the priority count for each match and decrements 
// one point for each mismatch 
//////////////////

int info:: compare_features(char * keyword)
{	
	if(!head)
		return 0;
	feature * current = head;
	while(current)
	{
		if(strcmp(keyword,current->description)==0)
			priority = priority +2;
		else
			--priority;
		current = current -> next;	
	}
	return 1;
}

//////////////////
// copy all the infomation into an object info
// allocates memory and inserts each feature
// in a linear linked list
/////////////////



int info::copy(info & to_add)
{
	manufacturer = new char[strlen(to_add.manufacturer)+1];
	strcpy(manufacturer,to_add.manufacturer);
	model = new char[strlen(to_add.model)+1];
	strcpy(model,to_add.model);
	
	year = to_add.year;
	price = to_add.price;
	
	feature * current = to_add.head;
	
	while(current)
	{
		insert(current -> description);
		current = current -> next;
	}

	
}	

///////////////
// returns one if there is a match
// with the manufacturer in file vs
// the user's want
//////////////

int info::compare(info & to_compare)
{
	return strcmp(manufacturer,to_compare.manufacturer);
}

/////////////
// displays all the infomation in my struct info
// including the features as well
////////////



int info::display()
{
	if(manufacturer && model) {
		cout << "Manufacturer :  " << manufacturer<<endl;
		cout << "Model :  " << model<<endl;
		cout << "Year :  " << year<<endl;
		cout << "Price : " <<price<<endl;
		cout << "Priority: "<<priority<<endl;

		feature * current = head;
		while(current)
		{
			cout << "Feature : " << current ->description<<endl;
			current = current -> next;
		}
			cout << "-----------------------"<<endl;
	}
	else
		cout << "DATA NOT SET!!" << endl; 
}

//////////////
// destructor for the features 
/////////////


int info::delete_features()
{
	feature * temp;

	while(head)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
}

///////////
// constructor for the class
///////////

list_of_cars::list_of_cars()
{
	head = NULL;
	tail = NULL;
	sorted_head = NULL;
}

//////////
// reads from file and saves the info
// into a linear linked list
/////////


int list_of_cars::load_file()
{
	char temp [100];
	info car;    					//creates the variable car of type info
	ifstream file_in;
	file_in.open("vehicle.txt");			// opens file
	file_in.peek();
						
	if(!file_in) 					// checks if file exits 		
	{
		cout<<"File doesn't exit"<<endl;
		return 0;
	}
	while (!file_in.eof())
	{
		file_in.get(temp,100,':');
		file_in.ignore(100,':');
			
		if(!file_in.eof())
		{

		car.manufacturer = new char[strlen(temp)+1];
		strcpy(car.manufacturer,temp);
	
		file_in.get(temp,100,':');
		file_in.ignore(100,':');
		
		car.model = new char[strlen(temp)+1];
		strcpy(car.model,temp);

		file_in>>car.year;
		file_in.ignore(100,':');

		file_in>>car.price;
		file_in.ignore(100,':');	
		
		file_in>>car.num_of_features;
		file_in.ignore(100,':');

		for(int i =0; i< car.num_of_features; ++ i) 	// reads in each feature and puts it into a list 
		{
			file_in.get(temp,100,':');
			file_in.ignore(100,':');
			car.insert(temp);			// inserts each feature at the beginning 
				
		}
		file_in.ignore();

		add_to_lll(car);				// puts the whole car object into a list 

		delete [] car.manufacturer;
		delete [] car.model;
		car.delete_features();				// empties all the temp features 

		}
		
	
	}
			return 1;
}

////////////
// builds the list sorted by manufacturer
///////////

int list_of_cars::add_to_lll(info & to_add)   
{

	node * temp = new node;				
	temp -> data.copy(to_add);			// copies all the info from to_add into temp
							// sorts the list
	if(!head)
	{
		head = temp;
		return 1;
	}
	else if ((temp -> data.compare(head->data)) <= 0)    // puts temp in front of head if temp is smaller
	{
		temp -> next = head;
		head = temp;
		return 1;
	}

	add(head, head -> next, temp);			// organizes the list recursively 

	

}

////////////
// sorts the list recursively
////

int list_of_cars:: add(node * previous, node * current, node * temp)
{
	
	if (!previous || !temp)
		return 1;

	if(!current)
	{
		previous -> next = temp;
		temp -> next = NULL;
		return 1;
	}
	else if((temp -> data.compare(current->data)) <= 0)
	{
		temp -> next = current;
		previous -> next = temp;
		return 1;
	}

	add(previous -> next, current -> next, temp);

}

/////////
// displays the entire linear linked list
////////

int list_of_cars:: display_lll(node * head)

{
	if(!head)
		return 0;
	head ->data.display();
	display_lll(head -> next);
}

int list_of_cars:: display_lll ()
{
	display_lll(head);
}

int list_of_cars::compare_features(char * keyword)
{
	if(!head)
		return 0;
	node * current = head;
	while(current)
	{
		current ->data.compare_features(keyword);
		current = current -> next;
	}
		return 1;
}

int list_of_cars:: insert_sorted(node * to_add)
{
	if(!sorted_head)
	{
		sorted_head = new s_node;
		sorted_head -> data = to_add;
		sorted_head -> next = NULL;
		return 1;
	}
	
	s_node * temp = new s_node;
	temp -> data = to_add;

	if(to_add ->data.priority >= sorted_head ->data ->data.priority)
	{
		temp -> next = sorted_head;
		sorted_head = temp;		
		return 1;
	}

	s_node * current = sorted_head;
	s_node * previous = sorted_head;

	while( current && to_add -> data.priority <= current -> data -> data.priority)
	{
		previous = current;
		current = current -> next;
	}
	
	previous -> next = temp;
	temp -> next = current;
}

int list_of_cars:: call_insert_sorted()
{
	node * current = head;
	while(current)
	{
		insert_sorted(current);
		current = current -> next;
	}
	return 1;
}

list_of_cars::~list_of_cars()
{
	node * temp;

	while(head)
	{
		temp = head->next;
		delete [] head-> data.manufacturer;
		delete [] head-> data.model;
		
		feature * ftemp = head->data.head;
		feature * fhead = head->data.head;
		while(fhead)
		{	
			ftemp = fhead->next;
			delete [] fhead->description;
			fhead = ftemp;	
		}		

		head->data.head = NULL;
		head = temp;
	}
		head = NULL;
}

int list_of_cars::display_priority_list()
{
	s_node * temp = sorted_head;
	while(temp)
	{
		temp -> data -> data.display();
		temp = temp -> next;
	} 
}	

int list_of_cars:: search_model(char * make, char * model)
{
	node * temp = head;
	while(temp)
	{
		if(strcmp(temp ->data.manufacturer, make) == 0 && strcmp(temp ->data.model,model) == 0 )
			temp ->data.display();

		temp = temp -> next;
	}
}
