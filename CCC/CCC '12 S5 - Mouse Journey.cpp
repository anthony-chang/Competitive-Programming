#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool cats[30][30];
int dp[30][30];
int R, C, K;

int main() {
    scanf("%d%d%d", &R, &C, &K);
    int x, y;
    for(int i = 0; i < K; i++) {
        scanf("%d%d", &x, &y);
        cats[x][y] = true;
    }
    dp[1][1] = 1;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j<=C; j++) {
            if(!cats[i][j])
                dp[i][j] += dp[i-1][j] + dp[i][j-1];
        }
    }
    printf("%d\n", dp[R][C]);
    return 0;
}