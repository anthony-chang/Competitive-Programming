#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 0x3F3F3F3F;
const int MOD = (int)1e9 + 7;
const int MAX = 1000005;

int N, ans;
int arr[1005][1005];
int cnt;
bool b;

int main() {
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ++cnt;
            scanf("%d", &arr[i][j]);

            if(cnt != arr[i][j]) {
                ans++;
                b = true;
            }
        }
        if(b) {
            printf("%d\n", ans);
            return 0;
        }
    }
    return 0;
}