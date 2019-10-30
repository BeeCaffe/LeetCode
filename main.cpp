#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    static bool isPalindrome(string s) {
        if(s.size()==0 || s.size()==1) return true;
        vector<char> str;
        for(int i=0;i<s.size();++i){
            if((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z')){
                str.push_back(tolower(s[i]));
            }
        }
        vector<char> strrev=str;
        reverse(strrev.begin(),strrev.end());
        for(int i=0;i<str.size();++i)
            if(str[i]!=strrev[i]) return false;
        return true;
    }
};

int main() {
    string str="OP";
    cout<<Solution::isPalindrome(str)<<endl;
    return 0;
}