#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; ++a)
#define pb push_back

using namespace std;

/*
    Author: Ruy Brito
    14/05/17
    Statement:
        "There are three types of edits that can be performed on strings: insert a character,
remove a character, or replace a character. Given two strings, write a function to check if they are
one edit (or zero edits) away."
*/

// Complexity: O(n)
int main() {
    string a, b;
    cin >> a >> b;
    bool ans = false;
    int diff = 0;
    if (a.size() == b.size()) {
        fr(i, 0, a.size()) if (a[i] != b[i]) ++diff;
        if (diff <= 1)
            ans = true;
    } else if (a.size() - b.size() == 1) {
        for(int i = 0, j = 0; i < a.size(); i++, j++) if (a[i] != b[j]) j++, diff++;
        if (diff <= 1)
            ans = true;
    } else if (b.size() - a.size() == 1) {
        for(int i = 0, j = 0; i < b.size(); i++, j++) if (b[i] != a[j]) j++, diff++;
        if (diff <= 1)
            ans = true;
    } else ans = false;
    ans ? puts("True") : puts("False");
    return 0;
}