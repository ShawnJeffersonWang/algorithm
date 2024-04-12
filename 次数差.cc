//
// Created by shawn on 24-4-12.
//

#include<bits/stdc++.h>

using namespace std;

int main() {
//    int hash_arr[256] = {0};
    vector<int> hash_arr(256, 0);
//    char s[1010];
    string s;
//    scanf("%s", s);
    cin >> s;
//    for (int i = 0; i < s.size(); i++) {
//        hash_arr[s[i]]++;
//    }
    for (char c: s) {
        hash_arr[c]++;
    }
    int max = 0, min = 1000;
    for (int i = 'a'; i <= 'z'; i++) {
        if (hash_arr[i] > max) max = hash_arr[i];
        if (hash_arr[i] < min && hash_arr[i]) min = hash_arr[i];
    }
    cout << max - min;
}