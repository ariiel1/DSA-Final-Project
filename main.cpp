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
	        case 1:
	            addContact();
	            system("cls");
	            break;
	        case 2:
	            display();
	            cin.get(pause);
	            system("cls");
	            len = 0;
	            break;
	        case 3:
	            searchContact();
	            cin.get(pause);
	    		system("cls");
	            break;
	        case 4:
	            deleteContact();
	            cin.get(pause);
	    		system("cls");
	    		len = 0;
	            break;
	        case 5:
	            exit(1);
	            break;
	        default:
	            cout<<"Invalid Option"<<endl;
        }
    }
}
