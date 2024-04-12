//
// Created by shawn on 24-3-14.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) return -1;
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) >> 1;
            if (nums[mid] == target) {
                return mid;
            }
            // 前半部分有序，因此可以快速判断target在不在里面
            if (nums[start] <= nums[mid]) {
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int res = s.search(nums, 0);
    cout << "res: " << res << endl;
}