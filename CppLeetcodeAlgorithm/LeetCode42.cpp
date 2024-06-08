#include <bits/stdc++.h>
#include <stdexcept>
using namespace std;
// 接雨水
// 双指针解法
class Solution {
   public:
    int trap(vector<int>& height) {
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            if (i == 0 || i == height.size() - 1)
                continue;
            int rHeight = height[i];
            int lHeight = height[i];
            for (int r = i + 1; r < height.size(); r++) {
                if (height[r] > rHeight)
                    rHeight = height[r];
            }
            for (int l = i - 1; l >= 0; l--) {
                if (height[l] > lHeight)
                    lHeight = height[l];
            }
            int h = min(lHeight, rHeight) - height[i];
            if (h > 0)
                sum += h;
        }
        return sum;
    }
};