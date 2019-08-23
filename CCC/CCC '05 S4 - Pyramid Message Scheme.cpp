#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int L, N;
int ans[10], maxDepth;

string input[105];
string tree[105];
int main() {
    scanf("%d", &L);
    for(int i = 0; i < L; i++) {
        maxDepth = 0;
        scanf("%d", &N);
        for(int j = 0; j < N; j++) {
            cin>>input[j];
        }
        tree[0] = input[N-1];

        int cnt = 0, temp = 0;
        for(int j = 0; j < N; j++) {
            cnt = 0;
            while(tree[cnt]!=input[j] && cnt <= temp)
                cnt++;

            tree[cnt] = input[j];
            temp = cnt;
            if(temp > maxDepth) maxDepth = temp;

        }

        ans[i] = N*10-(20*maxDepth);
    }
    for(int i = 0; i < L; i++)
        printf("%d\n", ans[i]);

    return 0;
}