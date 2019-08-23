#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int M, N, K;
int arr[30002][1002];
int main() {
    scanf("%d%d%d", &M, &N, &K);
    for (int ii = 0; ii < K; ii++) {
        int x, y, r, b;
        scanf("%d%d%d%d", &x, &y, &r, &b);
        for (int i = max(1, x-r); i <= min (N, x+r); i++) {
            int d = static_cast<int>(sqrt(pow(r, 2) - pow(i-x, 2)));
            arr[max(1, y-d)][i] += b;
            arr[min(M, y+d)+1][i] -= b;
        }
    }
    int maxx = -1, cnt = 0;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j<=N; j++) {
            arr[i][j] += arr[i-1][j];
            if (arr[i][j] > maxx) {
                maxx = arr[i][j];
                cnt = 1;
            }
            else if (arr[i][j] == maxx)
                cnt++;
        }
    printf("%d\n%d", maxx, cnt);
    return 0;
}