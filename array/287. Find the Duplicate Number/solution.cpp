/***********************************************************************************************************************
 * Created by caffe on 2019/11/5.
 *287. Find the Duplicate Number
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
    Example 1:
    Input: [1,3,4,2,2]
    Output: 2
    Example 2:
    Input: [3,1,3,4,2]
    Output: 3
    Note:
        You must not modify the array (assume the array is read only).
        You must use only constant, O(1) extra space.
        Your runtime complexity should be less than O(n2).
        There is only one duplicate number in the array, but it could be repeated more than once.
 **********************************************************************************************************************/
/**
 * solution1 ： set法
 *      将数组元素存入一个set，当发生重复时就返回。
 * 时间复杂度：O（n）
 * 空间复杂度：O（n）
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> m_set;
        for(int i=0;i<nums.size();++i){
            if(m_set.find(nums[i])==m_set.end()){
                m_set.insert(nums[i]);
            }else return nums[i];
        }
        return -1;
    }
};

/**
 * solution2 :
 */