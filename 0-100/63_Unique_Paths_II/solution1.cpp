//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * 1。动态规划
 *      和62题一样，不同的是当出现阻碍的时候，这个点的dp为0，也就是到不了这里。同样时间复杂度为O（n^2）.
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows=obstacleGrid.size(),cols=obstacleGrid[0].size();
        vector<vector<long>> dp;
        vector<long> temp(cols,0);
        for(int i=0;i<rows;i++) dp.push_back(temp);

        if(obstacleGrid[0][0]!=1) dp[0][0]=1;
        else return 0;

        for(int i=1;i<rows;i++){
            if(obstacleGrid[i][0]!=1) dp[i][0]=dp[i-1][0];
            else dp[i][0]=0;
        }
        for(int j=1;j<cols;j++){
            if(obstacleGrid[0][j]!=1) dp[0][j]=dp[0][j-1];
            else dp[0][j]=0;
        }

        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(obstacleGrid[i][j]!=1)
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                else dp[i][j]=0;
            }
        }
        return dp[rows-1][cols-1];
    }
};