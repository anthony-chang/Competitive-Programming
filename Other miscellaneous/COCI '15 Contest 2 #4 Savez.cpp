#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N, ans, base = 131;
ll hsh1, hsh2, p;
int temp;
unordered_map<ll, int> mp;
string s;


int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        cin>>s;
        hsh1 = 0; hsh2 = 0;
        p = 1;
        temp = 0;
        for(int j = 0; j < s.size(); j++) {
            hsh1 = hsh1 * base + s[j];
            hsh2 = s[s.size()-j-1]*p + hsh2;
            p*= base;
            if(hsh1 == hsh2)
                temp = max(temp, mp[hsh1]);
        }
        mp[hsh1] = temp + 1;
        ans = max(ans, temp+1);
    }
    printf("%d", ans);

    return 0;
}