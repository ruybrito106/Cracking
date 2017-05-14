#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; ++a)
#define pb push_back

using namespace std;

/*
    Author: Ruy Brito
    30/04/17
    Statement:
        "Write a method to replace all spaces in a string with ‘%20’."
*/

// Complexity: O(n)
void solve(string &str) {
    int cnt = 0, j = str.size() - 1;
    fr(i, 0, str.size()) if (str[i] == ' ') ++cnt;
    str.resize(j + 1 + (cnt<<1));
    for(int i = str.size() - 1; i >= 0; i--) {
        if (str[j] == ' ') {
            str[i] = '0';
            str[i - 1] = '2';
            str[i - 2] = '%';
            i -= 2;
        } else str[i] = str[j];
        j--;
    }
}

int main() {
    string str;
    getline(cin, str);
    solve(str);
    cout << str << endl;
    return 0;
}