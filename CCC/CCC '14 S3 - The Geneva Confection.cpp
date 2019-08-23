#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int TT, N;
bool b;

int main() {

    scanf("%d", &TT);
    for (int x = 0; x < TT; x++) {
        b = true;
        stack<int> mountain, branch;
        scanf("%d", &N);
        int cur = 1;
        for (int i = 0, temp; i < N; i++) {
            scanf("%d", &temp);
            mountain.push(temp);
        }
        branch.push(0);
        while (cur!=N) {
            if(mountain.empty() && branch.top()!=cur) {
                b=false;
                break;
            }
            if(!mountain.empty()&&mountain.top() == cur) {
                mountain.pop();
                cur++;
                continue;
            }
            if(branch.top()==cur) {
                branch.pop();
                cur++;
                continue;
            }
            if(!mountain.empty()) {
                branch.push(mountain.top());
                mountain.pop();
            }

        }
        if (b) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}