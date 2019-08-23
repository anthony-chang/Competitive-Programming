#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int j[1000010];
int J, A, ans;
int main() {
    scanf("%d%d", &J, &A);
    for(int i = 1; i <= J; i++) {
        char in;
        scanf(" %c", &in);
        if(in == 'S') j[i] = 1;
        else if (in == 'M') j[i] = 2;
        else if (in == 'L') j[i] = 3;
    }
    for(int i = 0, in, size = 0; i < A; i++) {
        char c;
        scanf(" %c %d", &c, &in);
        if(c == 'S') size= 1;
        else if (c == 'M') size = 2;
        else if (c == 'L') size = 3;

        if(j[in]>=size) {
            j[in] = -1;
            ans++;
        }

    }
    printf("%d", ans);
    return 0;
}