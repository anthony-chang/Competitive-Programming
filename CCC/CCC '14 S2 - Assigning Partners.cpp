#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

struct E {
    string a, b;
}; E arr[35];
int N;
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        string in;
        cin>>in;
        arr[i].a = in;
    }
    for(int i = 0; i < N; i++) {
        string in;
        cin>>in;
        arr[i].b = in;
    }

    for(int i = 0; i < N; i++) {
        string curra = arr[i].a, currb = arr[i].b;
        if(curra == currb) {
            printf("bad");
            return 0;
        }
        for(int j = 0; j < N; j++) {
            if(arr[j].a == curra) {
                if(arr[j].b != currb) {
                    printf("bad");
                    return 0;
                }
            }
            if(arr[j].b == curra) {
                if(arr[j].a != currb) {
                    printf("bad");
                    return 0;
                }
            }
        }

    }
    printf("good");
    return 0;
}