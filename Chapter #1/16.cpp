#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; ++a)
#define pb push_back

using namespace std;

/*
    Author: Ruy Brito
    14/05/17
    Statement:
        "Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the
"compressed" string would not become smaller than the original string, your method should return
the original string. You can assume the string has only uppercase and lowercase letters (a - z)."
*/

// Complexity: O(n)
int main() {
    string str;
    cin >> str;
    string ret;
    int cnt = 1;
    fr(i, 1, str.size()) {
        if (str[i] == str[i - 1]) ++cnt;
        else {
            ret.pb(str[i - 1]);
            ret.append(to_string(cnt));
            cnt = 1;
        }
    }
    if (cnt != 0) {
        ret.pb(str[str.size()-1]);
        ret.append(to_string(cnt));
    }
    if (str.size() <= ret.size()) cout << str << endl;
    else cout << ret << endl;
    return 0;
}