#include<iostream>
using namespace std;
#include "Library.h"

int main() {

    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");
    
   
    Library library;

    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "All library details:\n";
    library.displayCollection();
 
    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
        cout << endl;
    }
    else{
        cout << "not found " << endl;
    }

    Newspaper* foundNewspaper = library.searchNewspaperByName(" Times");
    if (foundNewspaper) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
       
    }
    else {
        cout << "Newspaper : \n" << " not found " << endl;
    }

}