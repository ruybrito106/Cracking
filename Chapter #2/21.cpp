#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; ++a)
#define pb push_back

using namespace std;

/*
    Author: Ruy Brito
    DONE
    23/05/17
    Statement:
        "Write code to remove duplicates from an unsorted linked list."
*/

unordered_map<int, int> m;

void mark(Node *n) {
    while (n != NULL) {
        m[n->getVal()]++;
        n = n->getNext();
    }
}

List *remDuplicates(List *l) {
    mark(l->getHead());

    Node *tmp = l->getHead();
    while (tmp != NULL && m[tmp->getVal()] > 1) {
        m[tmp->getVal()]--;
        l->setHead(tmp->getNext());
        tmp = l->getHead();
    }

    while (tmp->getNext() != NULL) {
        if (m[(tmp->getNext())->getVal()] > 1) {
            m[(tmp->getNext())->getVal()]--;
            tmp->setNext(tmp->getNext()->getNext());
        }
        tmp = tmp->getNext();
        if (tmp == NULL) {
            break;
        }
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