#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int K, ans;
ll h[1000005], p[1000005];
int seed = 131;
string s;

ll getHash(int s, int len) {
    return h[s+len] - p[len]*h[s];
}
int bs(int i, int j) {
    int lo = 0, hi = K;
    while (lo <= hi) {
        int mid = (lo + hi)/2;
        if(getHash(i, mid)!= getHash(j, mid)) {
            hi = mid-1;
        } else
            lo = mid+1;
    }
    return lo;
}
int main() {
    cin>>s>>K;
    h[0] = s[0];
    p[0] = 1;
    for(int i = 1; i < s.size(); i++) {
        h[i] = h[i-1]*seed + s[i];
        p[i] = p[i-1]*seed;
    }
    for(int i = 1; i < s.size() - K + 1; i++) {
        if(s[i]==s[ans]) {
            int pos = bs(i, ans);
            if (s[i + pos] < s[ans + pos])
                ans = i;
        } else if (s[i]<s[ans])
                ans = i;

    }
    for(int i = 0; i < K; i++)
        cout<<s[ans+i];

    return 0;
}