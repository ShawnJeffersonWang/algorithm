#include <bits/stdc++.h>
using namespace std;
// 长度最小的子数组
class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;
        int sum = 0;
        int i = 0;
        int subLength = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= target) {
                subLength = (j - i + 1);
                result = subLength < result ? subLength : result;
                sum -= nums[i++];
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};