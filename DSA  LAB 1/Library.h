#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

class Publication {
public:
    virtual void display() = 0;
};

class Book : public Publication {
private:
    string title;
    string author;
    int pages;

public:
    Book() {}

    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    string getTitle() { return title; }
    int getPages() { return pages; }

    void display() override {
        cout << "Book: " << title
            << ", Author: " << author
            << ", Pages: " << pages << endl;
    }
};

class Newspaper : public Publication {
private:
    string name;
    string date;
    string edition;

public:
    Newspaper() {}

    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }

    string getName() { return name; }
    string getEdition() { return edition; }

    void display() override {
        cout << "Newspaper: " << name
            << ", Date: " << date
            << ", Edition: " << edition << endl;
    }
};

// Library class
class Library {
private:
    Book books[10];
    Newspaper newspapers[10];
    int bookCount = 0;
    int newspaperCount = 0;

public:
    void addBook(Book b) {
        books[bookCount++] = b;
    }

    void addNewspaper(Newspaper n) {
        newspapers[newspaperCount++] = n;
    }

    void displayCollection() {
        cout << "\nBooks:\n";
        for (int i = 0; i < bookCount; i++)
            books[i].display();

        cout << "\nNewspapers:\n";
        for (int i = 0; i < newspaperCount; i++)
            newspapers[i].display();
    }

    
    void sortBooksByTitle() {
        for (int i = 0; i < bookCount - 1; i++) {
            int smallIndex = i;
            for (int j = i + 1; j < bookCount; j++) {
                if (books[j].getTitle() < books[smallIndex].getTitle()) {
                    smallIndex = j;
                }
            }
            if (smallIndex != i)
                swap(books[i], books[smallIndex]);
        }
    }

    void sortNewspapersByName() {
        for (int i = 0; i < newspaperCount - 1; i++) {
            int smallIndex = i;
            for (int j = i + 1; j < newspaperCount; j++) {
                if (newspapers[j].getName() < newspapers[smallIndex].getName()) {
                    smallIndex = j;
                }
            }
            if (smallIndex != i)
                swap(newspapers[i], newspapers[smallIndex]);
        }
    }

   
    Book* searchBookByTitle(string title) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == title)
                return &books[i];
        }
        return nullptr;
    }

    Newspaper* searchNewspaperByName(string name) {
        for (int i = 0; i < newspaperCount; i++) {
            if (newspapers[i].getName() == name)
                return &newspapers[i];
        }
        return nullptr;
    }
};
