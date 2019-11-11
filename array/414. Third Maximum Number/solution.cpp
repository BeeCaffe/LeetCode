/***********************************************************************************************************************
 * Created by caffe on 2019/11/6.
 * 414. Third Maximum Number
 * Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

    Example 1:

    Input: [3, 2, 1]

    Output: 1

    Explanation: The third maximum is 1.

    Example 2:

    Input: [1, 2]

    Output: 2

    Explanation: The third maximum does not exist, so the maximum (2) is returned instead.

    Example 3:

    Input: [2, 2, 3, 1]

    Output: 1

    Explanation: Note that the third maximum here means the third maximum distinct number.
    Both numbers with value 2 are both considered as second maximum.

 **********************************************************************************************************************/
/**
 * solution1：sort法
 *      直接排序，找出第三大的数。
 * 时间复杂度：O（nlogn）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int num=3,last=0;
        for(int i=nums.size()-1;i>=0;--i){
            if(last!=nums[i]){--num;last=nums[i];}
            if(num==0) return nums[i];
        }
        return nums[nums.size()-1];
    }
};
/**
 * solution2:set
 *      考虑到set是有序的，并且在set中不能够有重复元素，因此，只需要将数组中的全部元素加入set中，然后连续删除3个即可。
 * 时间复杂度：O（n）
 * 空间复杂度：O（n）
 */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> topN;
        int n=3;
        for(int num:nums){
            topN.insert(num);
            if(topN.size()>n) topN.erase(topN.begin());
        }
        return (topN.size()>=n)? *(topN.begin()):*(topN.rbegin());
    }
};