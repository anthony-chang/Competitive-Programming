#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int M, U, R;
int dp[152][302][152];
//items(restaurants), weight(time), fullness
int main() {
    scanf("%d%d%d", &M, &U, &R);
    for (int i = 1, v=0, t=0,f=0; i <= R; i++) {
        scanf("%d%d%d", &v, &t, &f);
        for (int j=1; j<=M; j++)
            for (int k=1; k<=U; k++) {
                if (t>j||f>k) dp[i][j][k] = dp[i-1][j][k]; 
                else dp[i][j][k] = max(dp[i-1][j][k], v+dp[i-1][j-t][k-f]);
            }
    }
    printf("%d", dp[R][M][U]);

    return 0;
}