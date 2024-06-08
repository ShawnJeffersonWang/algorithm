#include <bits/stdc++.h>
using namespace std;
// 最大子数组和
// 贪心解法
class Solution1 {
   public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result) {
                result = count;
            }
            if (count <= 0)
                count = 0;
        }
        return result;
    }
};
// 动态规划
class Solution2 {
   public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > result)
                result = dp[i];
        }
        return result;
    }
};