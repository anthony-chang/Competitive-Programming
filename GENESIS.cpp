#include <iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const int MAX = 202;
const int INF = 0x3f3f3f3f;
int N, M, adj[MAX][MAX], pre[MAX], vis[MAX], flow, s, t;


void maxFlow() {
    while (true) {
        queue <int> Q;
        Q.push(s);
        memset(pre, -1, sizeof(pre));
        memset(vis, 0, sizeof(vis));
        int mx = INF;
        vis[s] = 1;

        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            if (u == t) {
                for(int v = u; v != s; v = pre[v])
                    mx = min(mx, adj[pre[v]][v]);
                flow += mx;
                break;
            }
            for(int v = 1; v <= 2*N; v++) {
                if (adj[u][v] > 0 &&!vis[v] ) {//exists and not vis
                    Q.push(v);
                    vis[v] = 1;
                    pre[v] = u;
                }
            }
        }
        if (!vis[t]) return;
        for(int v = t; v!=s; v = pre[v]) {
            adj[pre[v]][v] -= mx;
            adj[v][pre[v]] += mx;
        }
    }
}

int main() {
    scanf("%d", &N);
    s = 1, t = N;
    for (int i = 1, x; i < N; i++) {
        scanf("%d", &x);
        adj[i][i+N] = x;
    }
    scanf("%d", &M);
    for(int i = 1, u, v; i <=M; i++) {
        scanf("%d %d", &u, &v);
        adj[u+N][v] = INF;
    }
    maxFlow();
    printf("%d\n", flow);

}