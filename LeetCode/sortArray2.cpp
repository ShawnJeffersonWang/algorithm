//
// Created by shawn on 24-3-4.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> tmp;

    void mergeSort(vector<int> &nums, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) >> 1;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int i = l, j = mid + 1;
        int cnt = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[cnt++] = nums[i++];
            } else {
                tmp[cnt++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[cnt++] = nums[i++];
        }
        while (j <= r) {
            tmp[cnt++] = nums[j++];
        }
        for (int i = 0; i < r - l + 1; i++) {
            nums[i + l] = tmp[i];
        }
    }

public:
    vector<int> sortArray(vector<int> &nums) {
        tmp.resize((int) nums.size(), 0);
        mergeSort(nums, 0, (int) nums.size() - 1);
        return nums;
    }

    void printArray(const vector<int> &nums) {
        for (int item: nums) {
            cout << item << " ";
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 8, 4, 1, 3, 5, 6, 7};
    const vector<int> &vector = s.sortArray(nums);
    s.printArray(vector);
}