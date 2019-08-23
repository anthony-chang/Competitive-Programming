#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll a[2005];
ll b[2005];
ll c;
int M;
const int mod = static_cast<const int>(1e9 + 7);

ll exp(ll b, ll e) {
    if (e == 0) return 1;
    if (e == 1) return b;
    if (e%2 == 0) return exp(b*b %mod, e/2);
    return b * exp (b*b%mod, e/2) % mod;
}
inline ll coef(ll n, ll k) {
    return n * exp(k, mod - 2) % mod;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &a[i]);
    scanf("%d", &M);
    c = -1;
    for (int i = 0; i < N; i++) {
        if (c == -1) c = 1;
        else {
            c = (c*(i+M-1)) % mod;
            c = coef(c, i);
        }
        for (int j = 0 + i; j < N; j++)
            b[j] = (b[j]+c*a[j-i]) % mod;
    }
    for (int i = 0; i < N; i++)
        printf("%lld ", b[i]);


    return 0;
}