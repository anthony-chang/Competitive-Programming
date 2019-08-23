#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
string a, b;
int arr1[200], arr2[200];
int main() {
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < a.length(); i++) {
        arr1[a[i]]++;
        if(b[i] != '*')
            arr2[b[i]]++;
    }
    for (int i = 0; i < 200; i++) {
        if(arr2[i] > arr1[i]) {
            printf("N");
            return 0 ;
        }
    }
    printf("A");
    return 0;
}