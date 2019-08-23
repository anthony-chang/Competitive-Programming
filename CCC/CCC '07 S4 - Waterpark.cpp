#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int dp[100001];
int st[100001]; //start
int ed[100001]; //end
int N, num;

int dpp(int cur) {
    if (cur == N) return 1;
    int sum = 0;
    for (int i = 0; i < num; i++) {
        if (st[i] == cur) {
            if (dp[ed[i]] != 0)
                sum += dp[ed[i]];
            else {
                dp[ed[i]] =dpp(ed[i]);
                sum += dp[ed[i]];
            }
        }
    }
    return sum;
}
int main() {
    scanf("%d", &N);
    num = 0;
    int p1, p2;
    scanf("%d%d", &p1, &p2);
    while (p1 != 0) {
        st[num] = p1;
        ed[num] = p2;
        num++;
        scanf("%d%d", &p1, &p2);
    }
    printf("%d", dpp(1));
    return 0;
}