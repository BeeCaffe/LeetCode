/***********************************************************************************************************************
 * Created by caffe on 2019/12/11.
 * 64. 最小路径和
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

    说明：每次只能向下或者向右移动一步。
 **********************************************************************************************************************/
/**
 * solution 1 ： 二维动态规划
 * 和机器人走路的题类似，只是递推关系需要变一下。
 * 时间复杂度：O（n2）
 * 空间复杂度：O（n2）
 */
//执行用时 :12 ms, 在所有 cpp 提交中击败了63.95% 的用户
//内存消耗 :10.8 MB, 在所有 cpp 提交中击败了71.67%的用户
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        dp[0][0]=grid[0][0];
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(i-1>=0&&j-1>=0) dp[i][j]=min(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j]);
                else if(j==0&&i-1>=0) dp[i][j]=dp[i-1][j]+grid[i][j];
                else if(i==0&&j-1>=0) dp[i][j]=dp[i][j-1]+grid[i][j];
            }
        }
        return dp[rows-1][cols-1];
    }
};