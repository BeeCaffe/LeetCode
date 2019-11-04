/***********************************************************************************************************************
 * Created by caffe on 2019/11/4.
 * 题干：
 *      Given an array of integers, find if the array contains any duplicates.
        Your function should return true if any value appears at least twice in the array, and it should return false if
        every element is distinct.
 **********************************************************************************************************************/
/**
 * solution1：
 *      先对数组进行排序，再依次遍历判断是否有重复。
 * 时间复杂度：O(nlog(2n))
 * 空间复杂度：O（1）；
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty()) return false;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();++i){
            if(nums[i]==nums[i-1]) return true;
        }
        return false;
    }
};