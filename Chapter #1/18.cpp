#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; ++a)
#define pb push_back

using namespace std;

/*
    Author: Ruy Brito
    DONE
    23/05/17
    Statement:
        "Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
column are set to O"
*/

// Complexity: time O(N * M), extra space O(1)
int main() {
    int n, m;
    cin >> n >> m;
    int mat[n][m];
    int a;
    fr(i, 0, n) fr(j, 0, m) {
        scanf("%d", &mat[i][j]);
        if (!mat[i][j]) mat[0][j] = mat[i][0] = 0;
    }
    fr(i, 0, n) fr(j, 0, m) mat[i][j] = (!mat[i][0] || !mat[0][j]) ? 0 : mat[i][j];
    fr(i, 0, n) {
        fr(j, 0, m) cout << mat[i][j] << ' ';
        cout << endl;
    }
    return 0;
}