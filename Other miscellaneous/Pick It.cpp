#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dp[202][202];
int arr[202];
int N;

int main() {
    scanf("%d", &N);
    while (N != 0) {
        for (int i = 0; i < N; i++)
            scanf("%d", &arr[i]);
        for (int i = 1; i < N - 1; i++)
            for (int j = 1; j < N - i; j++) {
                int cur = j + i - 1;
                int ans = 0;
                for (int k = j; k <= cur; k++)
                    ans = max(ans, arr[j-1]+arr[k]+arr[cur+1]+dp[j][k-1]+dp[k+1][cur]);
                dp[j][cur] = ans;
            }
        printf("%d\n", dp[1][N-2]);
        scanf("%d", &N);
    }
    return 0;
}