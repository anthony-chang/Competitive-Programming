#include <iostream>
#include <bits/stdc++.h>
//#include "inaho.h"

using namespace std;

typedef pair<int, int> pii;

int p[500010];
int rankk[500010];
stack<pair<pii, bool>> last;

int find(int x) {
    if (x != p[x])
        return find(p[x]);
    return x;
}
void Init(int N) {
    for (int i = 0; i <= N; i++) {
        p[i] = i;
        rankk[i] = 1;
    }
}
void AddEdge(int U, int V) {
    int pU = find(U);
    int pV = find(V);

    if (pU == pV) {
        last.push(make_pair(make_pair(pU, pV), false));
        return;
    }

    if (rankk[pU] > rankk[pV]) {
        p[pV] = p[pU];
        rankk[pU] += rankk[pV];
    }
    else {
        p[pU] = p[pV];
        rankk[pV] += rankk[pU];
    }
    last.push(make_pair(make_pair(pU, pV), true));
}
void RemoveLastEdge() {
    if (!last.top().second) {
        last.pop();
        return;
    }
    pii remove = last.top().first;
    if (p[remove.first]==remove.first) {
        p[remove.second]=remove.second;
        rankk[remove.first] -= rankk[remove.second];
    }
    else {
        p[remove.first] = remove.first;
        rankk[remove.second] -= rankk[remove.first];
    }
    last.pop();
}

int GetSize(int U) {
    return rankk[find(U)];
}