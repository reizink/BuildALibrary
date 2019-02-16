/* Reilly Zink
project 1
1/25/17
My Library book function definitions
input, output, acessing book info. */

#include"book.h"
using namespace std;

Book::Book(){
    title = "N/A";
    author = "N/A";
    year = 0;
    pages = 0;
}

void Book::input(std::istream& ins){
    while(ins.peek()=='\n'||ins.peek()=='\r') {ins.ignore();}
    getline(ins, title);
    /*pos = title.find("Title: ");
    if(pos != -1)
        line.erase(pos, 7);*/
    getline(ins, author);
	ins >> year;
    ins >> pages;
}

void Book::output(std::ostream& outs)const{
    outs << title << endl;
    outs << author << endl;
    outs << year << endl;
    outs << pages << endl;
    
    /*outs << "Title: " << title << endl;  ///this output doesn't allow for re-loading
    outs << "Author: " << author << endl;
    outs << "Copyright Year: " << year << endl;
    outs << "# of pages: " << pages << endl;*/
}
	// Acessors
std::string Book::get_title()const{
    return title;
}

std::string Book::get_author()const{
    return author;
}

int Book::get_copyright()const{
    return year;
}

int Book::get_pages()const{
    return pages;
}

std::istream& operator >>(std::istream& ins, Book& b1){
    b1.input(ins);
	return ins;
}
std::ostream& operator <<(std::ostream& outs, const Book& b1){
    b1.output(outs);
	return outs;
}
