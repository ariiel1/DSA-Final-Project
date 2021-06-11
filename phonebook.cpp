#include<iostream>
#include <stdlib.h>
#include <string>
#include "phonebook.h"
using namespace std;

void addContact(){
	cin.get(pause);
    system("cls");
    newNode = new NODE;
    cout << "Enter First Name: ";
    cin >> newNode->firstName;
    cout << "Enter Last Name: ";
    cin >> newNode->lastName;
    cout << "Enter Phone Number: ";
    cin >> newNode->number;
    cout << "Enter e-mail Address: ";
    cin >> newNode->email;
   
    
    if(head == NULL){
        head = newNode;
        temp = newNode;
    }
    else{
        temp->next= newNode;
        temp = newNode;
    }
}


void display(){
	cin.get(pause);
    system("cls");
    if(head == NULL)
    {
        cout<<"Contact List Empty"<<endl;
    }
    else
    {
        NODE *search = head ;
        while (search != NULL)
        {
        	cout << "   " << len+1;
            cout << "    |First Name: " << search->firstName << endl;
            cout << "        |Last Name: " << search->lastName << endl;
            cout << "        |Phone Number: " << search->number << endl;
            cout << "        |e-mail Address: " << search->email << endl;
            cout << "----------------------------" << endl;
            search = search->next;
            len++;
        }      
    }
}


void searchContact(){
	cin.get(pause);
	system("cls");
	NODE *search = head;
	string searchString;
	bool found = false;
	
	if(head == NULL){
		cout << "Contact List Empty" << endl;
	}
	
	while(head != NULL && found == false){
		cout << "1. Search by First Name" << endl;
        cout << "2. Search by Last Name" << endl;
        cout << "3. Search by Phone Number" << endl;
        cout << "4. Search by e-mail Address" << endl;
        cout << "--------------------------------" << endl;
        
        int option;
        cin>>option;
        switch(option){
        	case 1:
        		system("cls");
        		cout << "Search First Name: ";
        		cin >> searchString;
        		while(search != NULL && found == false){
        			if(searchString == search->firstName){
        				cin.get(pause);
        				system("cls");
        				cout << "First Name: " << search->firstName << endl;
        				cout << "Last Name: " << search->lastName << endl;
        				cout << "Phone Number: " << search->number << endl;
						cout << "e-mail Address: " << search->email << endl;	
        				cout << "\nPress Enter to Continue..." << endl;
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
	        	
	        case 2:
        		system("cls");
        		cout << "Search Last Name: ";
        		cin >> searchString;
        		while(search != NULL && found == false){
        			if(searchString == search->lastName){
        				cin.get(pause);
        				system("cls");
        				cout << "First Name: " << search->firstName << endl;
        				cout << "Last Name: " << search->lastName << endl;
        				cout << "Phone Number: " << search->number << endl;
						cout << "e-mail Address: " << search->email << endl;	
        				cout << "\nPress Enter to Continue..." << endl;
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
	        	
	        case 3:
        		system("cls");
        		cout << "Search Phone Number: ";
        		cin >> searchString;
        		while(search != NULL && found == false){
        			if(searchString == search->number){
        				cin.get(pause);
        				system("cls");
        				cout << "First Name: " << search->firstName << endl;
        				cout << "Last Name: " << search->lastName << endl;
        				cout << "Phone Number: " << search->number << endl;	
        				cout << "e-mail Address: " << search->email << endl;
        				cout << "\nPress Enter to Continue..." << endl;
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
	        
	        case 4:
        		system("cls");
        		cout << "Search e-mail Address: ";
        		cin >> searchString;
        		while(search != NULL && found == false){
        			if(searchString == search->email){
        				cin.get(pause);
        				system("cls");
        				cout << "First Name: " << search->firstName << endl;
        				cout << "Last Name: " << search->lastName << endl;
        				cout << "Phone Number: " << search->number << endl;	
        				cout << "e-mail Address: " << search->email << endl;
        				cout << "\nPress Enter to Continue..." << endl;
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
	


void deleteContact(){
    system("cls");
    display();
    int pos;
    NODE *next_node;
    temp = head;
    
    if(head != NULL){
	    cout<<"Which contact would you like to delete?"<<endl;
	    cin>>pos;
	    pos = pos - 1;
	}

    
    if(head == NULL){
    	cin.get(pause);
    	system("cls");
        cout<<"Contact List Empty"<<endl;
    }

    else if (pos > len || pos < 0){
    	cin.get(pause);
    	system("cls");
        cout<<"Invalid Position "<<endl;
    }
    
    else if(pos == 0 && head != NULL){
    	cin.get(pause);
    	system("cls");
        temp = head;
        head = head->next;
        delete temp;
        cout<<"Contact has been deleted "<<endl;
    }
    
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

void menu ()
{
    cout << "1. Add contact" << endl;
    cout << "2. Display contact list" << endl;
    cout << "3. Search contact list" << endl;
    cout << "4. Delete contact" << endl;
    cout << "5. Exit" << endl;
    cout << "--------------------------" << endl;
}













