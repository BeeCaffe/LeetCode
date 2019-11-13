/***********************************************************************************************************************
 * Created by caffe on 2019/11/13.
 * 674. Longest Continuous Increasing Subsequence
 *  Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

    Example 1:

    Input: [1,3,5,4,7]
    Output: 3
    Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
    Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.

    Example 2:

    Input: [2,2,2,2,2]
    Output: 1
    Explanation: The longest continuous increasing subsequence is [2], its length is 1.

    Note: Length of the array will not exceed 10,000.
 **********************************************************************************************************************/
/**
 * solution 1 ： 双指针法
 * 略
 * 时间复杂度：O（n）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int pbeg=0,pend;
        int ans=1;
        while(pbeg<nums.size()){
            pend=pbeg+1;
            while(pend<nums.size()&&(nums[pend]-nums[pend-1]>0)) ++pend;
            ans=max(ans,pend-pbeg);
            ++pbeg;
        }
        return ans;
    }
};