#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int ques, N;
int dmoj[105], peg[105];
int main() {
    scanf("%d%d", &ques, &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &dmoj[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &peg[i]);

    sort(dmoj, dmoj+N);
    sort(peg, peg+N);
    int ans=0;
    if(ques == 1) {
        for(int i = 0; i < N; i++)
            ans += max(dmoj[i], peg[i]);
    }
    else if(ques == 2) {
        for (int i = 0; i < N; i++)
            ans += max(dmoj[i], peg[N-i-1]);
    }
    printf("%d", ans);

    return 0;
}