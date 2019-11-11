/***********************************************************************************************************************
 * Created by caffe on 2019/11/7.
 * 448. Find All Numbers Disappeared in an Array
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

    Find all the elements of [1, n] inclusive that do not appear in this array.

    Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

    Example:

    Input:
    [4,3,2,7,8,2,3,1]

    Output:
    [5,6]
 **********************************************************************************************************************/
/**
 * solution1 ： index法
 *      同样利用1<=a[i]<=n的特点，依次遍历数组，将元素所对应的下标值置为负数，再遍历一次数组，将值大于0的下标加一返回即可。
 * 时间复杂度：O（n）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();++i){
            int idx=abs(nums[i])-1;
            if(nums[idx]>0) nums[idx]=-nums[idx];
        }
        for(int i=0;i<nums.size();++i){
            if(nums[i]>0) res.push_back(i+1);
        }
        return res;
    }
};