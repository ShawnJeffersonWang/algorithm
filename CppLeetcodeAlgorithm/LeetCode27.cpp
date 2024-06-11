#include <bits/stdc++.h>
using namespace std;
// 移除元素
// 暴力解法
// class Solution {
//    public:
//     int removeElement(vector<int>& nums, int val) {
//         int size = nums.size();
//         for (int i = 0; i < size; i++) {
//             if (nums[i] == val) {
//                 for (int j = i + 1; j < size; j++) {
//                     nums[j - 1] = nums[j];
//                 }
//                 i--;  // 循环结束会i++,导致如果是连着的val元素会忽略
//                 size--;
//             }
//         }
//         return size;
//     }
// };

// 双指针法
class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != val) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};