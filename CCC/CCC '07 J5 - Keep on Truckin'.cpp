#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 0x3F3F3F3F;
const int MOD = (int)1e9 + 7;
const int MAX = 1000005;

int A, B, N;
vector<int> locs;
ll dp[40];
int sz;
int main() {
    locs.push_back(0);
    locs.push_back(990);
    locs.push_back(1010);
    locs.push_back(1970);
    locs.push_back(2030);
    locs.push_back(2940);
    locs.push_back(3060);
    locs.push_back(3930);
    locs.push_back(4060);
    locs.push_back(4970);
    locs.push_back(5030);
    locs.push_back(5990);
    locs.push_back(6010);
    locs.push_back(7000);

    scanf("%d%d%d",&A, &B, &N);
    int u;
    for(int i = 0; i < N; i++) {
        scanf("%d", &u);
        locs.push_back(u);
    }
    sort(locs.begin(), locs.end());
    sz = 13+N;
    for(int i = 1; i <= sz; i++) {
        if(A<=locs[i]&&locs[i]<=B)
            dp[i] = 1;
        else
            dp[i] = 0;
    }
    for(int i = 1; i <sz; i++) {
        if(dp[i] >= 1) {
            for(int j = i+1; j<=sz; j++ ) {
                if (A <= locs[j] - locs[i] && locs[j] - locs[i] <= B)
                    dp[j] += dp[i];
            }
        }
    }

    printf("%lld\n", dp[sz]);


    return 0;
}