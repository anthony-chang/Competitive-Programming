#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 0x3F3F3F3F;
const int MOD = (int)1e9 + 7;
const int MAX = (int)1e9;

int N;
unordered_map<int, ll> dp;

ll f(int n) {
    if(n==1||n==2) return 1;
    if(dp.count(n)) return dp[n];
    ll ret = 0;
    int x = n;
    while(x >=2) {
        int w = n/x, y = n/(w+1);
        ret += (ll)(x-y)*f(w);
        x = y;
    }

    return dp[n] = ret;
}

int main() {
    scanf("%d", &N);


    printf("%lld", f(N));
    return 0;
}