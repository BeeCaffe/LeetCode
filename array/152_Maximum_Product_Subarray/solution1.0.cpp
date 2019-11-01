/***********************************************************************************************************************
 * Created by caffe on 2019/11/1.
 * 题干：
        Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which
        has the largest product.
 * 解法一：动态规划
        用m_min和m_max来记录以nums[i]结尾的乘积最小和最大的子序列，因为要求的是乘机最大的子序列的结果，有可能负数乘以一个更大的负数就会成
        为最大的结果。
 * 时间复杂度：O（n）
 * 空间复杂度：O（1）
 **********************************************************************************************************************/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m_min(1),m_max(1),result(INT_MIN);
        for(int num:nums){
            int cur_min = min(num,min(m_min*num,m_max*num));
            int cur_max = max(num,max(m_max*num,m_min*num));
            result=max(result,cur_max);
            m_min=cur_min;
            m_max=cur_max;
        }
        return result;
    }
};