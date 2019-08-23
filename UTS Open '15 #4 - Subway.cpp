#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> piii;
typedef long long ll;

int N, M, T;
vector<piii> adj[2005];
double dp[2005][2005];

int main() {
    scanf("%d%d%d", &N, &M, &T);
    for(int i = 0, a, b, x, y; i < M; i++) {
        scanf("%d%d%d%d", &a, &b, &x, &y);
        adj[a].push_back({b, {x, y}});
    }
    dp[0][1] = 1.0;
    for(int t = 0; t <= T; t++) {
        for(int i = 1; i <= N; i++) {
            if(!(t==1 && i== 1) && t > 0)
                dp[t][i] += dp[t-1][i];
            for(auto e: adj[i]) {
                int j = e.first, lo = e.second.first, hi = e.second.second;
                double p = dp[t][i]/(double)(hi - lo + 1)/(double) adj[i].size();
                if(i == N || t + lo > T) continue;
                dp[t+lo][j] += p;
                dp[min(t+hi+1, T+1)][j]-=p;
            }
        }
    }
    double num = 0.0, den = 0.0;
    for(int t = 0; t <= T; t++) {
        num += dp[t][N] * t;
        den += dp[t][N];
    }
    printf("%.10f\n", num/den);

    return 0;
}