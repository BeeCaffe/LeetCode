/***********************************************************************************************************************
 * Created by caffe on 2019/11/25.
 * 907. Sum of Subarray Minimums
 * Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

    Since the answer may be large, return the answer modulo 10^9 + 7.



    Example 1:

    Input: [3,1,2,4]
    Output: 17
    Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
    Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.



    Note:

        1 <= A.length <= 30000
        1 <= A[i] <= 30000
 **********************************************************************************************************************/
/**
 * solution 1 : 双指针法
 * 时间复杂度：O（n3）
 * 空间复杂度：O（1）
 */
 //Time Limit Exceed
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        if(A.size()==1) return A[0];
        int ans=0;
        for(int i=0;i<A.size();++i){
            for(int j=i;j<A.size();++j){
                int sub_min=INT_MAX;
                for(int k=i;k<=j;++k) sub_min=min(sub_min,A[k]);
                if(sub_min!=INT_MAX) ans+=sub_min;
            }
        }
        return ans;
    }
}
//Time Limit Exceed
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        if(A.size()==1) return A[0];
        int mod=1e9+7;
        int ans=0;
        for(int i=0;i<A.size();++i){
            int cur_min=A[i];
            for(int j=i;j<A.size();++j){
                cur_min=min(cur_min,A[j]);
                ans=(ans+cur_min)%mod;
            }
        }
        return ans;
    }
};