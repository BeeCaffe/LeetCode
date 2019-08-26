//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * 1.dynamic programming
 *      suppose you present location is (i,j), so , the dp(i,j)=grid(i,j)+min(dp(i-1,j),dp(i,j-1))
 *      eventually return the last location, and the time complexity is O(n^2).
 */
class Solution {
public:
#define min(a,b) (a>b ? b:a)
    int minPathSum(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        vector<vector<int>> dp;
        vector<int> temp(cols,0);
        for(int i=0;i<rows;i++) dp.push_back(temp);
        dp[0][0]=grid[0][0];
        for(int i=1;i<rows;i++) dp[i][0]=grid[i][0]+dp[i-1][0];
        for(int j=1;j<cols;j++) dp[0][j]=grid[0][j]+dp[0][j-1];
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[rows-1][cols-1];
    }
};