#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

class Solution {
public:
    /*
     2  3  4
     5  6  7
     8  9  10
     11 12 13
     14 15 16
     */
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        if (m == 1) {
            int k = 0;
            for (int i = 0; i < n; i++) {
                res.push_back(matrix[0][k++]);
            }
            return res;
        }
        if (n == 1) {
            int k = 0;
            for (int i = 0; i < n; i++) {
                res.push_back(matrix[k++][0]);
            }
            return res;
        }
        int min = m > n ? n : m;
        int loop = min / 2;
        int midx = min / 2;
        int midy = min / 2;
        int offset = 1;
        int startx = 0;
        int starty = 0;
        int i, j;
        while (loop--) {
            i = startx;
            j = starty;
            for (j = starty; j < n - offset; j++) {
                res.push_back(matrix[i][j]);
            }
            for (i = startx; i < m - offset; i++) {
                res.push_back(matrix[i][j]);
            }
            for (; j > starty; j--) {
                res.push_back(matrix[i][j]);
            }
            for (; i > startx; i--) {
                res.push_back(matrix[i][j]);
            }
            startx++;
            starty++;
            offset++;
        }
        if (m % 2 && n % 2) {
            for (int k = 0; k < n - offset; k++) {
                res.push_back(matrix[midx][midy++]);
            }
            midx--;
            midy--;
            for (int k = 0; k < n - offset; k++) {
                res.push_back(matrix[midx++][midy]);
            }
            return res;
        }
        if (m % 2) {
            for (int k = 0; k < n - offset; k++) {
                res.push_back(matrix[midx][midy++]);
            }
        }
        if (n % 2) {
            for (int k = 0; k < m - offset; k++) {
                res.push_back(matrix[midx++][midy]);
            }
        }
        return res;
    }
};

int main() {
    printf("");
    char *p = (char *) malloc(sizeof(char) * 1000);
    strcpy(p, "hello");

    free(p);
    Solution s;
    vector<vector<int>> matrix1{{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};
    vector<vector<int>> matrix2{{1, 2,  3,  4},
                                {5, 6,  7,  8},
                                {9, 10, 11, 12}};
    vector<vector<int>> matrix3{{2,  3,  4},
                                {5,  6,  7},
                                {8,  9,  10},
                                {11, 12, 13},
                                {14, 15, 16}};
    const vector<int> &order = s.spiralOrder(matrix3);
    for (int num: order) {
        cout << num << " ";
    }
    return 0;
}
