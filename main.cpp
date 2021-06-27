#include<iostream>
#include <stdlib.h>
#include <string>
#include "phonebook.cpp"
using namespace std;

int main (){
	
    int option;
    while (true){
        menu();
        cin>>option;
        
        switch (option){
        	//ADD CONTACT
	        case 1:
	            addContact();
	            system("cls");
	            break;
	        //DISPLAY CONTACT
	        case 2:
	            display();
	            cin.get(pause);
	            system("cls");
	            len = 0;
	            break;
	        //SEARCH CONTACT
	        case 3:
	            searchContact();
	            cin.get(pause);
	    		system("cls");
	            break;
	        //DELETE CONTACT
	        case 4:
	            deleteContact();
	            cin.get(pause);
	    		system("cls");
	    		len = 0;
	            break;
	        //EDIT CONTACT
	        case 5:
	        	editContact();
	            cin.get(pause);
	    		system("cls");
	    		len = 0;
	    		break;
	    	//EXIT
	        case 6:
	            exit(1);
	            break;
	        default:
	            cout<<"Invalid Option"<<endl;
        }
    }
}
