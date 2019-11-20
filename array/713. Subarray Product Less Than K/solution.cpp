/***********************************************************************************************************************
 * Created by caffe on 2019/11/14.
 * 713. Subarray Product Less Than K
 * Your are given an array of positive integers nums.

    Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

    Example 1:

    Input: nums = [10, 5, 2, 6], k = 100
    Output: 8
    Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
    Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

    Note:
    0 < nums.length <= 50000.
    0 < nums[i] < 1000.
    0 <= k < 10^6.
 **********************************************************************************************************************/
/**
 * error solution 1 : two pointer
 * declare two pointer of pbeg and pend,pend move one step to right each time and calculate the product of previous elements.
 * if the product is less than k ,count++,until the product bigger than or equal to k.Then pbeg shift one step.
 * time complexity : O(n)
 * space complexity : O(1)
 */
 //Can't AC,Time limit exceed.
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        int pbeg=0,pend;
        int ans=0;
        while(pbeg<nums.size()){
            pend=pbeg;
            int accum=1;
            while(pend<nums.size()){
                accum*=nums[pend++];
                if(accum<k) ++ans;
                else break;
            }
            ++pbeg;
        }
        return ans;
    }
};
/**
 * error solution 2 : binary search
 * the product of elements in array usually are very big, can not store in int or long.(unlike add)
 */
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(nums.empty() || k==0) return 0;
        int ans=0;
        vector<long> acc(nums.size()+1,1);
        for(int i=1;i<acc.size();++i){
            acc[i]=acc[i-1]*nums[i-1];
        }
        for(int i=0;i<acc.size();++i){
            int left=i,right=acc.size()-1;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(acc[mid]/acc[i]>=k) right=mid-1;
                else left=mid+1;
            }
            ans+=right-i;
        }
        return ans<0 ? 0:ans;
    }
};
/**
 * error solution 3 : dfs
 * time complexity : O(nlog2n)
 * space complexity : O(1)
 */
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(nums.empty() || k==0) return 0;
        int ans=0;
        for(int i=0;i<nums.size();++i){
            int count=0;
            assist(nums,k,1,i,count);
            ans+=count;
        }
        return ans;
    }
    void assist(vector<int> &nums,int &k,int acc,int index,int &count){
        if(index>=nums.size()) return;
        if(acc*nums[index]<k){
            assist(nums,k,acc*nums[index],index+1,++count);
        }
        else return;
    }
};
/**
 * solution 1 : silding window
 * For each right, call opt(right) the smallest left so that the product of the subarray nums[left] * nums[left + 1] *
 * ... * nums[right] is less than k. opt is a monotone increasing function, so we can use a sliding window.
 * Our loop invariant is that left is the smallest value so that the product in the window prod = nums[left] * nums[left
 * + 1] * ... * nums[right] is less than k.
 *For every right, we update left and prod to maintain this invariant. Then, the number of intervals with subarray product
 *less than k and with right-most coordinate right, is right - left + 1. We'll count all of these for each value of right.
 *time complexity : O(n)
 * space complexity : O(1)
 * /

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int prod=1,ans=0,left=0;
        for(int right=0;right<nums.size();++right){
            prod*=nums[right];
            while(prod>=k) prod/=nums[left++];
            ans+=right-left+1;
        }
        return ans;
    }
};