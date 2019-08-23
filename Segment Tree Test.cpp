#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;
int N, M;
int input[100001];
int minSeg[200002];
pii gcdSeg[200002];
// >> 1 means /2
// << 1 means *2
void buildSeg() {
    for (int i = N; i < 2 * N; i++) {
        minSeg[i] = input[i - N];
        gcdSeg[i].first = input[i - N];
        gcdSeg[i].second = 1;
    }
    for (int i = N - 1; i > 0; i--) {
        minSeg[i] = min(minSeg[i << 1], minSeg[i << 1 | 1]); //tree[i] = min(tree[i * 2], tree[i * 2 + 1])
        gcdSeg[i].first = __gcd(gcdSeg[i << 1].first, gcdSeg[i << 1 | 1].first);

        if (gcdSeg[i].first == gcdSeg[i << 1].first)
            gcdSeg[i].second += gcdSeg[i << 1].second;
        if (gcdSeg[i].first == gcdSeg[i << 1 | 1].first)
            gcdSeg[i].second += gcdSeg[i << 1 | 1].second;
    }
}
void updateSeg(int ind, int value) {
    ind += N;
    minSeg[ind] = value;
    gcdSeg[ind].first = value;
    int num;
    while (ind > 0) {
        ind >>= 1;
        num = 0;
        minSeg[ind] = min(minSeg[ind << 1], minSeg[ind << 1 | 1]);
        gcdSeg[ind].first = __gcd(gcdSeg[ind << 1].first, gcdSeg[ind << 1 | 1].first);
        if (gcdSeg[ind].first == gcdSeg[ind << 1].first)
            num += gcdSeg[ind << 1].second;
        if (gcdSeg[ind].first == gcdSeg[ind << 1 | 1].first)
            num += gcdSeg[ind << 1 | 1].second;
        gcdSeg[ind].second = num;
    }
}
int findMin (int left, int right) {
    int curMin = input[left];
    left += N;
    right += N;
    while (left <= right) {
        if (left & 1)
            curMin = min(curMin, minSeg[left++]);
        if (!(right & 1))
            curMin = min(curMin, minSeg[right--]);
        left >>= 1;
        right >>= 1;
    }
    return curMin;
}
int findGcd (int left, int right) {
    int curGcd = input[left];
    left += N;
    right += N;
    while (left <= right) {
        if (left & 1)
            curGcd = __gcd(curGcd, gcdSeg[left++].first);
        if (!(right & 1))
            curGcd = __gcd(curGcd, gcdSeg[right--].first);
        left >>= 1;
        right >>= 1;
    }
    return curGcd;
}
int countGcd (int left, int right) {
    int ans = findGcd(left, right), ret = 0;
    left += N;
    right += N;
    while (left <= right) {
        if (left & 1) {
            if (gcdSeg[left].first == ans)
                ret += gcdSeg[left].second;
            left++;
        }
        if (!(right & 1)) {
            if (gcdSeg[right].first == ans)
                ret += gcdSeg[right].second;
            right--;
        }
        left >>= 1;
        right >>= 1;
    }
    return ret;
}
int main (){

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &input[i]);

    buildSeg();
    char c;
    int a, b;
    for (int i = 0; i < M; i++) {
        scanf(" %c %d %d", &c, &a, &b); //space before %c  !!!
        if (c == 'C') {
            input[a - 1] = b;
            updateSeg(a - 1, b);
        }
        if (c == 'M')
            printf("%d\n", findMin(a - 1, b - 1));
        if (c == 'G')
            printf("%d\n", findGcd(a - 1, b - 1));
        if (c == 'Q')
            printf("%d\n", countGcd(a - 1, b - 1));

    }
    return 0;

}