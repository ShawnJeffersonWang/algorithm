//
// Created by shawn on 24-3-8.
//
#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> queMin;
    priority_queue<int, vector<int>, greater<int>> queMax;

    MedianFinder() {

    }

    void addNum(int num) {
        if (queMax.size() == queMin.size()) {
            queMin.push(num);
            queMax.push(queMin.top());
            queMin.pop();
        } else {
            queMax.push(num);
            queMin.push(queMax.top());
            queMax.pop();
        }
    }

    double findMedian() {
        if (queMax.size() > queMin.size()) {
            return queMax.top();
        }
        return (queMin.top() + queMax.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */