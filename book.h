/********************************************************
	This is a little class which stores essential information about 
	a single book. This information is the Title, Author, 
	Copyright year and number of pages. The class has accessor 
	functions for each of these variables as well as input and 
	output functions that are called by the overloaded >> and << functions.
		John Dolan	Ohio University	  January 2016
*****************************************************************/

/* used by: Reilly Zink
project 1
1/25/17
My Library 
header */

#include<iostream>
#include<string>
#ifndef BOOK_H
#define BOOK_H
class Book{
    public:
	Book();
	void input(std::istream& ins);
	void output(std::ostream& outs)const;
	// Acessors
	std::string get_title()const;
	std::string get_author()const;
	int get_copyright()const;
	int get_pages()const;
    private:
	std::string title;
	std::string author;
	int year;
	int pages;
};


// Non-member overload extraction and insertion operators
std::istream& operator >>(std::istream& ins, Book& b1);
std::ostream& operator <<(std::ostream& outs, const Book& b1);

#endif
