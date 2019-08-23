#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 0x3F3F3F3F;
const int MOD = (int)1e9 + 7;
const int MAX = 1000005;

int trips, N, fuck;
int arr[30][30];
int dis[30][30];
bool vis[30][30];

struct pt {
    int x, y;
    pt(int a, int b) {
        x = a, y = b;
    }
};

bool bfs() {
    vis[1][1] = true;
    queue<pt> q;
    q.push(pt(1, 1));
    while(!q.empty()) {
        pt cur = q.front();
        q.pop();

        if(cur.x == N && cur.y == N)
            return true;

        if (!vis[cur.x + 1][cur.y]&& abs(arr[cur.x+1][cur.y]-arr[cur.x][cur.y])<=2 && arr[cur.x+1][cur.y] != -1) {
            if(arr[cur.x+1][cur.y] > fuck || arr[cur.x][cur.y] > fuck)
                dis[cur.x + 1][cur.y] = dis[cur.x][cur.y] + 1;
            else dis[cur.x + 1][cur.y] = dis[cur.x][cur.y];
            vis[cur.x + 1][cur.y] = true;
            q.push(pt(cur.x + 1, cur.y));
        }
        if (!vis[cur.x - 1][cur.y]&& abs(arr[cur.x-1][cur.y]-arr[cur.x][cur.y])<=2 && arr[cur.x-1][cur.y] != -1) {
            if (arr[cur.x-1][cur.y] > fuck || arr[cur.x][cur.y] > fuck)
                dis[cur.x - 1][cur.y] = dis[cur.x][cur.y] + 1;
            else dis[cur.x - 1][cur.y] = dis[cur.x][cur.y];
            vis[cur.x - 1][cur.y] = true;
            q.push(pt(cur.x - 1, cur.y));
        }
        if (!vis[cur.x][cur.y + 1]&& abs(arr[cur.x][cur.y+1]-arr[cur.x][cur.y])<=2 && arr[cur.x][cur.y+1] != -1) {
            if(arr[cur.x][cur.y+1] > fuck || arr[cur.x][cur.y] > fuck)
                dis[cur.x][cur.y + 1] = dis[cur.x][cur.y] + 1;
            else dis[cur.x][cur.y + 1] = dis[cur.x][cur.y];
            vis[cur.x][cur.y + 1] = true;
            q.push(pt(cur.x, cur.y + 1));
        }
        if (!vis[cur.x][cur.y - 1]&&abs(arr[cur.x][cur.y-1]-arr[cur.x][cur.y])<=2 && arr[cur.x][cur.y-1] != -1) {
            if(arr[cur.x][cur.y-1] > fuck || arr[cur.x][cur.y] > fuck)
                dis[cur.x][cur.y - 1] = dis[cur.x][cur.y] + 1;
            else dis[cur.x][cur.y - 1] = dis[cur.x][cur.y];
            vis[cur.x][cur.y - 1] = true;
            q.push(pt(cur.x, cur.y - 1));
        }
    }
    return false;
}

int main() {
    scanf("%d", &trips);
    for(int ii = 0; ii < trips; ii++) {
        scanf("%d", &N);
        memset(arr, -1, sizeof(arr));
        memset(dis, 0, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        fuck = arr[1][1];
        if(bfs()) {
            printf("%d\n\n", dis[N][N]);
        }
        else
            printf("CANNOT MAKE THE TRIP\n\n");


    }

    return 0;
}