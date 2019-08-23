#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
int n, m, p[1000002];
vector<int> e;

int find(int x) {
    return x!= p[x]? p[x] = find(p[x]): p[x];
}
void unionn (int x, int y) {
    p[x] = y;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 1, x, y; i <=m; i++) {
        scanf("%d %d", &x, &y);
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            unionn(fx, fy);
            e.push_back(i);
        }
        if (e.size() == n - 1) break;
    }
    if (e.size() == n - 1)
        for (int u: e)
            printf("%d\n", u);
    else printf("Disconnected Graph");
}