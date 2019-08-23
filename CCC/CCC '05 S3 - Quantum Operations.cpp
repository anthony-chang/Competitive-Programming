#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int arr[1030][1030];
int tensorr[1030][1030];
int rowss[1030], colss[1030];
int temp[1030][1030];
int NN;


int main() {
    tensorr[0][0] = 1;
    scanf("%d", &NN);
    int rr = 1, cc = 1;
    for(int k = 0, r, c; k < NN; k++) {
        scanf("%d%d", &r, &c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%d", &temp[i][j]);
            }
        }
        for (int i = 0; i < r * rr; i++)
            for (int j = 0; j < c * cc; j++)
                arr[i][j] = tensorr[i%rr][j%cc] * temp[i/rr][j/cc];
        rr *= r;
        cc *= c;
        for (int i = 0; i < rr; i++)
            for (int j = 0; j < cc; j++)
                tensorr[i][j] = arr[i][j];
    }
    int minn = 999999999, maxx = -999999999;
    int minRow = 999999999, maxRow = -999999999;
    int minCol = 999999999, maxCol = -999999999;
    for (int i = 0; i < rr; i++)
        for (int j = 0; j < cc; j++) {
            rowss[i] += tensorr[i][j];
            colss[j] += tensorr[i][j];
            minn = min(minn, tensorr[i][j]);
            maxx = max(maxx, tensorr[i][j]);
        }
    for (int i = 0; i < rr; i++) {
        minRow = min(minRow, rowss[i]);
        maxRow = max(maxRow, rowss[i]);
    }
    for (int i = 0; i < cc; i++) {
        minCol = min(minCol, colss[i]);
        maxCol = max(maxCol, colss[i]);
    }
    printf("%d\n%d\n%d\n%d\n%d\n%d\n", maxx, minn, maxRow, minRow, maxCol, minCol);


    return 0;
}