#include <iostream>
#include <bits/stdc++.h>
#define endl "\n";

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int N, M;
bool pho[100001], vis[100001];
pair<bool, int> dia[100001]; //diameter? and parent
int dis[100001], node1, node2, ans;
vector<int>adj[100001];


void dfs(int u) {
    vis[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        if (!vis[adj[u][i]]) {
            dis[adj[u][i]] = dis[u] + 1;
            dia[adj[u][i]].second = u;
            dfs(adj[u][i]);
        }
    }
}
inline void markDia(int u) {
    int cur = u;
    for (int i = 0; i < dis[u]; i++) {
        dia[cur].first = true;
        vis[cur] = true;
        cur = dia[cur].second;
    }
}
inline int solve(int u) {
    int ret = 0;
    while (!dia[u].first) {
        if (!vis[u]) {
            ret++;
            vis[u] = true;
        }
        u = dia[u].second;
    }
    return ret;
}

int main() {
    memset(pho, false, sizeof(pho));
    memset(vis, false, sizeof(vis));
    memset(dis, 0, sizeof(dis));

    int randPho = 0;
    scanf("%d%d", &N, &M);
    for (int i = 0, temp; i < M; i++) {
        scanf("%d", &temp);
        pho[temp] = true;
        randPho = temp;
    }
    for (int i = 0, a, b; i < N-1; i++) {
        scanf("%d%d", &a ,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(randPho);
    node1 = randPho;
    for (int i = 0; i < N; i++)
        if (pho[i] && dis[i] > dis[node1])
            node1 = i; //find furthest pho

    dia[node1].first = true; //mark it as on the diameter
    memset(vis, false, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    dfs(node1); //dfs to find the diameter

    node2 = node1; //furthest pho from first one
    for (int i = 0; i < N; i++)
        if (pho[i] && dis[i] > dis[node2])
            node2 = i;

    memset(vis, false, sizeof(vis));
    markDia(node2);

    ans = dis[node2];

    for (int i = 0; i < N; i++)
        if (pho[i] && !dia[i].first && !vis[i]) {
            ans += solve(i) * 2;
        }
    printf("%d", ans);
    return 0;
}