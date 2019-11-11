/***********************************************************************************************************************
 * Created by caffe on 2019/11/6.
 * 442. Find All Duplicates in an Array
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

    Find all the elements that appear twice in this array.

    Could you do it without extra space and in O(n) runtime?

    Example:

    Input:
    [4,3,2,7,8,2,3,1]

    Output:
    [2,3]
 **********************************************************************************************************************/
/**
 * solution 1 : index下标法
 *      根据1<=a[i]<=n的特点，可以依次遍历元素，并将元素值减一作为下标值，当下标被遍历过一次便置为负数，当第二次遍历到该下标时发现已经是负
 *      数了就作为结果返回。
 * 时间复杂度：O(n)
 * 空间复杂度：O（1）
 */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();++i){
            int idx=abs(nums[i])-1;
            if(nums[idx]<0) res.push_back(idx+1);
            nums[idx]=-nums[idx];
        }
        return res;
    }
};