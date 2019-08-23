#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 0x3F3F3F3F;
const int MOD = (int)1e9 + 7;
//const int MAX = ;

int N, M; //# of vertices, # of edges

struct E {
    int v, w; //destination vertex, weight of edge to vertex v
    E(int v0, int w0) {v = v0; w = w0;};

    bool operator < (const E& x) const {
        return w > x.w; //reverse sort(priority queue in C++ sorts by biggest first default)
    }
};
vector <E> adj[1005]; //adjacency matrix
int dis[1005]; //distance from start to vertex index

int djik1(int s, int t) { //O(E logV) implementation
    memset(dis, INF, sizeof(dis));
    priority_queue<E> q;
    dis[s] = 0;
    q.push({s, 0});
    while(!q.empty()){
        E cur = q.top();
        q.pop();
        if(cur.w > dis[cur.v])
            continue;
        for(E e : adj[cur.v]) {
            if (dis[e.v] > dis[cur.v] + e.w) {
                dis[e.v] = dis[cur.v] + e.w;
                q.push({e.v, dis[e.v]});
            }
        }
    }
    return dis[t];
    //distance to node t = dis[t];
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 0, a, b, w; i < M; i++) {
        scanf("%d%d%d", &a, &b, &w);
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    for(int i = 1; i <= N; i++) {
        int n = djik1(1, i);
        if(n==INF)
            printf("-1\n");
        else printf("%d\n", n);
    }
    r