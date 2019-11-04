/***********************************************************************************************************************
 * Created by caffe on 2019/11/4.
 * 题干：
 *      Given a sorted integer array without duplicates, return the summary of its ranges.

        Example 1:

        Input:  [0,1,2,4,5,7]
        Output: ["0->2","4->5","7"]
        Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.

        Example 2:

        Input:  [0,2,3,4,6,8,9]
        Output: ["0","2->4","6","8->9"]
        Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 **********************************************************************************************************************/
/**
 * solution1：双指针法
 *      用两个指针right，left分别指向连续序列的开始和结束（注意都遵守左闭右开的规则），right先走，当发现和前面的差值不为1的时候说明就不连
 *      续了，将字符串放入数组中，让left=right，作为开始重复上面的过程。
 *      Runtime: 0 ms, faster than 100.00% of C++ online submissions for Summary Ranges.
 *      Memory Usage: 8.4 MB, less than 92.31% of C++ online submissions for Summary Ranges.
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return {};
        if(nums.size()==1) return {to_string(nums[0])};
        vector<string> res;
        string str;
        int left=0,right=left+1;
        while(right<nums.size()){
            while(right<nums.size() && (long)nums[right]-(long)nums[right-1]==1) right++;
            if(left==right-1) str=to_string(nums[left]);
            else str=to_string(nums[left])+"->"+to_string(nums[right-1]);
            res.push_back(str);
            left=right++;
        }
        if(left=nums.size()-1 && right==nums.size()) res.push_back(to_string(nums[right-1]));
        return res;
    }
};