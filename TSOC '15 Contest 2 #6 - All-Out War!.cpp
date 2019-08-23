#include <iostream>
#include <bits/stdc++.h>
#define endl "\n";
using namespace std;

typedef long long ll;
const int n = 30001;
int h = sizeof(int) * 8 - __builtin_clz(n);
ll t[2 * n];
ll d[n];
ll input[n];
int N, Q;

void apply(int p, ll value) {
    t[p] += value;
    if (p < N) d[p] += value;
}

void build(int p) {
    while (p > 1) p >>= 1, t[p] = min(t[p<<1], t[p<<1|1]) + d[p];
}

void push(int p) {
    for (int s = h; s > 0; s--) {
        int i = p >> s;
        if (d[i] != 0) {
            apply(i<<1, d[i]);
            apply(i<<1|1, d[i]);
            d[i] = 0;
        }
    }
}

void update(int l, int r, ll value) {
    l += N, r += N;
    int l0 = l, r0 = r;
    while (l <= r) {
        if (l&1)
            apply(l++, value);
        if (!(r&1))
            apply(r--, value);
        l >>= 1;
        r >>= 1;
    }
    build(l0);
    build(r0);
}

ll query(int l, int r) {
    l += N, r += N;
    push(l);
    push(r);
    ll res = t[l];
    while (l <= r) {
        if (l & 1)
            res = min(res, t[l++]);
        if (!(r & 1))
            res = min(res, t[r--]);
        l >>= 1;
        r >>= 1;
    }
    if (res < 0)
        return 0;
    return res;
}
void initialize() {
    for (int i = N - 1; i > 0; i--)
        t[i] = min(t[i << 1], t[i << 1 | 1]);
}

int main() {
    scanf("%d %d", &N, &Q);
    for (int i = 0; i < N; i++)
        scanf("%lld", &t[i + N]);
    initialize();
    int a, b;
    ll c;
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %lld", &a, &b, &c);
        update(a-1, b-1, -c);
        printf("%lld %lld\n", query(a-1, b-1), query(0, N-1));
    }



    return 0;
}