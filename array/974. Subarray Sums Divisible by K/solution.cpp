/***********************************************************************************************************************
 * Created by caffe on 2019/11/27.
 * 974. Subarray Sums Divisible by K
 * Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

    Example 1:

    Input: A = [4,5,0,-2,-3,1], K = 5
    Output: 7
    Explanation: There are 7 subarrays with a sum divisible by K = 5:
    [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

    Note:

        1 <= A.length <= 30000
        -10000 <= A[i] <= 10000
        2 <= K <= 10000
 **********************************************************************************************************************/
/**
 * solution 1 : 双指针
 * 本题要求找出所有的能够被K整除的子数组，最简单的办法是遍历所有子数组，依次检查即可，这里采用的办法是双指针。
 * 时间复杂度：O（n2）
 * 空间复杂度：O（1）
 */
 //Time Limit Exceed
 class Solution {
 public:
     int subarraysDivByK(vector<int>& A, int K) {
         if(A.size()==1) return A[0]%K==0 ? 1:0;
         int left=0,right;
         int ans=0;
         while(left<A.size()){
             right=left;
             int sum=0;
             while(right<A.size()){
                 sum+=A[right];
                 if(sum%K==0) ans++;
                 ++right;
             }
             ++left;
         }
         return ans;
     }
 };