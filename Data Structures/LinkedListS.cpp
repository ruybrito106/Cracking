#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; ++a)
#define pb push_back

using namespace std;

/*
    Author: Ruy Brito
    30/04/17
    INCOMPLETE
    Data Structure: Single LinkedList
*/

class Node {
    int data;
    Node *nxt;

    public:
        Node() {};
        void set_data(int val) { data = val; };
        void set_next(Node *n) { nxt = n; };
        int data() { return data; };
        Node *next() { return nxt; };
};

class List {
    Node *head;

    public:
        List() { head = NULL; };
        void Append(int data) {
            Node *n = head;
            while (n->nxt != NULL) n = n->nxt;
            Node *node = new Node();
            node->data = data;
            node.set_next(NULL);
            n.set_next(node);
        };

        void Delete(int data) {
            Node *tmp = head;
            Node *prev;
            if (tmp == NULL) return;
            if (tmp->nxt == NULL) {
                delete tmp;
                head = NULL;
            } else {
                do {
                    if (tmp.data() == data) break;
                    prev = tmp;
                    tmp = tmp->next();
                } while (tmp != NULL);
            }

            prev->set_next(tmp->nxt);
            delete tmp;
        };
};