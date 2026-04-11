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

    // Copy Constructor
    LinkedList(const LinkedList& other)
    {
        first = last = nullptr;

        Node* t = other.first;

        while (t != nullptr)
        {
            Node* nn = new Node;
            nn->data = t->data;
            nn->next = nullptr;

            if (first == nullptr)
                first = last = nn;
            else
            {
                last->next = nn;
                last = nn;
            }

            t = t->next;
        }
    }

    // Destructor
    virtual ~LinkedList()
    {
        Node* t;

        while (first != nullptr)
        {
            t = first;
            first = first->next;
            delete t;
        }

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
};

// MAIN
int main()
{
    myLinkedList l1;

    l1.insertAtLast(10);
    l1.insertAtLast(20);
    l1.insertAtLast(30);

    cout << "Original List: ";
    l1.display();

    myLinkedList l2 = l1; // Copy Constructor test

    cout << "Copied List: ";
    l2.display();

    return 0;
}