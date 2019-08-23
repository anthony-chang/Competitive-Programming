#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, in;
int arr[10];
int main() {
    scanf("%d", &N);
    for(int i = 0; i < 10; i++)
        arr[i] = 1;
    for(int i = 1; i < N; i++) {
        scanf("%d", &in);
        arr[in] = arr[in]*(1+arr[i]);
    }


    printf("%d", arr[N]);
    return 0;
}