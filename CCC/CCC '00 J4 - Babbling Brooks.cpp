#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 0x3F3F3F3F;
const int MOD = (int)1e9 + 7;
const int MAX = 1000005;

int N;
vector<int> arr;
int in;
int main() {
    scanf("%d", &N);
    //arr.push_back(-1);
    for(int i = 0, u; i < N; i++) {
        scanf("%d", &u);
        arr.push_back(u);
    }
    scanf("%d", &in);
    int split, p1, temp;
    while(in!=77) {
        if(in==99) {
            scanf("%d%d", &split, &p1);
            split--;
            temp = arr[split];
            arr[split] = p1*temp/100;
            arr.insert(arr.begin()+split+1, temp-arr[split]);
            N++;
        }
        if(in==88) {
            scanf("%d", &split);
            split--;
            arr[split+1]+=arr[split];
            arr.erase(arr.begin()+split);
            N--;
        }
        scanf("%d", &in);

    }
    for(int i = 0; i<N; i++ ) {
        printf("%d ", arr[i]);
    }
    return 0;
}