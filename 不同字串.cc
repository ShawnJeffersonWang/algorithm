#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s="0100110001010001";
    vector<string> result;
    for(int i=0;i<s.length();i++){
        for(int j=i;j<s.length();j++){
            string tmp=s.substr(i,j-i+1);
            if(find(result.begin(),result.end(),tmp)==result.end()){
                result.push_back(tmp);
            }
        }
    }
    cout << result.size();
}