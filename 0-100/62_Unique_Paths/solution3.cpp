//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//

/**
 * 3.带记录的递归算法
 *      在2的方法中，重复计算了很多内容，这里考虑将到达过的位置记录下来。
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> temp(m,0);
        vector<vector<int>> dp;
        for(int i=0;i<n;i++){
            dp.push_back(temp);
        }
        return go(m,n,dp);
    }

    int go(int row,int col,vector<vector<int>>& dp){
        if(row==0&&col==0) return 1;
        if(dp[row][col]!=0) return dp[row][col];
        if(row==0){
            dp[row][col]=go(row,col-1,dp);
        }else if(col==0){
            dp[row][col] go(row-1,col,dp);
        }else{
            dp[row][col] go(row-1,col,dp)+go(row,col-1,dp);
        }
        return dp[row][col];
    }
};