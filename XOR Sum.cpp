#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 0x3F3F3F3F;
const int MOD = (int)1e9 + 7;
const int MAX = 1000005;

ll N, minn, maxx;
//int arr[100005];
ll x;
int main() {
    scanf("%lld", &N);
    for(int i = 0; i < N; i++) {
        scanf("%lld", &x);
        maxx += x;
        minn = minn^x;
    }
    printf("%lld\n", maxx-minn);


    return 0;

}