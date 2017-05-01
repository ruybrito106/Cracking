#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; ++a)
#define pb push_back

using namespace std;

/*
    Author: Ruy Brito
    30/04/17
    Algorithm: QuickSort
*/

vector<int> QuickSort(vector<int> &v) {
    int sz = v.size();
    if (sz <= 1) return v;
    int x = v[sz >> 1];
    vector<int> l, r, m;
    fr(i, 0, sz)
        if (i != (sz>>1)) {
            if (v[i] < x) l.pb(v[i]);
            else r.pb(v[i]);
        }
    l = QuickSort(l), r = QuickSort(r);
    m = l;
    m.pb(x);
    m.insert(m.end(), r.begin(), r.end());
    return m;
}

int main() {
    int n, a;
    cin >> n;
    vector<int> v;
    while (n--) cin >> a, v.pb(a);
    v = QuickSort(v);
    fr(i, 0, v.size()) cout << v[i] << ' ';
    cout << endl;
    return 0;
}