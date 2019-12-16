/***********************************************************************************************************************
 * Created by caffe on 2019/12/11.
 * 63. 不同路径 II
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

    机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

    现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 **********************************************************************************************************************/
/**
 * solution 1 ： 二维动态规划
 * 和上一题差不多，只是对于有阻碍的地方dp[i][j]应该等于0才对。
 * 时间复杂度：O（n2）
 * 空间复杂度：O（n2）
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows=obstacleGrid.size(),cols=obstacleGrid[0].size();
        vector<vector<long>> dp(rows,vector<long>(cols,0));
        dp[0][0]=1;
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;continue;
                }
                if(i-1>=0&&j-1>=0) dp[i][j]=dp[i-1][j]+dp[i][j-1];
                else if(j==0&&i-1>=0) dp[i][j]=dp[i-1][j];
                else if(i==0&&j-1>=0) dp[i][j]=dp[i][j-1];
            }
        }
        return dp[rows-1][cols-1];
    }
};