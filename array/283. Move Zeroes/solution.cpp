/***********************************************************************************************************************
 * Created by caffe on 2019/11/5.
 * 283. Move Zeroes
   Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
    Example:
    Input: [0,1,0,3,12]
    Output: [1,3,12,0,0]
    Note:
        You must do this in-place without making a copy of the array.
        Minimize the total number of operations.
 **********************************************************************************************************************/
 /**
  * solution1 ： Space Optimal（空间最优化）
  *         利用不为0的个数始终少于或等于数组中的元素总个数，直接将不为0的前移，再将0添加在最后即可。
  * 时间复杂度：O（n）
  * 空间复杂度：O（1）
  */
 class Solution {
 public:
     void moveZeroes(vector<int>& nums) {
         int idx=0;
         for(int i=0;i<nums.size();++i){
             if(nums[i]!=0) nums[idx++]=nums[i];
         }
         for(int i=idx;i<nums.size();++i) nums[i]=0;
     }
 };