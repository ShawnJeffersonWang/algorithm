//
// Created by 86138 on 2024/5/19.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int removeDuplicates(vector<int> &nums) {
        size_t n = nums.size();
        if (n <= 2) {
            return (int) n;
        }
        int fast = 2, slow = 2;
        while (fast < n) {
            if (nums[fast] != nums[slow - 2]) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int len = Solution::removeDuplicates(nums);
    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}