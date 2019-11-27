/***********************************************************************************************************************
 * Created by caffe on 2019/11/25.
 * 873. Length of Longest Fibonacci Subsequence
 * A sequence X_1, X_2, ..., X_n is fibonacci-like if:

    n >= 3
    X_i + X_{i+1} = X_{i+2} for all i + 2 <= n

    Given a strictly increasing array A of positive integers forming a sequence, find the length of the longest fibonacci-like subsequence of A.  If one does not exist, return 0.

    (Recall that a subsequence is derived from another sequence A by deleting any number of elements (including none) from A, without changing the order of the remaining elements.  For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].)



    Example 1:

    Input: [1,2,3,4,5,6,7,8]
    Output: 5
    Explanation:
    The longest subsequence that is fibonacci-like: [1,2,3,5,8].

    Example 2:

    Input: [1,3,7,11,12,14,18]
    Output: 3
    Explanation:
    The longest subsequence that is fibonacci-like:
    [1,11,12], [3,11,14] or [7,11,18].



    Note:

        3 <= A.length <= 1000
        1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9
        (The time limit has been reduced by 50% for submissions in Java, C, and C++.)
 **********************************************************************************************************************/
/**
 * solution 1 : 双指针加set
 * 每次对于两个数作为数列的开始都需要在数组所有的元素中查找一个符合条件的最长序列。为了节省查找的时间，采用的是hash set数据结构来查找当前开始
 * 两个数的最长符合条件的序列，并返回最大值。
 * 时间复杂度： O（n2）
 * 空间复杂度： O（n）
 */
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_set<int> hash_set(A.begin(),A.end());
        int ans=0;
        for(int i=0;i<A.size();++i){
            for(int j=i+1;j<A.size();++j){
                int len=2;
                int x=A[j],y=A[i]+A[j];
                while(hash_set.find(y)!=hash_set.end()){
                    int tmp=x+y;
                    x=y;
                    y=tmp;
                    ans=max(ans,++len);
                }
            }
        }
        return ans>=3 ? ans : 0;
    }
};