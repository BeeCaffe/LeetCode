/***********************************************************************************************************************
 * Created by caffe on 2019/11/19.
 * Given an array of integers nums, write a method that returns the "pivot" index of this array.

    We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.

    If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

    Example 1:

    Input:
    nums = [1, 7, 3, 6, 5, 6]
    Output: 3
    Explanation:
    The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
    Also, 3 is the first index where this occurs.



    Example 2:

    Input:
    nums = [1, 2, 3]
    Output: -1
    Explanation:
    There is no index that satisfies the conditions in the problem statement.



    Note:

        The length of nums will be in the range [0, 10000].
        Each element nums[i] will be an integer in the range [-1000, 1000].

 **********************************************************************************************************************/
/**
 * solution 1 : two pointer
 * every time travel an element,and produce two pointer to calculate the left elements's sum and right side elements's
 * sum,if they are equal,return this element's.
 * time complexity : O(n)
 * space complexity : O(1)
 */
 //very slow
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pleft,pright;
        if(nums.empty()) return -1;
        if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size();++i){
            int sumleft=0,sumright=0;
            pleft=i-1;
            pright=i+1;
            while(pleft>=0) sumleft+=nums[pleft--];
            while(pright<nums.size()) sumright+=nums[pright++];
            if(sumleft==sumright) return i;
        }
        return -1;
    }
};