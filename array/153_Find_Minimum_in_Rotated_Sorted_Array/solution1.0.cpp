/***********************************************************************************************************************
 * Created by caffe on 2019/11/1.
 * 题干：
        Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
        (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
        Find the minimum element.
        You may assume no duplicate exists in the array.
 * 解法一：二分查找
 *        1)显然，当最左边小于最右边时，是单调递增序列，直接返回最左边元素
 *        2）不满足条件一就是发生了旋转，分成下面两种情况
 *              a.nums[mid]>nums[left],在左边递增部分，这是我们希望mid跳到右半部分去，采用二分查找的方法。
 *              b.nums[mid]<nums[right],在右边递增部分，向前查找最小值即可。
 * 时间复杂度：O（n）
 * 空间复杂度：O（n）
 **********************************************************************************************************************/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        int left=0,right=nums.size()-1;
        if(nums[left]<nums[right]) return nums[0];
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>=nums[left]) left=mid+1;
            if(nums[mid]<=nums[right]){
                int i=mid-1;
                while(nums[i]<nums[i+1]) i--;
                return nums[i+1];
            }
        }
        return 0;
    }
};