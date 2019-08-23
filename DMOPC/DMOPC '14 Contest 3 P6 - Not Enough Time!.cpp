#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N, T;
int p[2001][3];
int v[2001][3];
int dp[10001];

int main() {
    scanf("%d%d", &N, &T);
    for (int i =0; i<N; i++)
        for (int j = 0; j<3; j++)
            scanf("%d%d", &p[i][j], &v[i][j]);
    for (int i = 0; i < N; i++)
        for (int j = T; j>=0; j--)
            for (int k = 0; k < 3; k++)
                if (j + p[i][k] <= T)
                    dp[j + p[i][k]] = max(dp[j + p[i][k]], dp[j] + v[i][k]);
    int ans = 0;
    for (int i = 0; i <=T; i++)
        ans = max(ans, dp[i]);
    printf("%d", ans);


    return 0;
}