#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 0x3F3F3F3F;
const int MOD = (int)1e9 + 7;
//const int MAX = ;

int N, M, P, Q;
vector<int> adj[1000010];
bool vis[1000010];


bool bfs(int s, int t) {
    queue<int> q;
    memset(vis, false, sizeof(vis));
    vis[s] = true;
    q.push(s);
    int cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur == t)
            return true;
        for (int e:adj[cur]) {
            if (!vis[e]) {
                vis[e] = true;
                q.push(e);
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 0, x, y; i < M; i++) {
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
    }
    scanf("%d%d", &P, &Q);
    if(bfs(P, Q)) printf("yes");
    else if(bfs(Q, P)) printf("no");
    else printf("unknown");

    return 0;
}