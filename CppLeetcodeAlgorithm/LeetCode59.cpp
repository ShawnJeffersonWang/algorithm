#include <bits/stdc++.h>
using namespace std;
// 螺旋矩阵II
class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startx = 0, starty = 0;
        int count = 1;
        int loop = n / 2;
        int offset = 1;
        int mid = n / 2;
        int i, j;
        while (loop--) {
            for (j = starty; j < n - offset; j++) {
                res[startx][j] = count++;
            }
            for (i = startx; i < n - offset; i++) {
                res[i][j] = count++;
            }
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            for (; i > startx; i--) {
                res[i][j] = count++;
            }
            startx++;
            starty++;
            offset++;
        }
        if (n % 2 != 0) {
            res[mid][mid] = count;
        }
        return res;
    }
};
