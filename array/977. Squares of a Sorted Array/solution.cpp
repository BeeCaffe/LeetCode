/***********************************************************************************************************************
 * Created by caffe on 2019/11/27.
 * 977. Squares of a Sorted Array
 * Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

    Example 1:

    Input: [-4,-1,0,3,10]
    Output: [0,1,9,16,100]

    Example 2:

    Input: [-7,-3,2,3,11]
    Output: [4,9,9,49,121]



    Note:

        1 <= A.length <= 10000
        -10000 <= A[i] <= 10000
        A is sorted in non-decreasing order.
 **********************************************************************************************************************/
/**
 * solution 1 : sort法
 * 先将所有元素按照绝对值排序，再求平方即可。
 * 时间复杂度：O（nlog2n）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    static bool cmp(const int &t1,const int &t2){
        return abs(t1)<abs(t2);
    }
    vector<int> sortedSquares(vector<int>& A) {
        sort(A.begin(),A.end(),cmp);
        for(int i=0;i<A.size();++i){
            A[i]=A[i]*A[i];
        }
        return A;
    }
};