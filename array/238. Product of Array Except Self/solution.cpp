/***********************************************************************************************************************
 * Created by caffe on 2019/11/5.
 * 238. Product of Array Except Self
   Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
   Example:

   Input:  [1,2,3,4]
   Output: [24,12,8,6]

   Note: Please solve it without division and in O(n).

   Follow up:
   Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
 **********************************************************************************************************************/
/**
 * solution1 : 左右乘积数组
 *      由于不能用出发，且时间复杂度为O（n），因此对于每一个数，要是预先知道其左边和右边的乘积那么就简单多了。因此，建立两个数组，遍历原数组
 *      两次，分别在两个数组中存储从左到右的连续乘积和从右到左的连续乘积。最后再遍历一次，求出最后的结果。
 * 时间复杂度：O（3n）
 * 空间复杂度：O（3n）
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty()) return {};
        if(nums.size()==1) return {nums[0]};
        int n=nums.size();
        vector<int> pdt1(n,1),pdt2(n,1),res;
        for(int i=0;i<n-1;++i){
            pdt1[i+1]=pdt1[i]*nums[i];
        }
        for(int i=n-1;i>0;--i){
            pdt2[i-1]=pdt2[i]*nums[i];
        }
        for(int i=0;i<n;++i){
            res.push_back(pdt1[i]*pdt2[i]);
        }
        return res;
    }
};
/**
 * solution2 : 左右乘积数组优化
 *      思路和上面一个解法一致，但是这次我们只采用一个数组作为存储空间即可。第一次从前往后遍历数组得到所有数左边的乘积，第二次从后往前遍历数
 *      组，将得到的值存在right中，并将最后结果存储在数组之中。
 * 时间复杂度：O（2n）
 * 空间复杂度：O（n）
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty()) return {};
        if(nums.size()==1) return {nums[0]};
        int n=nums.size(),right=1;
        vector<int> res(n,1);
        for(int i=0;i<n-1;++i){
            res[i+1]=res[i]*nums[i];
        }
        for(int i=n-1;i>=0;--i){
            res[i]*=right;
            right*=nums[i];
        }
        return res;
    }
};