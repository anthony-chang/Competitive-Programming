#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int arr[36][36];
bool b[100];

int N;

int main() {
    scanf("%d", &N);
    for (int i = 0, temp; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            scanf(" %c", &c);
            temp = c - '0';
            arr[i][j] = temp;
        }
    }
    memset(b, false, sizeof(b));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (b[arr[i][j]]) {
                cout<<"No"<<endl;
                return 0;
            }
            else b[arr[i][j]] = true;
        }
        memset(b, false, sizeof(b));
    }
    memset(b, false, sizeof(b));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (b[arr[j][i]]) {
                cout<<"No"<<endl;
                return 0;
            }
            else b[arr[j][i]] = true;
        }
        memset(b, false, sizeof(b));
    }
    for (int i = 0; i < N-1; i++) {
        if (arr[0][i] > arr[0][i+1]) {
            cout<<"Latin"<<endl;
            return 0;
        }
        if (arr[i][0] > arr[i+1][0]) {
            cout << "Latin"<<endl;
            return 0;
        }
    }
    if (arr[0][N-2]>arr[0][N-1]){
        cout << "Latin"<<endl;
        return 0;
    }
    if (arr[N-2][0]>arr[N-1][0]){
        cout << "Latin"<<endl;
        return 0;
    }
    cout<<"Reduced"<<endl;

    return 0;
}