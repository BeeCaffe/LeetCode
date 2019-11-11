/***********************************************************************************************************************
 * Created by caffe on 2019/11/11.
 * 581. Shortest Unsorted Continuous Subarray
 * Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

    You need to find the shortest such subarray and output its length.

    Example 1:

    Input: [2, 6, 4, 8, 10, 9, 15]
    Output: 5
    Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

    Note:

        Then length of the input array is in range [1, 10,000].
        The input array may contain duplicates, so ascending order here means <=.
 **********************************************************************************************************************/
/**
 * solution 1 ： 双指针法
 * 定义两个指针pst和pend分别指向数组的开始和结束位置，pst向右走，pend向左走，当pst发现它不是最小的时候停止，当pend发现它不是最大的时候
 * ，pend停止。用pend-pst就可以得到最长的需要排序的子序列，
 * 时间复杂度：O（n2）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int pst=0,pend=nums.size();
        while(pst<pend && ismin(nums,nums[pst],pst+1,pend)) ++pst;
        while(pst<pend && ismax(nums,nums[pend-1],pst,pend-1)) --pend;
        return pend-pst;
    }

    bool ismin(vector<int> &nums,int key,int left,int right){
        for(int i=left;i<right;++i){
            if(key>nums[i]) return false;
        }
        return true;
    }
    bool ismax(vector<int> &nums,int key,int left,int right){
        for(int i=right-1;i>=left;--i){
            if(key<nums[i]) return false;
        }
        return true;
    }
};