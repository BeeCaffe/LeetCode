/***********************************************************************************************************************
 * Created by caffe on 2019/11/12.
 * 643. Maximum Average Subarray I
 * Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

    Example 1:

    Input: [1,12,-5,-6,50,3], k = 4
    Output: 12.75
    Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75



    Note:

        1 <= k <= n <= 30,000.
        Elements of the given array will be in the range [-10,000, 10,000].

 **********************************************************************************************************************/
/**
 * solution 1 ： 双指针法
 * 声明两个指针pbeg，pend，pbeg和pend每次先指向相同位置，pend向右走，当走了k个位置时算一次平均数。之后，pbeg再向右走一布，
 * pend=pbeg重新再来。
 * 时间复杂度：O（n）
 * 空间复杂度：O（1）
 */
 //时间超限，无法AC
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double average=(double)INT_MIN;
        int pbeg=0,pend;
        while(pbeg<=nums.size()-k){
            pend=pbeg;
            double sum=0;
            while(pend<nums.size()&&pend-pbeg<k){
                sum+=(double)nums[pend];
                ++pend;
            }
            average=max(average,sum/k);
            ++pbeg;
        }
        return average;
    }
};
/**
 * solution 2 ： （sliding window）滑动窗口法
 * 如果我们知道了nums[i]到nums[i+k]的和，那么求nums[i+1]到nums[i+k+1]的和就只需要减去nums[i]再加上nums[i+k+1]即可。
 * 因此可以从前往后滑动窗口，找到最大的平均数即可。
 * 时间复杂度：O（n）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        for(int i=0;i<k;++i) sum+=nums[i];
        double average=sum/k;
        for(int i=1;i<=nums.size()-k;++i){
            sum=sum-nums[i-1]+nums[i+k-1];
            average=max(average,sum/k);
        }
        return average;
    }
};
/**
 * solution 3 ： 累计法
 * 声明一个数组sum[nums.size()+1]，每一个位置分别存储当前位置前面元素的和。遍历一次该数组，用sum[i+k-1]-sum[i]就可以得到从i到i+k元素的
 * 和，再找出平均数最大的即可。
 * 时间复杂度：O（n）
 * 空间复杂度：O（n）
 */
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<double> sum(nums.size()+1,0);
        double average=(double)INT_MIN;
        for(int i=1;i<nums.size()+1;++i){
            sum[i]=sum[i-1]+nums[i-1];
        }
        for(int i=0;i<=nums.size()-k;++i){
            average=max((sum[i+k]-sum[i])/k,average);
        }
        return average;
    }
};