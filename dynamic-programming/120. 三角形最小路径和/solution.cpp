/***********************************************************************************************************************
 * Created by caffe on 2019/12/13.
 * 120. 三角形最小路径和
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

    例如，给定三角形：

    [
         [2],
        [3,4],
       [6,5,7],
      [4,1,8,3]
    ]

    自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 **********************************************************************************************************************/
/**
 * solution 1 : 动态规划
 * 采用自底向上进行动态规划，可以求出最短的路径。
 * 状态转移方程为：dp[i][j]=dp[i][j]+min(dp[i+1][j],dp[i+1][j+1])
 * 时间复杂度：O（n2）
 * 空间复杂度：O（n2）
 */
//执行用时 :8 ms, 在所有 cpp 提交中击败了71.94% 的用户
//内存消耗 :9.7 MB, 在所有 cpp 提交中击败了85.53%的用户
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows=triangle.size();
        vector<vector<int>> dp(triangle);
        for(int i=rows-2;i>=0;--i){
            for(int j=0;j<triangle[i].size();++j){
                dp[i][j]+=min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};
/**
 * 解法一的改进，只需要使用三角形的两层就可以完成dp
 * 时间复杂度：O（n2）
 * 空间复杂度：O（n）
 */
//执行用时 :4 ms, 在所有 cpp 提交中击败了97.07% 的用户
//内存消耗 :9.7 MB, 在所有 cpp 提交中击败了81.45%的用户
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows=triangle.size(),maxcols=triangle[rows-1].size();
        vector<int> lastlevel(triangle[rows-1]);
        vector<int> curlevel;
        for(int i=rows-2;i>=0;--i){
            curlevel=triangle[i];
            for(int j=0;j<curlevel.size();++j){
                curlevel[j]+=min(lastlevel[j],lastlevel[j+1]);
            }
            lastlevel=curlevel;
        }
        return lastlevel[0];
    }
};

/**
 * solution 2 ： dfs
 * 遍历所有路径，找到最短的那一个就行，但是时间复杂度过高。
 * 时间复杂度：O（）
 * 空间复杂度：O（）
 */
 //Time Limit Exceed
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans=INT_MAX;
        mininum(triangle,ans,0,0,0);
        return ans;
    }
    void mininum(vector<vector<int>> &triangle,int &ans,int path,int level,int index){
        if(level>triangle.size()-1){
            ans=min(ans,path);return;
        }
        if(index<triangle[level].size()) {
            mininum(triangle,ans,path+triangle[level][index],level+1,index);
            mininum(triangle,ans,path+triangle[level][index],level+1,index+1);
        }
    }
};