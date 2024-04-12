//
// Created by shawn on 24-3-7.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    // 请在此输入您的代码
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    std::sort(nums.begin(), nums.end());
    std::queue<int> queue;

    long res = 0;
    bool flag = false;
    for (int i = n - 1; i >= 0; i--) {
        if (!queue.empty() && nums[i] <= queue.front()) {
            queue.pop();
        } else {
            if (flag) {
                queue.push(nums[i] / 2);
                flag = false;
            } else {
                flag = true;
            }
            res += nums[i];
        }
    }
    std::cout << res << std::endl;
    return 0;
}