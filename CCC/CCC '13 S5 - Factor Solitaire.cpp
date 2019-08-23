#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
 * x = cur
 * y = next
 *
 * x = a*b
 *
 * y = x + a
 * then y = a*b + a
 *      y = a(b+1)
 *
 * and cost += b
 *
 * very first 2 factors are a and b
 */


int N, ans;
int main() {
    scanf("%d", &N);
    while (N > 1) {
        for (int i = 2; i <= N; i++)
            if (N%i==0) {
                int n = N/i;
                N -= n;
                ans += N/n;
                break;
            }
    }
    printf("%d", ans);
    return 0;
}

/*
int N;
bool isPrime(int n) {
    for (int i = 2; i*i<=n; i++)
        if (n%i==0) return false;
    return true;
}
int solve(int n) {
    if (n == 1) return 0;
    if (isPrime(n)) return n-1+solve(n-1);
    for (int i = 2; i < n; i++)
        if (n%i==0) return solve(i) + solve(n/i);
}
int main() {
    scanf("%d", &N);
    printf("%d", solve(N));
    return 0;
}
*/
