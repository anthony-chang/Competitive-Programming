#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<double, double> pii;
int N, eaten;
pii loc[105];
vector<int> ans;
bool vis[105];

double dis(double x, double sheepX, double sheepY) {
    return sqrt(sheepY*sheepY + pow(sheepX-x, 2));
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        double x, y;
        scanf("%lf%lf", &x, &y);
        loc[i].first = x;
        loc[i].second = y;
    }
    int check = 0;
    for(double i = 0; i < 1000; i+=0.01) {
        double disMin = 9999999;
        for (int j = 0; j < N; j++) {
            double d = dis(i, loc[j].first, loc[j].second);
            //printf("%lf\n", d);
            if(d < disMin) {
                check = j;
                disMin = d;
            }
        }
        if (!vis[check]) {
            vis[check] = true;
            ans.push_back(check);
            eaten++;
        }

    }
//    for (int i = 0; i < eaten; i++)
//        if (vis[i])
//            cout<<i<<endl;

    for (int i = 0; i < eaten; i++) {
        printf("The sheep at (%.2lf, %.2lf) might be eaten.\n", loc[ans[i]].first, loc[ans[i]].second);
    }

    return 0;
}