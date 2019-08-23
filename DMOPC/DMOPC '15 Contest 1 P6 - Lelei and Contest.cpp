#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int n = 200001;
ll t[2*n];
int h = sizeof(int) * 8 - __builtin_clz(n);
ll lazy[n];
int input[200001];

void calc(int p, int k) {
    if (lazy[p] == 0) t[p] = t[p<<1] + t[p<<1|1];
    else t[p] = lazy[p] * k + t[p<<1] + t[p<<1|1];
}
void apply(int p, ll value, int k, int N) {
    t[p] += value * k;
    if (p < N) lazy[p] += value;
}
void build(int p) {
    int k = 2;
    while (p > 1) {
        p >>= 1;
        calc(p,k);
        k <<= 1;
    }
}
void push(int p, int N) {
    int k = 1 << (h-1);
    for (int s=h; s>0; s--){
        int i = p >> s;
        if (lazy[i] != 0) {
            apply(i<<1, lazy[i], k, N);
            apply(i<<1|1, lazy[i], k, N);
            lazy[i] = 0;
        }
        k >>= 1;
    }
}

void modify(int l, int r, int value, int N) {
    if (value == 0) return;
    l += N, r += N;
    int k=1;
    int left = l, right = r;
    push(l, N);
    push(r, N);
    while (l <= r) {
        if (l & 1) {
            apply(l++, value, k, N);
        }
        if (!(r & 1)) {
            apply(r--, value, k, N);
        }
        l >>= 1;
        r >>= 1;
        k <<= 1;
    }
    build(left);
    build(right);
}

long long query(int l, int r, int N) {
    l += N, r += N;
    push(l, N);
    push(r, N);
    long long res = 0;
    while (l <= r) {
        if (l & 1) {
            res += t[l++];
        }
        if (!(r & 1)) {
            res += t[r--];
        }
        l >>= 1;
        r >>= 1;
    }
    return res;
}
void initialize(int arr[], int N) {
    for (int i = 0; i < N; i++)
        t[i + N] = arr[i];
    for (int i = N - 1; i > 0; i--)
        t[i] = t[i << 1] + t[i << 1 | 1];
}

int main() {
    int M, N, Q;
    scanf("%d %d %d", &M, &N, &Q);
    for (int i = 0; i < N; i++)
        scanf("%d", &input[i]);
    initialize(input, N);
    int a, l, r, x;

    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d", &a, &l, &r);
        if (a == 1) {
            scanf("%d", &x);
            modify(l - 1, r - 1, x, N);
        }
        else if (a == 2) {
            printf("%lld\n", query(l - 1, r - 1, N)%M);
        }
    }
    return 0;
}