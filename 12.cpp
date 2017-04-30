#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; ++a)
#define pb push_back

using namespace std;

/*
    Author: Ruy Brito
    30/04/17
    Statement:
        "Write code to reverse a C-Style String. (C-String means that “abcd” is represented as
five characters, including the null character.)"
*/

// Complexity: O(n)
void rev(string &str) {
    int sz = str.size();
    fr(i, 0, sz>>1) swap(str[i], str[sz - i - 1]);;
}

int main() {
    string str;
    cin >> str;
    rev(str);
    cout << str << endl;
    return 0;
}