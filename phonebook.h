#include<iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct NODE{
   string firstName;
   string lastName;
   string number;
   string email;
   NODE *next;
};

NODE *head = NULL;
NODE *newNode = NULL;
NODE *temp;
int len = 0;
char pause;

void addContact ();
void display ();
void searchContact ();
void deleteContact ();
void menu ();

