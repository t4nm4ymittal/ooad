#include <iostream>
#include <string.h>
using namespace std;
class books // declaring a class
{
private:
char *title, *author, *publisher;
float price;
int stock;
public: // declaring functions
void getdata();
void display();
int search(char *, char *);
void buy();
books();
};
books::books() // default constructor
{
title = new char[50];
author = new char[50];
publisher = new char[10];
price = 0;
stock = 0;
}
void books::getdata() // getdata
{
cin.ignore();
cout << "\nEnter Author Name: ";
cin.getline(author, 50);
cout << "\nEnter Title: ";
cin.getline(title, 50);
cout << "\nEnter publisher: ";
cin.getline(publisher, 10);
cout << "\nEnter price: ";
cin >> price;
cout << "\nEnter stock: " << endl;
cout << "-----------------------------";
cin >> stock;
}
void books::display() // displaydata
{
cout << "\nAuthor Name: " << author;
cout << "\nTitle Name: " << title;
cout << "\nPublisher Name: " << publisher;
cout << "\nPrice: " << price;
cout << "\nStock available: " << stock << endl;
}
int books::search(char *title1, char *author1) // search
{
if (strcmp(title, title1) == 0 && strcmp(author, author1)
== 0)
return 1;
else
return 0;
}
void books::buy() // checking stock and displaying cost
{
int no_of_copies;
cout << "\nEnter no. of copies required:";
cin >> no_of_copies;
if (no_of_copies <= stock)
{
cout << "Number of entered copies is available" <<
endl;
cout << "\nPrice of " << no_of_copies << " books is :
RS." << no_of_copies * price;
cout << "\nThank you .... Visit again....";
}
else
{
cout << "\nRequired copies are not available...";
cout << "\nSorry for inconvinience...";
cout << "\nThank you .... Visit again....";
}
}
int main() // main
{
int val = 0;
int ch;
int n;
char a;
cout << "\nEnter no. of books :";
cin >> n;
cout << "\n";
books b[n];
char title1[50], author1[50];
for (int i = 0; i < n; i++)
{
cout << "Enter details of book" << i + 1;
b[i].getdata();
}
do
{
cout << "******MENU*****\n";
cout << "1.Display Data\n2.Search a Book\n3.Buy a
Book" << endl;
cout << "Enter your choice:";
cin >> ch;
switch (ch)
{
case 1:
for (int i = 0; i < n; i++)
{
cout << "---------------------------------\n";
cout << "Details of book " << i + 1 << " is
";
b[i].display();
}
break;
case 2:
// accepting book that customer wants to search
cout << "\nEnter following details to search a
book";
cout << "\nEnter Author Name: ";
cin.getline(author1, 50);
cout << "\nEnter Title: ";
cin.getline(title1, 50);
// searching if it is avaliable in shop
for (int i = 0; i < n; i++)
{
val = b[i].search(title1, author1);
if (val == 1)
{
cout << "\nBook is found";
}
}
if (val == 0)
cout << "\nBook is not available\n";
return 0;
break;
case 3:
// accepting book that customer wants to buy
cout << "\nEnter following details to search
whether the book is available";
cout << "\nEnter Author Name: ";
cin.getline(author1, 50);
cout << "\nEnter Title: ";
cin.getline(title1, 50);
// searching if it is available in shop and
proceeding to billing
for (int i = 0; i < n; i++)
{
val = b[i].search(title1, author1);
if (val == 1)
{
cout << "\nBook is found";
b[i].buy();
}
}
if (val == 0)
{
cout << "\nBook is not available";
} // return 0;
break;
}
cout << "Do you want to continue:(Yes-y or No-n)" <<
endl;
cin >> a;
} while (a == 'y' || a == 'Y');
return 0;
}
