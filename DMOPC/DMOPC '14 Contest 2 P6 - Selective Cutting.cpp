#include <bits/stdc++.h>

using namespace std;

long long bit[100001];

class Query {
public:
    int a, b, q, order;
    void setQuery(int aa, int bb, int qq, int x) {
        a = aa;
        b = bb;
        q = qq;
        order = x;
    }
};

class Trees {
public:
    int mass, order;
    void setTree (int a, int b) {mass = a; order = b;}
};

long long sum(int index) {
    long long sum = 0;
    index++;
    while (index > 0) {
        sum += bit[index];
        index -= index & (-index);
    }
    return sum;
}
void update (int n, int index, int val) {
    index++;
    while (index <= n) {
        bit[index] += val;
        index += index & (-index);
    }
}


int main() {
    int n, Q;
    scanf("%d", &n);
    Trees input[n];
    fill(bit, bit+n, 0);

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        input[i].setTree(t, i);
    }
    sort(input, input + n,
         [](Trees const & a, Trees const & b) -> bool
         { return a.mass > b.mass;});

    scanf("%d", &Q);
    Query q[Q];
    for (int i = 0; i < Q; i++) {
        int aa, bb, qq;
        scanf("%d %d %d", &aa, &bb, &qq);
        q[i].setQuery(aa, bb, qq, i);
    }
    sort(q, q + Q,
        [](Query const & a, Query const & b) -> bool
        { return a.q > b.q;});
    long long ans[Q];
    for (int i = 0, j = 0; i < Q; i++) {
        for (; j < n && input[j].mass >= q[i].q; j++)
            update(n, input[j].order, input[j].mass);
        ans[q[i].order] = sum(q[i].b) - sum(q[i].a - 1);
    }
    for (int i = 0; i < Q; i++)
        cout << ans[i] << "\n";
    return 0;
}