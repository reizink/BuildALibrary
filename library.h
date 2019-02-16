/* Reilly Zink
project 1
1/25/17
My Library 
header*/

#include<iostream>
#include<string>
#include"book.h"
#ifndef LIBRARY_H
#define LIBRARY_H
class Library{
    public:
    Library();
	static const std::size_t SIZE = 200;
    void addbook(Book b1);
    size_t size()const {return used;}
	void load(std::istream& ins);
	void save(std::ostream& outs);

    void find_title(const std::string& target); 
    void find_author(const std::string& target);
    void remove(const std::string& target);
    void sort_by_title();
    void sort_by_date();
    void showall(std::ostream& outs)const;
    int numpages()const;

    private:
	Book data[SIZE];
    std::size_t used;
};


// Non-member overload extraction and insertion operators
//std::istream& operator >>(std::istream& ins, Book& b1);
//std::ostream& operator <<(std::ostream& outs, const Book& b1);

#endif