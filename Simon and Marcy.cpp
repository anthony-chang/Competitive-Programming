#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int arr[1001][1001];
int w[1001];
int v[1001];

int dp(int W, int wt[], int val[], int n) {
    int w;
    int K[n+1][W+1];

    for (int i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    return K[n][W];
}

int main() {
    int C, W;
    scanf("%d %d", &C, &W);
    for (int i = 0; i < C; i++)
        scanf("%d %d", &v[i], &w[i]);
    printf("%d", dp(W, w, v, C));
    return 0;
}


/*
int C, M, dp[1001][1001];
int main(){
    scanf("%d %d", &C, &M);
    for(int i = 1, v=0, w=0; i <= C; i++){
        scanf("%d %d", &v, &w);
        for(int j = 1; j <= M; j++)
            if (w > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], v + dp[i - 1][j - w]);
    }
    printf("%d", dp[C][M]);
}

*/