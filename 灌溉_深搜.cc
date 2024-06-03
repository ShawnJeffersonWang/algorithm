//
// Created by 86138 on 2024/4/11.
//
//
// Created by 86138 on 2024/4/11.
//
#include <iostream>
#include <cstring>
#include <queue>

#define maxn 101

using namespace std;

int main() {
    int n, m, t, x, y;
    int front = 0, rear = 0;
    cin >> n >> m;
//    int hash[maxn][maxn];
    vector<vector<int>> hash(maxn, vector<int>(maxn, -1));
//    int queue[maxn * maxn];
    queue<int> queue;
    int dir[4][2] = {
            {1,  0},
            {-1, 0},
            {0,  1},
            {0,  -1}
    };
//    memset(hash, -1, sizeof(hash));

    cin >> t;
    while (t--) {
        cin >> x >> y;
        hash[x][y] = 0;
//        queue[rear++] = x * 1000 + y;
        queue.push(x * 1000 + y);
    }
    int k, ans = 0;
    cin >> k;
    while (!queue.empty()) {
//        int v = queue[front++];
        int v = queue.front();
        queue.pop();
        int x = v / 1000;
        int y = v % 1000;
        if (hash[x][y] == k) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if (tx > n || tx < 1 || ty > m || ty < 1) {
                continue;
            }
            if (hash[tx][ty] != -1) {
                continue;
            }
            hash[tx][ty] = hash[x][y] + 1;
//            queue[rear++] = tx * 1000 + ty;
            queue.push(tx * 1000 + ty);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (hash[i][j] != -1) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}