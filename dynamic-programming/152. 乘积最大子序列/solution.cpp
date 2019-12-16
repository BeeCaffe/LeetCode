
//
// Created by caffe on 2019/12/16.
//
/*
 * solution 1 : 动态规划
 * 要求得当前最大得成绩，同时由于数组中有负数存在，所以实际上当前最大得数应该是:
 * dp[i]=max(nums[i]*pre_max,nums[i]*pre_min,nums[i])
 * 时间复杂度：O（n）
 * 空间复杂度：O(n2)
 */
//执行用时 :0 ms, 在所有 cpp 提交中击败了100.00%的用户
//内存消耗 :9.1 MB, 在所有 cpp 提交中击败了34.11%的用户
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp_max(n,0);
        vector<int> dp_min(n,0);
        dp_max[0]=nums[0];
        dp_min[0]=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;++i){
            dp_max[i]=max(nums[i],max(dp_max[i-1]*nums[i],dp_min[i-1]*nums[i]));
            dp_min[i]=min(nums[i],min(dp_min[i-1]*nums[i],dp_max[i-1]*nums[i]));
            ans=max(ans,dp_max[i]);
        }
        return ans;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pre_max=nums[0];
        int pre_min=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;++i){
            int cur_max=max(nums[i],max(pre_max*nums[i],pre_min*nums[i]));
            int cur_min=min(nums[i],min(pre_max*nums[i],pre_min*nums[i]));
            ans=max(ans,cur_max);
            pre_max=cur_max;
            pre_min=cur_min;
        }
        return ans;
    }
};
/**
 * solution 2 ： 双指针法
 * 即找到所有可能，并找出其中最大得一个即可。这里的连乘可能会造成int溢出的问题，但是好像leetcode上的例子
 * 没有涉及到溢出的问题。
 * 时间复杂度：O(n2)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int left=0,right;
        int ans=nums[0];
        while(left<n){
            right=left;
            int prd=1;
            while(right<n){
                prd*=nums[right++];
                ans=max(ans,prd);
            }
            ++left;
        }
        return ans;
    }
};
