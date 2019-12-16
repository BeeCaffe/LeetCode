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
using namespace std;
class Solution {
public:
    static int numDecodings(string s) {
        int n=s.size();
        if(n<2) return 1;
        vector<int> dp(n,0);
        dp[0]==1;
        if((s[0]-'0')>9) dp[1]=1;
        else dp[1]=2;
        for(int i=2;i<n;++i){
            if((s[i]-'0'>9)) dp[i]=dp[i-1];
            else dp[i]=dp[i-2]+dp[i-1];
        }
        return dp[n-1];
    }
};
int main() {
    string str="226";
    Solution::numDecodings(str);
    return 0;
}