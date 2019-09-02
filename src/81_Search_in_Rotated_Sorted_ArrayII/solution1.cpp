//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * @name binary search
 * @brief this is a follow up problem to "Search in Rotated Sorted Array",where nums may contains duplicates.
 *        we'd better to notice that when nums like [1,3,1,1], if target=3,it can divide to both left and right
 *        side.The solution is very simple ,just need to left move 'right' until it is able to divide its side.
 *        the time complexity is also O(logn).
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1,sz=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target || nums[left]== target || nums[right]==target) return true;
            if(nums[mid]<nums[right]){
                if(target<nums[right]){
                    if(nums[mid]<target) left=mid+1;
                    else right=mid-1;
                }else{
                    left=mid+1;
                }
            }else if(nums[mid]>nums[right]){
                if(target>nums[right]){
                    if(nums[mid]<target) left=mid+1;
                    else right=mid-1;
                }else{
                    right=mid-1;
                }
            }else{
                --right;
            }
        }
        return false;
    }
};