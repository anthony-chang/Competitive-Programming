#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dp[300][2510];
int c1[300][2510];
int c2[300][2510];
int t[300];
string str;
char c;
int X, curChar;

//merging left and right child nodes
//for (0 <= int k <= w)
// dp[u][w] = max(left[k] + right [w-k]);

void initialize(int i) {
    c = str[curChar++];
    while(isspace(c))
        c = str[curChar++];
    int val;
    if(isdigit(c)) {
        val = c - '0';
        c = str[curChar++];
        while(isdigit(c)) {
            val *= 10;
            val += c - '0';
            c = str[curChar++];
        }
        curChar--;
        t[i] = val;
    }
    else if (c== '(') {
        initialize(i<<1); //left child
        initialize(i<<1|1); //right child
        c = str[curChar++];
        while(isspace(c))
            c = str[curChar++];
    }
}
void solve (int i) {
    if (t[i]==0) {
        solve(i<<1);
        solve(i<<1|1);

        for (int j = 0; j <= X; j++)
            for (int k = 0; k <= j; k++)
//                dp[i << 1][j] = max(dp[i << 1][j], min((k + 1) * (k + 1), dp[i << 1][j - k]));
//                dp[i << 1 | 1][j] = max(dp[i << 1 | 1][j], min((k + 1) * (k + 1), dp[i << 1 | 1][j - k]));
                c1[i][j] = max(c1[i][j], min((k+1)*(k+1), dp[i<<1][j-k]));
        for (int j = 0; j <= X; j++)
            for (int k = 0; k <= j; k++)
                c2[i][j] = max(c2[i][j], min((k+1)*(k+1), dp[i<<1|1][j-k]));
        for (int j = 0; j <= X; j++)
            for (int k = 0; k <= j; k++)
                dp[i][j] = max(dp[i][j], c1[i][k]+c2[i][j-k]);

    }
    else {
        for (int j = 0; j <= X; j++)
            dp[i][j]=t[i]+j; //production of leaf node
    }
}
int main() {
    getline(cin, str);
    scanf("%d", &X);
    initialize(1);
    solve(1);
    printf("%d\n", dp[1][X]);

    return 0;
}