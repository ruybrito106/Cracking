#include <bits/stdc++.h>

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
