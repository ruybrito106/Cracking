#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; ++a)
#define pb push_back

using namespace std;

/*
    Author: Ruy Brito
    DONE
    23/05/17
    Statement:
        "Implement an algorithm to find the kth to last element of a singly linked list."
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
                while (tmp->getNext() != NULL) 
                    if ((tmp->getNext())->getVal() == v) { 
                        tmp->setNext((tmp->getNext())->getNext());
                        break;
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

int kth(List *l, int k) {
    int sz = 0;
    Node *n = l->getHead();
    while (n != NULL) sz++, n = n->getNext();
    sz -= k;
    n = l->getHead();
    while (--sz) n = n->getNext();
    return n->getVal();
}

int main() {
    int n, v;
    cin >> n;
    List *l = new List();

    fr(i, 0, n) {
        cin >> v;
        l->appendTail(new Node(v));
    }

    int m, k;
    cin >> m;
    while (m--) {
        cin >> k;
        cout << kth(l, k) << endl;
    }

    return 0;
}