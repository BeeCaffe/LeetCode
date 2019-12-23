#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:
    static string multiply(string num1, string num2) {
        int n1=num1.size(),n2=num2.size();
        string ans(n1+n2,'0');
        int res=0;
        for(int i=n1-1;i>=0;--i){
            res=0;
            for(int j=n2-1;j>=0;--j){
                int pre = ans[i+j+1]-'0';
                int cur = (num1[i]-'0')*(num2[j]-'0')+res+pre;
                ans[i+j+1] = cur%10+'0';
                res = cur/10;
            }
        }
        for(int i=0;i<ans.size();++i){
            if(ans[i]!='0'){
                ans = ans.substr(i,ans.size()-i);
                break;
            }
        }
        return ans;
    }
};
int main()
{
    string  s = "123";
    string s1="456";
    Solution::multiply(s,s1);
    return 0;
}