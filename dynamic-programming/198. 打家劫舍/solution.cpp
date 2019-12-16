
//
// Created by caffe on 2019/12/16.
//
/*
 * 198. 打家劫舍
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 */
/**
 * solution 1 : 动态规划
 * 假设dp[i]为前i天所能够偷盗的最大的钱数，那么显然
 * 第一天：dp[0]=nums[0]
 * 第二天：dp[1]=max(nums[0],nums[1])
 * 第i天：dp[i]=max(dp[i-2]*nums[i],dp[i-1])，因为对于第i天可能的选择有两种，偷和不偷，偷则为前i-2天最大
 * 的结果乘以nums[i]，不偷则为前i-1天的最大结果就可以了。另外注意一个问题，由于每次对于第i天都有考虑偷或则不偷的
 * 情况，所以可以确保到i为止都是最大的情况。
 * 时间复杂度：O（n）
 * 空间复杂度：O（n）
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(nums.empty()) return 0;
        if(n<2) return nums[0];
        vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;++i){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[n-1];
    }
};

//执行用时 :0 ms, 在所有 cpp 提交中击败了100.00%的用户
//内存消耗 :8.6 MB, 在所有 cpp 提交中击败了80.45%的用户
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(nums.empty()) return 0;
        if(n<2) return nums[0];
        int pre_pre=nums[0],pre=max(nums[0],nums[1]);
        for(int i=2;i<n;++i){
            int cur=max(pre_pre+nums[i],pre);
            pre_pre=pre;
            pre=cur;
        }
        return pre;
    }
};