#include<iostream>
#include <stdlib.h>
#include <string>
#include "phonebook.h"
using namespace std;

//Function used for adding contacts
void addContact(){
	cin.get(pause);          //These things are for pausing the screen
    system("cls");           //And clearing the screen
    newNode = new NODE;
    cout << "Enter First Name: ";
    cin >> newNode->firstName;
    cout << "Enter Last Name: ";
    cin >> newNode->lastName;
    cout << "Enter Phone Number: ";
    cin >> newNode->number;
    cout << "Enter e-mail Address: ";
    cin >> newNode->email;
    
	//Creating head if list is empty
    if(head == NULL){
        head = newNode;
        temp = newNode;
    }
    //Adds a node at the end of list if head exists
    else{
        temp->next= newNode;
        temp = newNode;
    }
}


//Function to display all contacts
void display(){
	cin.get(pause);
    system("cls");
    //Checking if list is empty
    if(head == NULL)
    {
        cout<<"Contact List Empty"<<endl;
    }
    else
    {
        NODE *search = head ;
        //Loops until it reaches NULL
        while (search != NULL)
        {
        	cout << "   " << len+1;
            cout << "    |First Name: " << search->firstName << endl;
            cout << "        |Last Name: " << search->lastName << endl;
            cout << "        |Phone Number: " << search->number << endl;
            cout << "        |e-mail Address: " << search->email << endl;
            cout << "----------------------------" << endl;
            search = search->next;
            len++; //Len is just used to display the numbers of the contacts to make it easy to choose one for the other functions
        }      
    }
}

//Used for shortening searchContact, all the printing stuff
void searchCase(NODE *search){
	cout << "First Name: " << search->firstName << endl;
    cout << "Last Name: " << search->lastName << endl;
    cout << "Phone Number: " << search->number << endl;
	cout << "e-mail Address: " << search->email << endl;	
    cout << "\nPress Enter to Continue..." << endl;
}

void searchContact(){
	cin.get(pause);
	system("cls");
	NODE *search = head;
	string searchString;
	bool found = false;
	
	//Checks if list is empty
	if(head == NULL){
		cout << "Contact List Empty" << endl;
	}
	
	//If list isn't empty, loop
	while(head != NULL && found == false){
		cout << "1. Search by First Name" << endl;
        cout << "2. Search by Last Name" << endl;
        cout << "3. Search by Phone Number" << endl;
        cout << "4. Search by e-mail Address" << endl;
        cout << "--------------------------------" << endl;
        
        int option;
        cin>>option;
        switch(option){
        	//SEARCH BY FIRST NAME
        	case 1:
        		system("cls");
        		cout << "Search First Name: ";
        		cin >> searchString;
        		while(search != NULL && found == false){
        			if(searchString == search->firstName){
        				cin.get(pause);
        				system("cls");
        				searchCase(search);
        				found = true;
        				break;
					}
					search = search->next;
				}
				if(found == false){
					cin.get(pause);
	        		system("cls");
	        		cout << "Not Found" << endl;
	        		found = true;
	        		break;
	        	}
	        	break;
	        
			//SEARCH BY LAST NAME	
	        case 2:
        		system("cls");
        		cout << "Search Last Name: ";
        		cin >> searchString;
        		while(search != NULL && found == false){
        			if(searchString == search->lastName){
        				cin.get(pause);
        				system("cls");
        				searchCase(search);
        				found = true;
        				break;
					}
					search = search->next;
				}
				if(found == false){
					cin.get(pause);
	        		system("cls");
	        		cout << "Not Found" << endl;
	        		found = true;
	        		break;
	        	}
	        	break;
	        
			//SEARCH BY PHONE NUMBER	
	        case 3:
        		system("cls");
        		cout << "Search Phone Number: ";
        		cin >> searchString;
        		while(search != NULL && found == false){
        			if(searchString == search->number){
        				cin.get(pause);
        				system("cls");
        				searchCase(search);
        				found = true;
        				break;
					}
					search = search->next;
				}
				if(found == false){
					cin.get(pause);
	        		system("cls");
	        		cout << "Not Found" << endl;
	        		found = true;
	        		break;
	        	}
	        	break;
	        
	        //SEARCH BY EMAIL
	        case 4:
        		system("cls");
        		cout << "Search e-mail Address: ";
        		cin >> searchString;
        		while(search != NULL && found == false){
        			if(searchString == search->email){
        				cin.get(pause);
        				system("cls");
        				searchCase(search);
        				found = true;
        				break;
					}
					search = search->next;
				}
				if(found == false){
					cin.get(pause);
	        		system("cls");
	        		cout << "Not Found" << endl;
	        		found = true;
	        		break;
	        	}
	        	break;
	        	
	        default:
	        	system("cls");
	        	cout << "Invalid Option" << endl;
	        	break;
		}
	}
}

//FUNCTION FOR EDITING CONTACT
void editContact(){
	system("cls");
    display();
    int pos;
    NODE *next_node;
    temp = head;
    
    
    if(head != NULL){
	    cout<<"Which contact would you like to edit?"<<endl;
	    cin>>pos;
	    pos = pos - 1; //This is so that the user option does not start from 0
	}

    
    //Checks if contact list is empty
    if(head == NULL){
    	cin.get(pause);
    	system("cls");
        cout<<"Contact List Empty"<<endl;
    }

	//Checks if user inputs a valid option
    else if(pos > len || pos < 0){
    	cin.get(pause);
    	system("cls");
        cout<<"Invalid Position "<<endl;
    }
    
    //Checks if user selects head or first thing on the list
    else if(pos == 0 && head != NULL){
    	cin.get(pause);
    	system("cls");
    	//Updates all the contact info
        cout << "Enter First Name: ";
    	cin >> temp->firstName;
    	cout << "Enter Last Name: ";
    	cin >> temp->lastName;
    	cout << "Enter Phone Number: ";
    	cin >> temp->number;
    	cout << "Enter e-mail Address: ";
    	cin >> temp->email;
    	temp-> next = head->next;
    	
    	head = temp;
    }
    
    else{
    	
    	//Gets the position of the selected contact on the list
    	for (int i=1 ; i<pos ; i++){
            temp = temp->next;
        }
        
        cin.get(pause);
    	system("cls");
    	
    	next_node = temp->next;
    	//Updates contact data
        cout << "Enter First Name: ";
    	cin >> next_node->firstName;
    	cout << "Enter Last Name: ";
    	cin >> next_node->lastName;
    	cout << "Enter Phone Number: ";
    	cin >> next_node->number;
    	cout << "Enter e-mail Address: ";
    	cin >> next_node->email;
   	
    	temp = next_node;
	}
}

//Function to delete contacts
void deleteContact(){
    system("cls");
    display();
    int pos;
    NODE *next_node;
    temp = head;
    
    //Iterating methods are the same as editing
    if(head != NULL){
	    cout<<"Which contact would you like to delete?"<<endl;
	    cin>>pos;
	    pos = pos - 1; 
	}

    //Checks if list is empty
    if(head == NULL){
    	cin.get(pause);
    	system("cls");
        cout<<"Contact List Empty"<<endl;
    }

	//Invalid input check
    else if (pos > len || pos < 0){
    	cin.get(pause);
    	system("cls");
        cout<<"Invalid Position "<<endl;
    }
    
    //Deletes head
    else if(pos == 0 && head != NULL){
    	cin.get(pause);
    	system("cls");
        temp = head;
        head = head->next;
        delete temp;
        cout<<"Contact has been deleted "<<endl;
    }
    
   	//Deletes selected node
    else{
    	
        for (int i=1 ; i<pos ; i++){
            temp = temp->next;
        }
        
        cin.get(pause);
    	system("cls");
    	
        next_node = temp->next;
        temp->next = next_node->next;
        delete next_node;
        cout<<"Contact has been deleted "<<endl;
    }
}

//Function to display the menu
void menu ()
{
    cout << "1. Add contact" << endl;
    cout << "2. Display contact list" << endl;
    cout << "3. Search contact list" << endl;
    cout << "4. Delete contact" << endl;
    cout << "5. Edit contact" << endl;
    cout << "6. Exit" << endl;
    cout << "--------------------------" << endl;
}

