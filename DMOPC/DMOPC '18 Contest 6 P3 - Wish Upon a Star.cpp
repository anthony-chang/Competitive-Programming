#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 0x3F3F3F3F;
const int MOD = (int)1e9 + 7;
const int MAX = 1000005;

int N, M;
vector <int> adj[200005];
int cc = 0;
bool vis[200005];

void dfs(int s) {
    vis[s] = true;
    for(int i = 0; i < adj[s].size(); i++) {
        if (!vis[adj[s][i]]) {
            dfs(adj[s][i]);
        }
    }
}
int main() {
    scanf("%d%d", &N ,&M);
    for(int i = 0, a, b; i < M; i++) {
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < N; i++) {
        if(!vis[i]) {
            dfs(i);
            cc++;
        }
    }
    if(M == N-cc || M == N-cc+1)
        printf("YES");
    else
        printf("NO");

    return 0;
}