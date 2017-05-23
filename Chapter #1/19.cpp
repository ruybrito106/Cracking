#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; ++a)
#define pb push_back

using namespace std;

/*
    Author: Ruy Brito
    DONE
    23/05/17
    Statement:
        "Assume you have a method isSubst ring which checks if one word is a substring
of another. Given two strings, 51 and 52, write code to check if 52 is a rotation of 51 using only one
call to isSubstring (e.g., "waterbottle" is a rotation of "erbottlewat")."
*/

bool isSubstring(string a, string b) {
    bool ans = false;
    for(int i = 0; i < a.size(); i++) {
        ans = ans || (a == b.substr(i, a.size()));
    }
    return ans;
}

// Complexity: time O(N), extra space O(N)
int main() {
    string a, b;
    cin >> a >> b;
    a.append(a);
    isSubstring(b, a) ? puts("y") : puts("n");
    return 0;
}