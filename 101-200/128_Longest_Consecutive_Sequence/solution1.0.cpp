/***********************************************************************************************************************
 * Created by caffe on 2019/10/31.
 * 题干：
        Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
        Your algorithm should run in O(n) complexity.
   解法一：暴力搜索
        由于要求算法的时间复杂度在O（n）这个数量级，因此不能够对数组进行排序。暴力算法的思想就是利用unorder_set能够快速查找到某个元素的特
        点，因为unorder_set的底层实现是hash表，因此查找的时间复杂度为O（1），因此该算法描述如下。
        1）将vector中元素复制到unorder_set中
        2）遍历ector中每个元素，依次作为开始再unorder_set中依次向前向后查找，直到不再连续
        3）返回最大连续的数目即可
 * 时间复杂度：O(n)
 * 空间复杂度：O（n）
 **********************************************************************************************************************/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(),nums.end());
        int len=1;
        for(int &n:nums){
            if(!set.count(n)) continue;
            set.erase(n);
            int left=n-1;
            int right=n+1;
            while(set.count(left)) set.erase(left--);
            while(set.count(right)) set.erase(right++);
            len = max(len,right-left-1);
        }
        return len;
    }
};