/***********************************************************************************************************************
 * Created by caffe on 2019/11/5.
 * 268. Missing Number
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
    Example 1:

    Input: [3,0,1]
    Output: 2

    Example 2:

    Input: [9,6,4,2,3,5,7,0,1]
    Output: 8

    Note:
    Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 **********************************************************************************************************************/
/**
 * solution1： sort法
 *      排序，然后找到不连续的数。
 * 时间复杂度：O（nlogn）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums[nums.size()-1]!=nums.size()) return nums.size();
        else if(nums[0]!=0) return 0;
        for(int i=1;i<nums.size();++i){
            if(nums[i]-nums[i-1]!=1)
                return nums[i]-1;
        }
        return -1;
    }
};

/**
 * solution2 ： hash set
 *      将数组中所有的值存储到一个set里面之后，遍历数组，查看index是否全部在set之中
 * 时间复杂度：O（2n）
 * 空间复杂度：O（n）
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> m_set;
        for(int num:nums) m_set.insert(num);
        for(int i=0;i<nums.size()+1;++i){
            if(m_set.find(i)==m_set.end()) return i;
        }
        return -1;
    }
};

/**
 * solution3 ： 位操作
        这个答案看不懂，复制过来
        Approach #3 Bit Manipulation [Accepted]
        Intuition
        We can harness the fact that XOR is its own inverse to find the missing element in linear time.
        Algorithm
        Because we know that nums contains nnn numbers and that it is missing exactly one number on the range [0..n−1][0..n-1][0..n−1], we know that nnn definitely replaces the missing number in nums. Therefore, if we initialize an integer to nnn and XOR it with every index and value, we will be left with the missing number. Consider the following example (the values have been sorted for intuitive convenience, but need not be):
        Index 	0 	1 	2 	3
        Value 	0 	1 	3 	4
        missing=4∧(0∧0)∧(1∧1)∧(2∧3)∧(3∧4)=(4∧4)∧(0∧0)∧(1∧1)∧(3∧3)∧2=0∧0∧0∧0∧2=2 \begin{aligned} missing &= 4 \wedge (0 \wedge 0) \wedge (1 \wedge 1) \wedge (2 \wedge 3) \wedge (3 \wedge 4) \\ &= (4 \wedge 4) \wedge (0 \wedge 0) \wedge (1 \wedge 1) \wedge (3 \wedge 3) \wedge 2 \\ &= 0 \wedge 0 \wedge 0 \wedge 0 \wedge 2 \\ &= 2 \end{aligned} missing​=4∧(0∧0)∧(1∧1)∧(2∧3)∧(3∧4)=(4∧4)∧(0∧0)∧(1∧1)∧(3∧3)∧2=0∧0∧0∧0∧2=2​
  */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int miss=nums.size();
        for(int i=0;i<nums.size();++i)
            miss^=i^nums[i];
        return miss;
    }
};