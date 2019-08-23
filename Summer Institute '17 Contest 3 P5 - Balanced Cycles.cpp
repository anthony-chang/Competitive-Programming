#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int MAX = (int)1e5 + 5;

struct E{
    int v, w;
    E(int v0, int w0) {v = v0, w = w0;}
};
vector<E> adj[MAX];
vector<int> arr;
unordered_map<int, int> freq;
bool done[MAX];
//bool vis[100005];
int sizee[MAX];
ll ans;
char c;
int N;

void dfs(int u, int pa) {
    sizee[u] = 1;
    //vis[u] = true;
    for(auto e: adj[u]) {
        //if(vis[e.v])continue;
        if(e.v !=pa && !done[e.v]) {
            dfs(e.v, u);
            sizee[u]+= sizee[e.v];
        }
    }
}
int getCentroid(int u, int pa, int tot) {
    for(auto e: adj[u]) {
        if(e.v != pa && !done[e.v] && sizee[e.v]*2>tot)
            return getCentroid(e.v, u, tot);
    }
    return u;
}
void getPath(int u, int pa, int sum) {
    arr.push_back(sum);
    ans+= freq[1-sum] + freq[-1-sum];
    //printf("%lld\n", ans);

    for(auto e: adj[u]) {
        if(done[e.v] || e.v==pa)
            continue;
        getPath(e.v, u, sum +e.w);
    }
}
void solve(int rt, int pa) {
    //memset(vis, false, sizeof(vis));
    dfs(rt, 0);
    rt = getCentroid(rt, 0, sizee[rt]);
    freq.clear();
    freq[0] = 1;
    done[rt] = true;
    for(auto e: adj[rt]) {
        if(done[e.v])
            continue;
        arr.clear();
        getPath(e.v, rt, e.w);
        for(int v:arr)
            freq[v]++;
    }
    for(auto e: adj[rt])
        if(!done[e.v])
            solve(e.v, rt);
}

int main() {
    scanf("%d", &N);
    for(int i = 1, x, y; i < N; i++) {
        scanf("%d %d %c", &x, &y, &c);
        int w = (c=='r')? 1:-1;
        //printf("%d, %d, %d\n", x, y, w);
        adj[x].push_back(E(y, w));
        adj[y].push_back(E(x, w));
    }
    solve(1, 0);

    printf("%lld", ans-N+1);

    return 0;
}