#include <bits/stdc++.h>
using namespace std;
// 摆动序列
class Solution {
   public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        int curDiff = 0;
        int preDiff = 0;
        int result = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            if ((curDiff > 0 && preDiff <= 0) ||
                (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};