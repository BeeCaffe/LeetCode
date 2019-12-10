/***********************************************************************************************************************
 * Created by caffe on 2019/12/10.
 * 1277. 统计全为 1 的正方形子矩阵
 * 给你一个 m * n 的矩阵，矩阵中的元素不是 0 就是 1，请你统计并返回其中完全由 1 组成的 正方形 子矩阵的个数。
 **********************************************************************************************************************/
/**
 * solution 1 : 动态规划
 * 时间复杂度：O（mn）
 * 空间复杂度：O（mn）
 */
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size();
        vector<vector<int>> f(rows,vector<int>(cols,0));
        int ans=0;
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(i==0||j==0) f[i][j]=matrix[i][j];
                else if(matrix[i][j]==0) f[i][j]==0;
                else f[i][j]=min(min(f[i][j-1],f[i-1][j]),f[i-1][j-1])+1;
                ans+=f[i][j];
            }
        }
        return ans;
    }
};