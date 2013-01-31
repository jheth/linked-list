#include <iostream>

using namespace std;

struct Node {
    int x;
    Node* next;
};

class List {
public: 
    List()
    {
        this->root = 0;
        this->last = 0;
        this->nSize = 0;
    }

    ~List()
    {
        Node* cur = 0;
        while (this->root != 0) {
            cur = this->root;
            this->root = this->root->next;
            delete cur;
        }
    }

    void add(int value)
    {
        if (this->root == 0) {
            this->root = this->createNode(value);
            this->last = this->root;
        } else {
            this->last->next = this->createNode(value);
            this->last = this->last->next;
        }
        this->nSize++;
    }

    Node* remove(int value)
    {
        Node* cur = this->root;
        Node* prev = 0;
        while (cur != 0) {
            if (cur->x == value) {
                break;
            }
            prev = cur;
            cur = cur->next;
        }

        if (cur == 0) {
            return 0;
        }

        // 1 -> 2 -> 3
        // if we're removing the fist element then move root.
        if (root == cur) {
            root = cur->next;
        // any other position we point to the next one.
        } else {
            prev->next = cur->next;
        }
        
        if (this->nSize > 0) {
            this->nSize--;
        }
        return cur;
    }

    Node* find(int value)
    {
        Node* tmp = this->root;
        while (tmp != 0) {
            if (tmp->x == value) {
                break;
            }
            tmp = tmp->next;
        }

        return tmp;
    }

    // 1 -> 2 -> 3
    // becomes
    // 3 -> 2 -> 1
    void reverse()
    {
        Node* cur = this->root;
        Node* prev = 0;
        while (cur != 0) {
            Node* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        this->root = prev;
    }

    int size()
    {
        return this->nSize;
    }

    void print()
    {
        if (root == 0) {
            cout << "List is Empty" << endl;
            return;
        }

        Node* tmp = this->root;
        while (tmp != 0) {
            cout << "|  " << tmp->x << "  |  -->  ";
            tmp = tmp->next;
        }
        cout << "END" << endl;
    }
private:

    Node* createNode(int value)
    {
        Node* t = new Node;
        t->x = value;
        t->next = 0;
        return t;
    }

private:
    Node* last;
    Node* root;
    int nSize;
};


