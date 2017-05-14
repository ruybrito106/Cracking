#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; ++a)
#define pb push_back

using namespace std;

/*
    Author: Ruy Brito
    INCOMPLETE
    30/04/17
    Statement:
        "Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?"
*/

const int N = 4;

char mat[N][N];

void rotate() {
    int aux = N;
    aux >>= 1;
    int val, a, b, cnt = 0, fix;
    fr(i, 0, aux) fr(j, 0, aux) {
        a = i, b = j;
        cnt = 0;
        val = mat[a][b];
        while (cnt < 4) {
            fix = val;
            a = b;
            b = N - a - 1;
            val = mat[a][b];
            mat[a][b] = fix;
            ++cnt;
        }
    }
}

int main() {
    fr(i, 0, N) {
        fr(j, 0, N) scanf(" %c", &mat[i][j]);
    }
    rotate();
    fr(i, 0, N) {
        fr(j, 0, N) cout << mat[i][j] << ' ';
        cout << endl;
    }
    return 0;
}