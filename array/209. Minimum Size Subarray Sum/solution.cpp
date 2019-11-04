/***********************************************************************************************************************
 * Created by caffe on 2019/11/1.
 * 题干：
 *      Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray
 *      of which the sum ≥ s. If there isn't one, return 0 instead.
 **********************************************************************************************************************/
/**
 * solution 1：dfs(深度优先搜索)
 *      这是一个错误的思路，因为深度优先搜索的顺序不一定会是连续的和题意是不符合的。
 */

/**
 * solution 1：双指针法
 *      用两个指针right和left来记录连续子数组的左右两个边界位置，它们都从0开始，right指针先🤜移动，直到left到right的和比sum大停止，算出长度。
 *      此时，sum减去left的值，并且left向右边移动，再找到和大于sum的子序列。
 * 时间复杂度：O（n）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0) return 0;
        int left=0,right=0,sz=nums.size(),sum=0,minlen=sz+1;
        while(right<sz){
            while(right<sz && sum<s) sum+=nums[right++];
            while(sum>=s){
                minlen=min(minlen,right-left);
                sum-=nums[left++];
            }
        }
        return minlen==sz+1 ? 0:minlen;
    }
};

/**
 * solution2:binary search
 *      建立一个比原数组长一位的sums数组，其中sums[i]表示sum数组中[0,i-1]的和，遍历sums数组，对于每一个sums[i]找到和大于sums[i]+s的位
 *      置，算出长度，找到最小长度即可。
 * 时间复杂度：O（nlog（n））
 * 空间复杂度：O（n）
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> sums(nums.size()+1,0);
        int minlen=INT_MAX;
        for(int i=1;i<nums.size();++i) sums[i]=sums[i-1]+nums[i-1];
        for(int i=0;i<nums.size();++i){
            int left=i+1,right=nums.size(),target=sums[i]+s;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(sums[mid]>=target) right=mid-1;
                else left=mid+1;
            }
            if(left==nums.size()+1) break;
            minlen=min(minlen,left-i) ;
        }
        return minlen==INT_MAX ? 0:minlen;
    }
};