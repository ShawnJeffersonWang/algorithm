#include <bits/stdc++.h>
using namespace std;
// 有效的括号
class Solution {
   public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st.push(')');
            else if (s[i] == '[')
                st.push(']');
            else if (s[i] == '{')
                st.push('}');
            else if (st.empty() || s[i] != st.top())
                return false;
            else
                st.pop();
        }
        return st.empty();
    }
};