#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int N;
ll arr[2010];
ll sum[4010]; //number of times a height of index is possible
ll length, numHeight;
int main() {
    scanf("%d", &N);
    for(int i = 0, in; i < N; i++) {
        scanf("%d", &in);
        arr[in]++;
    }
    for(int i = 1; i < 2001; i++) {
        if(arr[i] != 0) {
            sum[2*i] += arr[i]/2;
            for(int j = i+1 ;j < 2001; j++) {
                if(arr[j] != 0)
                    sum[i+j] += min(arr[i], arr[j]);
            }
        }
    }
    for(int i = 0; i < 4001; i++) {
        if(sum[i] > length) {
            length = sum[i];
            numHeight = 1;
        }
        else if(sum[i] == length)
            numHeight++;
    }
    printf("%lld %lld", length, numHeight);

    return 0;
}