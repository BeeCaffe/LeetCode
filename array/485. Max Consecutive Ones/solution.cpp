/***********************************************************************************************************************
 * Created by caffe on 2019/11/7.
 * 485. Max Consecutive Ones
 * Given a binary array, find the maximum number of consecutive 1s in this array.

    Example 1:

    Input: [1,1,0,1,1,1]
    Output: 3
    Explanation: The first two digits or the last three digits are consecutive 1s.
        The maximum number of consecutive 1s is 3.

    Note:

        The input array will only contain 0 and 1.
        The length of input array is a positive integer and will not exceed 10,000

 **********************************************************************************************************************/
/**
 * solution 1: 直接法
 *      直接遍历整个数组，记录最长的个数即可。
 * 时间复杂度：O（n）
 * 空间复杂度：O（1）
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maximum=0,tmp=0;
        for(int num:nums){
            if(num==0&&tmp!=0){
                maximum=max(maximum,tmp);
                tmp=0;
            }else if(num==0&&tmp==0) tmp=0;
            else if(num==1) ++tmp;
            maximum=max(maximum,tmp);
        }
        return maximum;
    }
};