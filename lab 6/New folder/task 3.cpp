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

    void put(int v, int pos);
    void swap(int xi, int yi);
    void sort(bool asc);
};

// PUT
void myLinkedList::put(int v, int pos)
{
    Node* nn = new Node;
    nn->data = v;

    if (pos <= 0 || first == nullptr)
    {
        nn->next = first;
        first = nn;
        return;
    }

    Node* t = first;
    int i = 0;

    while (t->next != nullptr && i < pos - 1)
    {
        t = t->next;
        i++;
    }

    nn->next = t->next;
    t->next = nn;
}

// SWAP
void myLinkedList::swap(int xi, int yi)
{
    if (xi == yi) return;

    Node* a = first;
    Node* b = first;

    for (int i = 0; i < xi && a; i++)
        a = a->next;

    for (int i = 0; i < yi && b; i++)
        b = b->next;

    if (a && b)
    {
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }
}

// SORT
void myLinkedList::sort(bool asc)
{
    for (Node* i = first; i != nullptr; i = i->next)
    {
        for (Node* j = i->next; j != nullptr; j = j->next)
        {
            if (asc ? i->data > j->data : i->data < j->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// MAIN
int main()
{
    myLinkedList l;

    l.insertAtLast(50);
    l.insertAtLast(10);
    l.insertAtLast(30);
    l.insertAtLast(20);

    cout << "Original: ";
    l.display();

    l.put(99, 2);
    cout << "Put: ";
    l.display();

    l.swap(1, 3);
    cout << "Swap: ";
    l.display();

    l.sort(true);
    cout << "Asc: ";
    l.display();

    l.sort(false);
    cout << "Desc: ";
    l.display();
}