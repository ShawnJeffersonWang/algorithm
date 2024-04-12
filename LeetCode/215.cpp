//
// Created by shawn on 24-3-4.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {

    int partition(vector<int> &nums, int l, int r) {
        int randomIndex = rand() % (r - l + 1) + l;
        swap(nums[randomIndex], nums[l]);

        int pivot = nums[l];

        int i = l + 1;
        int j = r;
        while (true) {
            while (i <= j && nums[i] < pivot) {
                i++;
            }
            while (i <= j && nums[j] > pivot) {
                j--;
            }
            if (i >= j) {
                break;
            }
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        swap(nums[l], nums[j]);
        return j;
    }

//    int partition(vector<int> &nums, int l, int r) {
//        int randomIndex = rand() % (r - l + 1) + l;
//        swap(nums[randomIndex], nums[l]);
//        // 如果此时选择左边，最后返回的是i,选择右边返回i+1
//        int pivot = nums[l];
//
//        int i = l;
//        for (int j = l + 1; j <= r; j++) {
//            if (nums[j] <= pivot) {
//                i++;
//                swap(nums[j], nums[i]);
//            }
//        }
//        swap(nums[l], nums[i]);
//        return i;
//    }


public:
    int findKthLargest(vector<int> &nums, int k) {
        srand(time(NULL));
        int target = nums.size() - k;
        int l = 0;
        int r = nums.size() - 1;
        while (true) {
            int pos = partition(nums, l, r);
            if (pos == target) {
                return nums[pos];
            } else if (pos < target) {
                l = pos + 1;
            } else {
                r = pos - 1;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int i = s.findKthLargest(nums, 4);
    cout << "i: " << i;
}