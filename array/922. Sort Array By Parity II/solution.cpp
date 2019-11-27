
/***********************************************************************************************************************
 * Created by caffe on 2019/11/26.
 * 922. Sort Array By Parity II
 * Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

    Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

    You may return any answer array that satisfies this condition.

    Example 1:

    Input: [4,2,5,7]
    Output: [4,5,2,7]
    Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

    Note:

        2 <= A.length <= 20000
        A.length % 2 == 0
        0 <= A[i] <= 1000

 **********************************************************************************************************************/
/**
 * solution 1 : 分析法
 * 时间复杂度：O（n）
 * 空间复杂度：O（n）
 */
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> ans(A);
        int odd=1,even=0;
        for(int num:A){
            if(num%2==0){
                ans[even]=num;
                even+=2;
            }else{
                ans[odd]=num;
                odd+=2;
            }
        }
        return ans;
    }
};