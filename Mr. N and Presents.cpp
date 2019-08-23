#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 0x3F3F3F3F;
const int MOD = (int)1e9 + 7;
const int MAX = 1000005;

int Q, input;
char ch;
deque<pii> dk;
unordered_map<int, int> mp;


int main() {
    scanf("%d", &Q);
    for(int i = 1; i <= Q; i++) {
        scanf(" %c %d", &ch, &input);
        if(ch == 'F') {
            dk.push_front(make_pair(input, i));
            mp[input] = i;
        }
        else if(ch == 'E') {
            dk.push_back(make_pair(input, i));
            mp[input] = i;
        }
        else if (ch == 'R') {
            mp[input] = -1;
        }
    }

    for(int i = 0; i < dk.size(); i++) {
        if(dk[i].second == mp[dk[i].first])
            printf("%d\n", dk.at(i));
    }

    return 0;
}