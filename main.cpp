#include <iostream>
#include "list.cpp"

using namespace std;

int main(int argc, char** argv)
{
    List* list = new List();

    cout << "Size of list: " << list->size() << endl;

    list->add(1);
    cout << "Size of list: " << list->size() << endl;
    list->print();

    list->add(2);
    cout << "Size of list: " << list->size() << endl;
    list->print();

    list->add(3);
    cout << "Size of list: " << list->size() << endl;
    list->print();

    Node* val = list->find(3);
    if (val == 0) {
        cout << "Unable to find value" << endl;
    } else {
        cout << "Located " << val->x << endl;
    }

    val = list->find(4);
    if (val == 0) {
        cout << "Unable to find value" << endl;
    } else {
        cout << "Located " << val->x << endl;
    }

    list->reverse();
    list->print();

    list->remove(2);
    cout << "Size of list: " << list->size() << endl;
    list->print();

    list->remove(1);
    cout << "Size of list: " << list->size() << endl;
    list->print();

    list->remove(3);
    cout << "Size of list: " << list->size() << endl;
    list->print();

    delete list;
}

/*
    Node* root;
    Node* conductor;

    root = new Node;
    root->x = 1;
    root->next = 0;

    conductor = root;
    if (conductor != 0) {
        while (conductor->next != 0) {
            conductor = conductor->next;
        }
    }
    
    conductor->next = new Node;
    conductor = conductor->next;
    conductor->next = 0;
    conductor->x = 5;
*/
