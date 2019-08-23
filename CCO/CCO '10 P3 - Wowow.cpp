#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

const int MAX = 1000005;
int t[MAX];
vector <int> rating, id;
unordered_map <int,int> indId, idInd, ratingInd;
int N;
char C;
int X, R, K;
int idRating[MAX], ratingId[MAX];

struct E {
    char c;
    int x, r, k;
    E(char c0, int x0, int r0){c = c0; x = x0; r = r0;}
    E(char c0, int k0) {c = c0; k = k0;}
};
vector <E> queries;

void update(int i, int val) {
    for (;i < MAX; i+=(i & -i)) t[i]+=val;
}
ll query(int i) {
    ll sum = 0;
    for (;i >0; i-=(i&-i)) sum+=t[i];
    return sum;
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %c", &C);
        if (C== 'N' || C == 'M') {
            scanf(" %d %d", &X, &R);
            queries.push_back(E(C, X, R));
            id.push_back(X);
            rating.push_back(R);
        }
        else {
            scanf(" %d", &K);
            queries.push_back(E(C,K));
        }
    }
    sort(id.begin(), id.end());
    id.erase(unique(id.begin(), id.end()), id.end());
    sort(rating.begin(), rating.end());

    int count = 0;
    for (int i = 0; i < id.size(); i++) {
        idInd[id[i]] = ++count;
        indId[count] = id[i];
    }
    count = 0;
    for (int i = 0; i < rating.size(); i++) {
        ratingInd[rating[i]] = count + 1;
        count++;
    }
    int num = 0, curId, curRating;
    for (int i = 0;i < N; i++) {
        E cur = queries[i];
        if (cur.c=='N') {
            curId = cur.x; curRating = cur.r;
            idRating[idInd[curId]] = ratingInd[curRating];
            ratingId[ratingInd[curRating]] = idInd[curId];
            update(ratingInd[curRating], 1);
            num++;
        }
        else if (cur.c=='M') {
            curId = cur.x; curRating = cur.r;
            update(idRating[idInd[curId]], -1);
            idRating[idInd[curId]] = ratingInd[curRating];
            ratingId[ratingInd[curRating]] = idInd[curId];
            update(ratingInd[curRating], 1);
        }
        else {
            int l = 1, r = count, mid;
            while (l <= r) {
                mid = l + (r-l)/2;
                if (query(mid) > num - cur.k)
                    r = mid - 1;
                else l = mid + 1;
            }
            printf("%d\n", indId[ratingId[l]]);
        }
    }
}