#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 0x3F3F3F3F;
const int MOD = (int)1e9 + 7;
//const int MAX = ;

int N, arr[105];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr+N);
    if(N%2==0) {
        int mid = N / 2;
        for (int i = 0; i < N / 2; i++) {
            printf("%d %d ", arr[mid - i - 1], arr[mid + i]);
        }
    }
    else {
        int mid = N/2;
        for (int i = 0; i < N/2; i++) {
            printf("%d %d ", arr[mid - i], arr[mid+i+1]);
        }
        printf("%d", arr[0]);

    }
    return 0;
}