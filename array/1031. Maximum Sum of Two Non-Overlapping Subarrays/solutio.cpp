/***********************************************************************************************************************
 * Created by caffe on 2019/12/2.
 * 1031. Maximum Sum of Two Non-Overlapping Subarrays
 * Given an array A of non-negative integers, return the maximum sum of elements in two non-overlapping (contiguous) subarrays, which have lengths L and M.  (For clarification, the L-length subarray could occur before or after the M-length subarray.)

    Formally, return the largest V for which V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) and either:

        0 <= i < i + L - 1 < j < j + M - 1 < A.length, or
        0 <= j < j + M - 1 < i < i + L - 1 < A.length.

    Example 1:

    Input: A = [0,6,5,2,2,5,1,9,4], L = 1, M = 2
    Output: 20
    Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.

    Example 2:

    Input: A = [3,8,1,3,2,1,8,9,0], L = 3, M = 2
    Output: 29
    Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.

    Example 3:

    Input: A = [2,1,5,6,0,9,5,0,3,8], L = 4, M = 3
    Output: 31
    Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [3,8] with length 3.

    Note:

        L >= 1
        M >= 1
        L + M <= A.length <= 1000
        0 <= A[i] <= 1000
 **********************************************************************************************************************/
/**
 * solution 1 : sum and two pointer
 * space complexity : O(n2)
 * time complexity : O(n)
 */
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> sum(A.size()+1,0);
        int ans=INT_MIN;
        for(int i=1;i<sum.size();++i) sum[i]=sum[i-1]+A[i-1];
        for(int i=0;i<sum.size();++i){
            for(int j=0;j<sum.size();++j){
                if(i+L<sum.size()&&j+M<sum.size()&&check(i,i+L-1,j,j+M-1)) ans=max(ans,sum[i+L]-sum[i]+sum[j+M]-sum[j]);
            }
        }
        return ans;
    }
    bool check(int x1,int y1,int x2,int y2){
        int x=max(x1,x2);
        int y=min(y1,y2);
        if(y-x>=0) return false;
        else return true;
    }
};