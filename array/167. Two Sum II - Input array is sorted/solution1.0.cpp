/***********************************************************************************************************************
 * Created by caffe on 2019/11/1.
 * 题干：
        Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
        The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
        Note:
            Your returned answers (both index1 and index2) are not zero-based.
            You may assume that each input would have exactly one solution and you may not use the same element twice.
 * 解法一：双指针问题
 *        由于整个数组是有序数组，因此直接前加后，当小于target时，说明需要左边的指针像右移动，当大于target，说明右边的指针需要向左移动
 **********************************************************************************************************************/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret(2,-1);
        int left = 0;
        int right = numbers.size()-1;
        while(left < right){
            int tmp = numbers[left]+numbers[right];
            if(tmp == target){
                ret[0] = left+1;
                ret[1] = right+1;
                return ret;
            }
            else if(tmp < target)   left ++;
            else  right --;
        }
        return ret;
    }
};