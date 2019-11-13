/***********************************************************************************************************************
 * Created by caffe on 2019/11/13.
 * 697. Degree of an Array
 * Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

    Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

    Example 1:

    Input: [1, 2, 2, 3, 1]
    Output: 2
    Explanation:
    The input array has a degree of 2 because both elements 1 and 2 appear twice.
    Of the subarrays that have the same degree:
    [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
    The shortest length is 2. So return 2.

    Example 2:

    Input: [1,2,2,3,1,4,2]
    Output: 6

    Note:
    nums.length will be between 1 and 50,000.
    nums[i] will be an integer between 0 and 49,999.
 **********************************************************************************************************************/
/**
 * solution 1 : 双指针法
 * 对于每一个新出现的元素nums[i]，从后面开始找到最后出现的位置j，并计算从第一次出现到最后一次出现的长度j-i+1。然后在[i,j]区间内找到这个元素
 * 出现的次数，如果出现次数是历史出现的最大的，则将长度记为结果，如果持平，则将长度置为更短的那一个。同时记得标记访问过的位置来节约时间。
 * 时间复杂度：O（n）
 * 空间复杂度：O（n）
 */
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int maxtimes=0,ans=0,i,j;
        vector<int> visited(nums.size(),0);
        for(i=0;i<nums.size();++i){
            if(!visited[i]){
                for(j=nums.size()-1;j>=i;--j){
                    if(nums[j]==nums[i]) break;
                }
                int len=j-i+1;
                int times=0;
                for(int k=i;k<=j;++k){
                    if(nums[k]==nums[i]){++times;visited[k]=true;}
                }
                if(times>maxtimes){ans=len;maxtimes=times;}
                else if(times==maxtimes){
                    ans=min(len,ans);
                }
            }
        }
        return ans;
    }
};