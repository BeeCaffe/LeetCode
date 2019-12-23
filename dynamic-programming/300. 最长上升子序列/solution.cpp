
//
// Created by caffe on 2019/12/17.
//
/*
 * 300. 最长上升子序列
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 */
/**
 * solution 1 : 动态规划
 * 时间复杂度：O(n2)
 * 空间复杂度：O（n）
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return n;
        vector<int> dp(n,0);
        int ans=0;
        dp[0]=1;
        for(int i=1;i<n;++i){
            int maxprev=0;
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j]){
                    maxprev=max(maxprev,dp[j]);
                }
            }
            dp[i]=maxprev+1;
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};

