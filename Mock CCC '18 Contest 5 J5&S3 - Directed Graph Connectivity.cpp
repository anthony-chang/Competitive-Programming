#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
vector<int> adj[100];
pii cancel[2500];
bool vis[100];

void dfs(int u, int ith) {
    vis[u] = true;
    for (int i = 0; i <adj[u].size(); i++) {
        if(u == cancel[ith].first && adj[u][i] == cancel[ith].second)
            continue;
        if (!vis[adj[u][i]]) {
            dfs(adj[u][i], ith);
        }
    }

}

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 0, s, t; i < M; i++) {
        scanf("%d%d", &s, &t);
        adj[s].push_back(t);
        cancel[i].first = s;
        cancel[i].second = t;
    }
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < M; i++) {
        dfs(1, i);
        printf("%s\n", vis[N]? "YES":"NO");
        memset(vis, false, sizeof(vis));
    }

    return 0;
}