//
// Created by shawn on 24-4-12.
//
#include <vector>
#include <iostream>

using namespace std;

#define maxn 101

int dir[4][2] = {
        {0,  1},
        {1,  0},
        {0,  -1},
        {-1, 0}
};
vector<vector<int>> hash_arr(maxn, vector<int>(maxn, -1));

int n, m;

void dfs(int x, int y, int t, int k) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << hash_arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    if (t > k) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (tx > n || tx < 1 || ty > m || ty < 1) {
            continue;
        }
        if (hash_arr[tx][ty] == -1 || t < hash_arr[tx][ty]) {
            hash_arr[tx][ty] = t + 1;
            dfs(tx, ty, t + 1, k);
        }
    }
}

int main() {
//    memset(hash_arr,-1,sizeof(hash_arr));
    int t, k, ans = 0;
    cin >> n >> m;
    cin >> t;
    int x[10], y[10];
    for (int i = 0; i < t; i++) {
        cin >> x[i] >> y[i];
    }
    cin >> k;
    for (int i = 0; i < t; i++) {
        hash_arr[x[i]][y[i]] = 0;
        dfs(x[i], y[i], 0, k);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (hash_arr[i][j] != -1 && hash_arr[i][j] <= k) {
                ans++;
            }
        }
    }
//    cout << ans;
}