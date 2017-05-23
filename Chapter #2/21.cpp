#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; ++a)
#define pb push_back

using namespace std;

/*
    Author: Ruy Brito
    INCOMPLETE
    23/05/17
    Statement:
        "Write code to remove duplicates from an unsorted linked list."
*/

class Node {

    private:
        Node *next;
        int val;

    public:
        Node(int v) {
            next = NULL;
            val = v;
        }
        Node* getNext() { return next; }
        int getVal() { return val; }
        void setNext(Node *n) { next = n; }
        void setVal(int v) { val = v; }
};

class List {

    private:
        Node *head;

    public:
        List() { head = NULL; }

        Node *getHead() { return head; }
        void setHead(Node *h) { head = h; } 
        void appendTail(Node *n) {
            if (head == NULL) {
                head = n;
                head->setNext(NULL);
            } else {
                Node *tmp = head;
                while (tmp->getNext() != NULL) tmp = tmp->getNext();
                tmp->setNext(n);
                n->setNext(NULL);
            }
        }

        void deleteVal(int v) {
            if (head->getVal() == v) head = head->getNext();
            else {
                Node *tmp = head;
                while (tmp->getNext() != NULL) {
                    if ((tmp->getNext())->getVal() == v) { 
                        tmp->setNext((tmp->getNext())->getNext());
                        break;
                    }
                    tmp = tmp->getNext();
                }
            }
        }

        void print() {
            Node *tmp = head;
            while (tmp->getNext() != NULL) {
                cout << (tmp->getVal()) << " -> ";
                tmp = tmp->getNext();
            }
            cout << (tmp->getVal()) << " -> NULL" << endl;
        }
};

List *remDuplicates(List *l) {
    Node *tmp = l->getHead();

    map<int, int> m;
    m[tmp->getVal()]++;
    while (tmp->getNext() != NULL) {
        tmp = tmp->getNext();
        m[tmp->getVal()]++;
    }

    if (m[(l->getHead())->getVal()] > 1) {
        l->setHead((l->getHead())->getNext());
        m[(l->getHead())->getVal()]--;
    }

    tmp = l->getHead();
    while (tmp->getNext() != NULL) {
        if (m[(tmp->getNext())->getVal()] > 1) { 
            m[(tmp->getNext())->getVal()]--;
            tmp->setNext((tmp->getNext())->getNext());
        }
        tmp = tmp->getNext();
    }

    return l;
}

int main() {
    int n;
    char cm;
    int v;
    cin >> n;
    List *l = new List();
    fr(i, 0, n) {
        cin >> cm >> v;
        Node *n = new Node(v);
        if (cm == 'a') l->appendTail(n);
        else l->deleteVal(v);
    }

    l = remDuplicates(l);
    l->print();
    return 0;
}