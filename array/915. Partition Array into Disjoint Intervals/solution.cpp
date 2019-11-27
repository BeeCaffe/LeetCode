/***********************************************************************************************************************
 * Created by caffe on 2019/11/25.
 * 915. Partition Array into Disjoint Intervals
 * Given an array A, partition it into two (contiguous) subarrays left and right so that:

    Every element in left is less than or equal to every element in right.
    left and right are non-empty.
    left has the smallest possible size.

    Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.



    Example 1:

    Input: [5,0,3,8,6]
    Output: 3
    Explanation: left = [5,0,3], right = [8,6]

    Example 2:

    Input: [1,1,1,0,6,12]
    Output: 4
    Explanation: left = [1,1,1,0], right = [6,12]



    Note:

        2 <= A.length <= 30000
        0 <= A[i] <= 10^6
        It is guaranteed there is at least one way to partition A as described.

 **********************************************************************************************************************/
/**
 * solution 1 : 双指针法
 * 时间复杂度：O(n2)
 * 空间复杂度：O（1)
 */
//Time Limit Exceed
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int pbeg=0,pend;
        pend=pbeg;
        while(pend<A.size()){
            int prev_max=INT_MIN,next_min=INT_MAX;
            for(int i=0;i<=pend;++i) prev_max=max(prev_max,A[i]);
            for(int i=pend+1;i<A.size();++i) next_min=min(next_min,A[i]);
            if(prev_max<=next_min) return pend+1;
            ++pend;
        }
        return 0;
    }
};
//Accepted
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int pbeg=0,pend;
        pend=pbeg;
        int prev_max=INT_MIN,next_min=INT_MAX;
        while(pend<A.size()){
            prev_max=max(prev_max,A[pend]);
            if(A[pend]<=next_min){
                next_min=INT_MAX;
                for(int i=pend+1;i<A.size();++i) next_min=min(next_min,A[i]);
            }
            if(prev_max<=next_min) return pend+1;
            ++pend;
        }
        return 0;
    }
};