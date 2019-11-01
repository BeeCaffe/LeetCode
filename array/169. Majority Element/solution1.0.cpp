/***********************************************************************************************************************
 * Created by caffe on 2019/11/1.
 * 题干：
 *      Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
        You may assume that the array is non-empty and the majority element always exist in the array.
   解法一：hash法
        用map来存储一个数字和它出现的次数，返回超过n/2的数字即可，注意处理数组长度为1的情况。
   时间复杂度：O（n）
   空间复杂度：O（n）
 **********************************************************************************************************************/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        map<int,int> mp;
        int maxnum=0;
        for(int num:nums){
            auto iter=mp.find(num);
            if(iter==mp.end()){
                mp.insert(pair<int,int>(num,1));
            }else{
                iter->second++;
                if(iter->second>nums.size()/2) return iter->first;
            }
        }
        return 0;
    }
};