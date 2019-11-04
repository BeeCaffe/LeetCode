/***********************************************************************************************************************
 * Created by caffe on 2019/11/4.
 * 题干：
 *      Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array
 *      such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
 *
        Example 1:

        Input: nums = [1,2,3,1], k = 3
        Output: true

        Example 2:

        Input: nums = [1,0,1,1], k = 1
        Output: true

        Example 3:

        Input: nums = [1,2,3,1,2,3], k = 2
        Output: false
 **********************************************************************************************************************/
/**
 * solution1：map
 *      遍历数组，看当前元素是否存在于map之中，不存在，加入map中。存在，拿出已存在的当前元素，计算index之差，若符合要求返回true，不符合则
 *      将map中的元素替换成为当前元素。
 * 时间复杂度：O（n）
 * 空间复杂度：O（n）
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty()) return false;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();++i){
            auto iter=mp.find(nums[i]);
            if(iter!=mp.end()){
                int index=iter->second;
                if(abs(index-i) <= k) return true;
                else{
                    iter->second=i;
                }
            }else{
                mp.insert(pair<int,int>(nums[i],i));
            }
        }
        return false;
    }
};