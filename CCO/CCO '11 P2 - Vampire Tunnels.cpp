#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
struct node {
    int v, t, sun;
    node(int x, int y, int z){
        v=x;
        t=y;
        sun=z;
    }
    bool operator < (const node& x) const {
        return t > x.t;
    }
};
vector<node> adj[1610];
int S, N, E;
int dis[1610][3610];
priority_queue<node> q;

int main() {
    scanf("%d%d%d", &S, &N, &E);
    S++; //sketchy solutionsss
    for (int i = 0, u, v, t, s; i < E; i++) {
        scanf("%d%d%d%d", &u, &v, &t, &s);
        if(s==1) s=t;
        adj[u].push_back(node(v, t, s));
        adj[v].push_back(node(u, t, s));
    }

    memset(dis, 0x3f, sizeof(dis));
    q.push(node(0, 0, 0));
    dis[0][0] = 0;
    while(!q.empty()) {
        node cur = q.top();
        q.pop();
        if(cur.t>dis[cur.v][cur.sun])
            continue;
        for(int i=0; i<adj[cur.v].size(); i++){
            int v=adj[cur.v][i].v, t=adj[cur.v][i].t, sun=adj[cur.v][i].sun;
            if(cur.sun+sun > S)
                continue;
            if(cur.t + t < dis[v][cur.sun+sun]){
                dis[v][cur.sun+sun] = cur.t+t;
                q.push(node(v, cur.t+t, cur.sun+sun));
            }
        }
    }

    int ans = 99999999;
    for (int i = 0; i < S; i++){
        ans = min(ans, dis[N-1][i]);
    }
    if(ans == 99999999) printf("-1");
    else printf("%d\n", ans);
    return 0;
}