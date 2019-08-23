#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int N;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr+N);
    for (int i = 0; i < N; i++)
        printf("%d\n", arr[i]);
    return 0;
}