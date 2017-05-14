#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; ++a)
#define pb push_back

using namespace std;

/*
    Author: Ruy Brito
    30/04/17
    Statement:
        "Write a method to decide if two strings are anagrams or not."
*/

// Time Complexity: O(n), Space Complexity: O(1)
int cnt[256];

void go(string &s1, string &s2) {
    fr(i, 0, s1.size()) cnt[s1[i]]++;
    fr(i, 0, s2.size()) cnt[s2[i]]--;
    bool ans = true;
    fr(i, 0, 256) if (cnt[i]) ans = false;
    (ans) ? puts("YES") : puts("NO");
}

// Time Complexity: O(n*logn) -> sort and compare

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    go(s1, s2);
    return 0;
}