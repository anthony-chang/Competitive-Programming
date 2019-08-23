#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int T;

bool solve(int m, int x, int y) {
    //if (m == 0) return false;

    int x0 = static_cast<int>(x / pow(5, m - 1));
    int y0 = static_cast<int>(y / pow(5, m - 1));
    if (x0==0&&y0==0) return false;
    if (x0 > 0 && x0 < 4 && y0 == 0) return true;
    if (x0 == 2 && y0 == 1) return true;
    if (((x0==1||x0==3)&&y0==1) || (x0==2&&y0==2))
        return solve(m - 1, x % (int)pow(5, m - 1), y % (int)pow(5, m - 1));
    return false;

}

int main() {
    scanf("%d", &T);
    int mm, xx, yy;
    while (T--) {
        scanf("%d%d%d", &mm, &xx, &yy);
        printf("%s\n", solve(mm, xx, yy)? "crystal":"empty");
    }
    return 0;
}