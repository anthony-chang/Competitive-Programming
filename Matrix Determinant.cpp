#include <iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const int MOD = (ll) 1e9 + 7;
ll N, arr[510][510], det = 1;


ll fpow (ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (!(b & 1)) return fpow(a * a % MOD, b >> 1);
    return a * fpow(a * a % MOD, b >> 1 % MOD) % MOD;
}

int main () {
    scanf("%lld", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            scanf("%lld", &arr[i][j]);
            arr[i][j] += MOD;
        }

    int cur = 0;
    for (int i = 0; i < N; i++) {
        cur = i;
        for (int j = i + 1; j<N; j++)
            if (arr[cur][i] < arr[j][i])
                cur = j;
        if (cur ^ i) {
            det *= -1;
            swap(arr[i], arr[cur]);
        }
        for (int j = i + 1; j < N; j++) {
            ll val =  arr[j][i] * fpow(arr[i][i] % MOD, (int)(1e9+5)) % MOD;
            for (int k = i; k < N; k++)
                arr[j][k] = ((arr[j][k] % MOD - val % MOD * arr[i][k] % MOD) % MOD + MOD) % MOD;
        }
    }
    for (int i = 0; i < N; i++)
        det = (det % MOD * arr[i][i] % MOD) % MOD;
    printf("%lld", (det + MOD) % MOD);

    return 0;
}