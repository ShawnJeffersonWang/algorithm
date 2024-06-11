//
// Created by shawn on 24-3-6.
//
#include <iostream>
#include <vector>


using namespace std;

class Solution {
   public:
    //    static int lengthOfLIS(vector<int> &nums) {
    //        int n = (int) nums.size();
    //        if (n == 0)
    //            return 0;
    //        vector<int> dp(n, 0);
    //        for (int i = 0; i < n; i++) {
    //            dp[i] = 1;
    //            for (int j = 0; j < i; j++) {
    //                if (nums[j] < nums[i]) {
    //                    dp[i] = max(dp[i], dp[j] + 1);
    //                }
    //            }
    //        }
    //
    //        cout << "dp: ";
    //        for (int num: dp) {
    //            cout << num << " ";
    //        }
    //        cout<<endl;
    //
    //        return *max_element(dp.begin(), dp.end());
    //    }
    int lengthOfLIS(vector<int> &nums) {
        vector<int> p{nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            // ‘if’ initialization statements are a C++17 extension
            if (auto num = nums[i]; num > p.back()) {
                p.push_back(num);
            } else {
                auto j = lower_bound(p.begin(), p.end(), num);
                *j = num;
            }
        }
        cout << "dp: ";
        for (int num : p) {
            cout << num << " ";
        }
        cout << endl;

        return p.size();
    }
};

int main() {
    vector<int> numbers = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    Solution s;
    //    int res = Solution::lengthOfLIS(numbers);
    int res = s.lengthOfLIS(numbers);
    cout << "res: " << res << endl;

    std::vector<int> nums = {10, 20, 30, 40, 50};

    // 使用 lower_bound 查找值为 25 的元素
    auto it = std::lower_bound(nums.begin(), nums.end(), 25);

    if (it != nums.end()) {
        std::cout << "找到了元素 " << *it << std::endl;
    } else {
        std::cout << "未找到元素" << std::endl;
    }

    return 0;
}