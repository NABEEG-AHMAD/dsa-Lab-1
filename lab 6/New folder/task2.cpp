#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
protected:
    Node* first;
    Node* last;

public:
    LinkedList() {
        first = nullptr;
        last = nullptr;
    }
};

class myLinkedList : public LinkedList
{
public:
    void insertAtLast(int value)
    {
        Node* nn = new Node;
        nn->data = value;
        nn->next = nullptr;

        if (first == nullptr)
            first = last = nn;
        else
        {
            last->next = nn;
            last = nn;
        }
    }

    void display()
    {
        Node* t = first;
        while (t != nullptr)
        {
            cout << t->data << " -> ";
            t = t->next;
        }
        cout << "NULL\n";
    }

    // REQUIRED FUNCTIONS
    int getSize();
    bool search(int v);
    int peek(int pos);
    int get(int pos);
};

// 1
int myLinkedList::getSize()
{
    int c = 0;
    Node* t = first;

    while (t != nullptr)
    {
        c++;
        t = t->next;
    }
    return c;
}

// 2
bool myLinkedList::search(int v)
{
    Node* t = first;

    while (t != nullptr)
    {
        if (t->data == v)
            return true;
        t = t->next;
    }
    return false;
}

// 3
int myLinkedList::peek(int pos)
{
    Node* t = first;
    int i = 0;

    while (t != nullptr)
    {
        if (i == pos)
            return t->data;

        t = t->next;
        i++;
    }

    return -99999;
}

// 4
int myLinkedList::get(int pos)
{
    if (pos == 0)
    {
        int val = first->data;
        Node* t = first;
        first = first->next;
        delete t;
        return val;
    }

    Node* t = first;
    Node* prev = nullptr;
    int i = 0;

    while (t != nullptr)
    {
        if (i == pos)
        {
            int val = t->data;
            prev->next = t->next;
            delete t;
            return val;
        }

        prev = t;
        t = t->next;
        i++;
    }

    return -99999;
}

// MAIN
int main()
{
    myLinkedList l;

    l.insertAtLast(10);
    l.insertAtLast(20);
    l.insertAtLast(30);
    l.insertAtLast(40);

    l.display();

    cout << "Size: " << l.getSize() << endl;
    cout << "Search 20: " << l.search(20) << endl;
    cout << "Peek 2: " << l.peek(2) << endl;
    cout << "Get 1: " << l.get(1) << endl;

    l.display();
}