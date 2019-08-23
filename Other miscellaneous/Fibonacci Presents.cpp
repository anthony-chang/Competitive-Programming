#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
typedef pair<int, int>pii;

int K, N;
ll cool[1000005];
ll dp[1000005];
int main() {
    scanf("%d%d", &K, &N);
    for(int i = 1; i <= N; i++)
        scanf("%lld", &cool[i]);

    if (K > N+1) {
        printf("-1");
        return 0;
    }
    dp[1] = cool[1];
    dp[2] = max(cool[1], cool[2]);


    for(int i = 3; i <= N+1; i++) {
        dp[i] = max(dp[i-2]+cool[i-1], cool[i]);
    }
    if (K<=2)
        printf("%lld", max(cool[1], cool[2]));
    else
        printf("%lld", dp[K]);


    return 0;
}