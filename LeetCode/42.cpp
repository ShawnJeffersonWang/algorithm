//
// Created by shawn on 24-3-5.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int sum = 0;
        vector<int> max_left(height.size());
        vector<int> max_right(height.size());
        for (int i = 1; i < height.size(); i++) {
            max_left[i] = std::max(max_left[i - 1], height[i - 1]);
        }
        for (int j = height.size() - 2; j >= 0; j--) {
            max_right[j] = std::max(max_right[j + 1], height[j + 1]);
        }
        for (int i = 1; i < height.size() - 1; i++) {
            int min = std::min(max_left[i], max_right[i]);
            if (min > height[i]) {
                sum += min - height[i];
            }
        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int sum = s.trap(nums);
    cout << "sum = " << sum << endl;
}