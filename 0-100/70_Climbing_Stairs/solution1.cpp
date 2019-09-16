//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//

/**
 * 1. Dynamic programming
 *      there is a formula about this problem ,d(i)=d(i-1)+d(i-2),because, if you suppose to go location i
 *      you can jump 2 steps from i-2, or jump 1 step from i-1.The time complexity is O(n).
 */
class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        vector<int> dp(n,0);
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
};