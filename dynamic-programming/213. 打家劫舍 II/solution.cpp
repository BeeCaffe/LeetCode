
//
// Created by caffe on 2019/12/16.
//
/*
 * 213. 打家劫舍 II
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
   给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 */
/**
 * solution 1 ： 动态规划
 * 这里实际上和上一个题目的区别在于，偷了第一个就不能够偷最后一个，偷了最后一个就不能够偷第一个
 * 因此，只需要分别将第一个和最后一个排除，再分别求他们的最大值就ok了
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
//执行用时 :0 ms, 在所有 cpp 提交中击败了100.00%的用户
//内存消耗 :8.7 MB, 在所有 cpp 提交中击败了73.54%的用户
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(nums.empty()) return 0;
        if(n<2) return nums[0];

        int max1,max2;
        vector<int> num1(nums.begin(),--nums.end());
        vector<int> num2(++nums.begin(),nums.end());
        max1=rob_circur(num1);
        max2=rob_circur(num2);
        return max(max1,max2);
    }

    int rob_circur(vector<int> &nums){
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

