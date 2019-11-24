/***********************************************************************************************************************
 * Created by caffe on 2019/11/24.
 * 795. Number of Subarrays with Bounded Maximum
 * We are given an array A of positive integers, and two positive integers L and R (L <= R).

    Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least L and at most R.

    Example :
    Input:
    A = [2, 1, 4, 3]
    L = 2
    R = 3
    Output: 3
    Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].

    Note:

        L, R  and A[i] will be an integer in the range [0, 10^9].
        The length of A will be in the range of [1, 50000].
 **********************************************************************************************************************/
/**
 * solution 1 : two pointer
 * time complexity : O(N2)
 * space complexity : O(1)
 */
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int pbeg=0,pend;
        int ans=0;
        while(pbeg<A.size()){
            pend=pbeg;
            while(pend<A.size()){
                int cur_max=INT_MIN;
                for(int i=pbeg;i<=pend;++i){
                    cur_max=max(cur_max,A[i]);
                }
                if(cur_max>=L&&cur_max<=R) ++ans;
                else if(cur_max>R) break;
                ++pend;
            }
            ++pbeg;
        }
        return ans;
    }
};