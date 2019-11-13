/***********************************************************************************************************************
 * Created by caffe on 2019/11/13.
 * 665. Non-decreasing Array
 *  Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

    We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

    Example 1:

    Input: [4,2,3]
    Output: True
    Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

    Example 2:

    Input: [4,2,1]
    Output: False
    Explanation: You can't get a non-decreasing array by modify at most one element.
 **********************************************************************************************************************/
/**
 * solution 1 : 模式匹配算法
 * 依次检测数组的每一个位置，看它是否符合递增的要求，如果不符合将其换成它的前一个元素，继续向后检测，如果需要改变的元素个数大于2的话就return
 * false。
 * 时间复杂度：O（n2）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for(int i=1;i<nums.size();++i){
            if(nums[i]<nums[i-1]){
                int oldval=nums[i-1];
                nums[i-1]=nums[i];
                if(isIncrease(nums)) return true;
                nums[i-1]=oldval;
                nums[i]=oldval;
                if(isIncrease(nums)) return true;
                else return false;
            }
        }
        return true;
    }
    bool isIncrease(vector<int> &nums){
        for(int i=1;i<nums.size();++i){
            if(nums[i]<nums[i-1]) return false;
        }
        return true;
    }
};