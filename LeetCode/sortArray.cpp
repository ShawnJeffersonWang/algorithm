//
// Created by shawn on 24-3-4.
//

//#include "sortArray.h"
#include <bits/stdc++.h>

using namespace std;

class Solution {

    int partition(vector<int> &nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; j++) {
            if (nums[j] <= pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);

        cout << "partition printArray: ";
        printArray(nums);
        cout << endl;
        return i + 1;
    }

    int randomized_partition(vector<int> &nums, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        cout << "rand i: " << i << endl;
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }

    void randomized_quicksort(vector<int> &nums, int l, int r) {
        if (l < r) {
            int pos = randomized_partition(nums, l, r);
            randomized_quicksort(nums, l, pos - 1);
            randomized_quicksort(nums, pos + 1, r);
        }
    }

public:
    vector<int> sortArray(vector<int> &nums) {
//        std::sort(nums.begin(), nums.end()); // 使用std::sort函数对nums进行排序
//        return nums; // 返回排序后的nums
        srand((unsigned) time(NULL));
        randomized_quicksort(nums, 0, (int) nums.size() - 1);
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
//    vector<int> nums = {2, 4, 1, 3, 5, 6, 7, 8};
    const vector<int> &vector = s.sortArray(nums);
    s.printArray(vector);
    cout << endl;
}