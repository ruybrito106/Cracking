#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; ++a)
#define pb push_back

using namespace std;

/*
    Author: Ruy Brito
    14/05/17
    Statement:
        "Given a string, write a function to check if it is a permutation of a palin-
drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation
is a rea rrangement of letters. The palindrome does not need to be limited to just dictionary words."
*/

int mark[30];

// Complexity:
// Time: O(n)
// Space: O(1)
bool solve(string str) {
    int odd = 0;
    fr(i, 0, str.size()) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            mark[str[i] - 'a']++;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            mark[str[i] - 'A']++;
        }
    }

    fr(i, 0, 30) if (mark[i]&1) ++odd;
    return odd <= 1;
}

int main() {
    string str;
    getline(cin, str);
    solve(str) ? puts("True") : puts("False");
    return 0;
}