//
// Created by caffe on 2019/12/17.
//
/*
 * 221. 最大正方形
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
 */
//执行用时 :16 ms, 在所有 cpp 提交中击败了92.58%的用户
//内存消耗 :11 MB, 在所有 cpp 提交中击败了77.90%的用户
/**
 * solution 1 : 动态规划
 * 注意这里的题目要求是找到最大正方形并返回其面积，因此我们只需要找到最大的边长即可。
 * 我们设置一个动态规划数组dp[][]用来存储当前位置最大的正方形边长
 * 那么dp[i][j] = min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1
 * 找到其中最大的一个边长，并返回边长的平方即可。
 * 时间复杂度：O（nm）
 * 空间负载的：O（nm）
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int cols=matrix[0].size(),rows=matrix.size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        int maxlen=0;
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(matrix[i][j]=='1'){
                    if(i-1>=0&&j-1>=0) dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
                    else dp[i][j]=1;
                    maxlen = max(maxlen,dp[i][j]);
                }
            }
        }
        return maxlen*maxlen;
    }
};