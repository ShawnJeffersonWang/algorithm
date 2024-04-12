//
// Created by shawn on 24-4-12.
//
#include <iostream>

using namespace std;


int main() {
    long long s = 0;
    long long sum = 0;
    int a[20000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    for (int i = 0; i < n; i++) {
        sum += a[i] * (s - a[i]);
    }
    cout << sum / 2;
}