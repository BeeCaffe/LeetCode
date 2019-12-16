/***********************************************************************************************************************
 * Created by caffe on 2019/12/11.
 * 53. 最大子序和
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

    示例:

    输入: [-2,1,-3,4,-1,2,1,-5,4],
    输出: 6
    解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 **********************************************************************************************************************/
/**
 * solution 1 : 二维动态规划
 * 建立一个二维数组dp[i][j]来记录[i,j]区间的所有元素之和，然后返回最大的即可。
 * 其中递推关系为dp[i][j]=dp[i][j-1]+nums[j]，需要注意的是，应当保证j-1>=i即j-i>=1。
 * 时间复杂度：O（n2）
 * 空间复杂度：O（n2）
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0;j<n;++j){
            for(int i=0;i<=j;++i){
                if(i==j){
                    dp[i][j]=nums[i];
                }else if(j-i>=1){
                    dp[i][j]=dp[i][j-1]+nums[j];
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
/**
 * solution 2 ： 一维动态规划
 * 使用数组dp[i]记录前面i个元素的最大和，可以有递推关系dp[i]=max(dp[i-1]+nums[i],nums[i])。
 * 时间复杂度：O（n）
 * 空间复杂度：O（n）
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        int ans=INT_MIN;
        dp[0]=nums[0];
        ans = dp[0];
        for(int i=1;i<n;++i){
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};