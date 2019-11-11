/***********************************************************************************************************************
 * Created by caffe on 2019/11/11.
 * 561. Array Partition I
 *  Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

    Example 1:

    Input: [1,4,3,2]

    Output: 4
    Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).

    Note:

        n is a positive integer, which is in the range of [1, 10000].
        All the integers in the array will be in the range of [-10000, 10000].
 *********************************************************************************************************************/
/**
 * solution 1 : 分析法
 * 如何才能够使得sum最大呢？如果两个数字一个很小一个很大的话，这样取较小的那个数字就浪费了较大的那个数字。所以我们要使得每一对数字尽量接近，
 * 并且取更小的那一个加起来就可以了。具体方法是：把数组sort一下，让数组从小向大排列，接着把index为0，2，4...的数字加起来就可以咯。
 * 时间复杂度:O（n）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int res=0;
        for(int i=0;i<nums.size();i+=2) res+=nums[i];
        return res;
    }
};