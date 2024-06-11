#include <bits/stdc++.h>
using namespace std;
// 反转字符串中的单词
class Solution {
   public:
    void removeExtraSpaces(string& s) {
        int slowIndex = 0, fastIndex = 0;
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }
        for (; fastIndex < s.size(); fastIndex++) {
            if (fastIndex - 1 > 0 && s[fastIndex] == ' ' &&
                s[fastIndex] == s[fastIndex - 1]) {
                continue;
            } else {
                s[slowIndex++] = s[fastIndex];
            }
        }
        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') {
            s.resize(slowIndex - 1);
        } else {
            s.resize(slowIndex);
        }
    }

    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        int end = 0;
        bool entry = false;
        for (int i = 0; i < s.size(); i++) {
            if ((!entry) || (s[i] != ' ' && s[i - 1] == ' ')) {
                start = i;
                entry = true;
            }
            if (entry && s[i] == ' ' && s[i - 1] != ' ') {
                end = i - 1;
                entry = false;
                reverse(s, start, end);
            }
            if (entry && (i == (s.size() - 1)) && s[i] != ' ') {
                end = i;
                entry = false;
                reverse(s, start, end);
            }
        }
        return s;
    }
};