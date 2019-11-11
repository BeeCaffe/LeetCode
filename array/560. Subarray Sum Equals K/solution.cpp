/***********************************************************************************************************************
 * Created by caffe on 2019/11/11.
 * 560. Subarray Sum Equals K
 * Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

    Example 1:

    Input:nums = [1,1,1], k = 2
    Output: 2

    Note:

        The length of the array is in range [1, 20,000].
        The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
 **********************************************************************************************************************/
/**
 * solution 1 : 双指针法
 * 建立两个指针pst，pend，pst指向数组每次开始的位置，然后pend向后移动，当结果为sum时，pst向右移动一个位置，pend回到pst的位置后重新开始向
 * 右搜索。
 * 时间复杂度：O（n2）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        int pst=0,pend=pst+1;
        int res=0,sz=nums.size();
        while(pst<sz){
            int sum=nums[pst];
            if(sum==k){
                ++res;
            }
            while(pend<sz){
                sum+=nums[pend];
                if(sum==k){
                    ++res;
                }
                ++pend;
            }
            pst++;
            pend=pst+1;
        }
        return res;
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        int pst=0,pend=pst+1;
        int res=0,sz=nums.size();
        for(int i=0;i<sz;++i){
            int sum=nums[i];
            if(sum==k) ++res;
            for(int j=i+1;j<sz;++j){
                sum+=nums[j];
                if(sum==k) ++res;
            }
        }
        return res;
    }
};