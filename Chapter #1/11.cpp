#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; ++a)
#define pb push_back

using namespace std;

/*
    Author: Ruy Brito
    29/04/17
    Statement:
        "Implement an algorithm to determine if a string has all unique characters. What if you
can not use additional data structures?"
*/

string quicksort(string str) {
    if (str.size() <= 1) return str;
    char x = str[str.size()/2];
    string l, r;
    fr(i, 0, str.size())
        if (i != str.size()/2) {
            if (str[i] < x) l.pb(str[i]);
            else r.pb(str[i]);
        }
    return quicksort(l) + x + quicksort(r);
}

// Sort the string and verify if there are no neighbors equal
// O(n * logn)
void solve(string str) {
    string S = quicksort(str);
    bool ans = true;
    fr(i, 0, S.size()-1) if (S[i] == S[i+1]) ans = false;
    ans ? puts("YES") : puts("NO");
}

int main() {
    string str;
    cin >> str;
    solve(str);
    return 0;
}