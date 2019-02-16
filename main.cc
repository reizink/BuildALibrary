/********************************************
    This is the application program for CS2401 Project 1.
    It offers the user a menu from which they can select 
    different options that are available in the Library
    Class which you have written.
    Note that when entering a book title or author for 
    searching it must be entered exactly as it appears in 
    the database, although spaces are allowed for both.
	January 2017		Prof. John Dolan
		Ohio University EECS
***************************************************/

/* used by: Reilly Zink
project 1
1/25/17
My Library */

#include <iostream>
#include <string>
#include <fstream>
#include "book.h"
#include "library.h"

int menu();
using namespace std;
int main(){

    Library mybooks;
    Book tmp;
    string tmpstring;
    int choice;
    ifstream ifs;
    ofstream ofs;
// The load and save functions should probably be some of the last stuff
// that you do on this project

    ifs.open("shelf.txt");
    // load existing library
    // if the file does not exist it means this the first
    // use of the software
    if(!ifs.fail()){
		mybooks.load(ifs);
		ifs.close();
	}

    // start the user interaction menu
    do{
	choice = menu();
	switch(choice){	
	    case 1:
		cin>>tmp; 
		mybooks.addbook(tmp);
		break;
	    case 2:
		mybooks.showall(cout);
		break;
// Move the comment markers as you develop each function
	    case 3:
		cout<<"Currently there are ";
		cout<<mybooks.size();
		cout<<" books in your library.\n";
		break;
	    case 4:
		cout<<"There are "<<mybooks.numpages();
		cout<<" total pages in your library.\n";
		break;
	    case 5:
		mybooks.sort_by_date();
		break;
	    case 6:
		mybooks.sort_by_title();
		break;
	    case 7:
		cout<<"Enter the title of the book:\n";
		if(cin.peek() == '\n')
		    cin.ignore();
		getline(cin,tmpstring);
		mybooks.find_title(tmpstring);
		break;
	    case 8:
		cout<<"Enter the author's full name:\n";
		if(cin.peek() == '\n')
		    cin.ignore();
		getline(cin,tmpstring);
		mybooks.find_author(tmpstring);
		break;
	    case 9:
		cout<<"Enter title to remove:\n";
		if(cin.peek() == '\n')
                    cin.ignore();
                getline(cin,tmpstring);
		mybooks.remove(tmpstring);
		break; ////added
	    case 0:
		cout<<"Leaving your library now.\n";
		break;
	    default:
		cout<<"Not a valid option.\n";
		break;
	} // bottom of the switch
    }while(choice != 0);
    // Now saving the library

    ofs.open("shelf.txt");
    mybooks.save(ofs);
    ofs.close();


return 0;
}

// The menu function which returns the user's choice
int menu() {
    int choice;
    cout<<"Please chose from the following options:\n";
    cout<<"1) Add a book to the library\n";
    cout<<"2) See all your books\n";
    cout<<"3) See how many books are in your library \n";
    cout<<"4) See total number of pages in your library \n";
    cout<<"5) Sort books by copyright date \n";
    cout<<"6) Sort books by title \n";
    cout<<"7) Find information about a book \n";
    cout<<"8) See all books by a particular author \n";
    cout<<"9) Remove a book by entering its title \n";
    cout<<"0) Quit \n";

    cin>>choice;
return choice;
}
