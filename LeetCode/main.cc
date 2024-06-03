#include <iostream>
#include <vector>
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
        vector<int> ans;
        if (matrix.empty()) {
            return ans;
        }
        int u = 0;
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while (true) {
            for (int i = l; i <= r; i++) {
                ans.push_back(matrix[u][i]);
            }
            if (++u > d) {
                break;
            }
            for (int i = u; i <= d; i++) {
                ans.push_back(matrix[i][r]);
            }
            if (--r < l) {
                break;
            }
            for (int i = r; i >= l; i--) {
                ans.push_back(matrix[d][i]);
            }
            if (--d < u) {
                break;
            }
            for (int i = d; i >= u; i--) {
                ans.push_back(matrix[i][l]);
            }
            if (++l > r) {
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix2{{1, 2,  3,  4},
                                {5, 6,  7,  8},
                                {9, 10, 11, 12}};
    const vector<int> &order = s.spiralOrder(matrix2);
    for (int num: order) {
        cout << num << " ";
    }
    return 0;
}
