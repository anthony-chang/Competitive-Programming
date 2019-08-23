#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
pii arr[100001];
pii dup[100001];
int bitFreq[100002];
int t;

void update(int ind, int val) {
    ind++;
    while (ind <= t) {
        bitFreq[ind] += val;
        ind += ind & (-ind);
    }
}
void construct (int thing[]) {
    for (int i = 0; i < t; i++)
        update(i, thing[i]);
}
long long getSum (long ind) {
    long long sum = 0;
    ind++;
    while (ind > 0) {
        sum += bitFreq[ind];
        ind -= ind & (-ind);
    }
    return sum;
}
int main() {
    scanf("%d", &t);
    for (int i=0; i<t; i++){
        scanf("%d", &arr[i].first);
        arr[i].second = i;
    }
    sort(arr, arr+t);

    for (int i=0; i<t; i++){
        dup[i].first = arr[i].second;
        dup[i].second = i;
    }
    sort(dup, dup+t);

    long long sum = 0;

    for (int i = 0; i < t; i++) {
        update(dup[i].second, 1);
        sum += i - getSum(dup[i].second) + 2;
    }

    printf("%.2f\n", (sum+0.0)/t);

    return 0;
}