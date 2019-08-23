#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 0x3F3F3F3F;
const int MOD = (int)1e9 + 7;
const int MAX = 1000005;

ll X, Y;
int main() {
    scanf("%lld%lld", &X, &Y);

    ll out = X*Y/2;

    if(X*Y%2 == 0)
        printf("%lld.0\n", out);
    else
        printf("%lld.5\n", out);
    return 0;

}