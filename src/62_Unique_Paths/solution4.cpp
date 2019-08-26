//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * 4。动态规划的非递归算法
 *      把dp中的每个位置的值代表有多少种方法可以走到当前位置dp[i][j]=dp[i-1][j]+dp[i][j-1]，这样只需要确定每一个的值就可以了。
 *      这里的时间复杂度为O(n^2).可以AC。
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> temp(m,0);
        vector<vector<int>> dp;
        for(int i=0;i<n;i++){
            dp.push_back(temp);
        }
        dp[0][0]=1;
        for(int row=1;row<n;row++) dp[row][0]=dp[row-1][0];
        for(int col=1;col<m;col++) dp[0][col]=dp[0][col-1];
        for(int row=1;row<n;row++){
            for(int col=1;col<m;col++){
                dp[row][col]=dp[row-1][col]+dp[row][col-1];
            }
        }
        return dp[n-1][m-1];
    }
};