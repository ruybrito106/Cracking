#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; ++a)
#define pb push_back

using namespace std;

/*
    Author: Ruy Brito
    30/04/17
    Statement:
        "Design an algorithm and write code to remove the duplicate characters in a string
without using any additional buffer. NOTE: One or two additional variables are fine.
An extra copy of the array is not.
FOLLOW UP
Write the test cases for this method"
*/

// Complexity: O(n)
void proc(string &str) {
    int j = 0;
    fr(i, 1, str.size()) {
        if (str[i] != str[j]) str[j+1] = str[i], j++;
    }
    str.resize(j+1);
}

int main() {
    string str, ans;
    cin >> str;
    proc(str);
    cout << str << endl;
    return 0;
}