#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int club[33];
int dp[5281];
int dis, num;

int main() {
    scanf("%d%d", &dis, &num);
    for (int i = 0; i < num; i++)
        scanf("%d", &club[i]);

    for (int i = 1; i <= dis; i++) {
        int min = numeric_limits<int>::max();
        for (int j = 0; j < num; j++) {
            int cur =i-club[j];
            if (cur>=0&&dp[cur]<min&&dp[cur]>=0)
                min = dp[cur];
        }
        if (min < numeric_limits<int>::max())
            dp[i] = min+1;
        else dp[i] = -1;
    }
    if (dp[dis] == -1)
        printf("Roberta acknowledges defeat.");
    else
        printf("Roberta wins in %d strokes.", dp[dis]);
    return 0;
}