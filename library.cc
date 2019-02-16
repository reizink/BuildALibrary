/* Reilly Zink
project 1
1/25/17
My Library function definitions
manipulates books*/

#include"library.h"
#include"book.h"
using namespace std;


Library::Library(){
	used = 0;
}

void Library::addbook(Book b1){
	if(used < SIZE){
		data[used] = b1;
		used++;
	}
	else{
		cout<<"Error. List capacity has been reached.\n";
	}
}

void Library::load(istream& ins){ 
    used = 0;
    ins >> data[used];
    while(!ins.eof()){
    used++;
	ins >> data[used];
	}
}

void Library::save(ostream& outs){ 
	for(size_t i=0; i<used; i++)
		outs << data[i]; //endl to separate books at the end
}

void Library::showall(std::ostream& outs)const{
	if(used == 0)
	    outs<<"Empty list.\n";
	else
	    for(size_t i = 0; i<used; i++)
		outs<<data[i]<<endl;
}

int Library::numpages()const{
    int tmp=0;
    for(size_t i=0; i < used; i++)
    {
        tmp += data[i].get_pages();
    }

    return tmp;
}
	
void Library::sort_by_title(){
    bool done = false;
    int j;
    Book tmp;
    while(!done){
	done = true;
	for(j=used-1; j> 0; j--){
	    if(data[j].get_title() < data[j-1].get_title()){
		tmp = data[j];
		data[j] = data[j-1];
		data[j-1] = tmp;
		done = false;
	    }
	}
    }
}

void Library::sort_by_date(){
    bool done = false;
    int j;
    Book tmp;
    while(!done){
	done = true;
	for(j=used-1; j> 0; j--){
	    if(data[j].get_copyright() < data[j-1].get_copyright()){
		tmp = data[j];
		data[j] = data[j-1];
		data[j-1] = tmp;
		done = false;
	    }
	}
    }
}

void Library::find_title(const std::string& target){
    for(size_t i=0; i<used; i++)
    {
        if(data[i].get_title() == target)
        {
            cout << data[i] << endl;
        }
    }
}

void Library::find_author(const std::string& target){
    for(size_t i=0; i<used; i++)
    {
        if(data[i].get_author() == target)
        {
            cout << data[i] << endl;
        }
    }
}

void Library::remove(const std::string& target){
    for(size_t i=0; i<used; i++)
    {
        if(data[i].get_title() == target)
        {
            for(size_t j=i; j<used-1; j++)
            {
                data[j]=data[j+1];
            }
        }
    }
    used--;
}

/*std::istream& operator >>(std::istream& ins, Book& b1){
    
    while(ins.peek()=='\n') {cin.ignore();}
    getline(ins, b1.title, '\n');
    getline(ins, b1.author, '\n');
	ins >> b1.year;
    ins >> b1.pages;
    return ins;
}

std::ostream& operator <<(std::ostream& outs, const Book& b1){
    outs << b1.title << endl;
    outs << b1.author << endl;
    outs << b1.year << endl;
    outs << b1.pages << endl;
    return outs;
}*/
