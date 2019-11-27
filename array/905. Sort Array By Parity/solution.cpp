/***********************************************************************************************************************
 * Created by caffe on 2019/11/25.
 * 905. Sort Array By Parity
 * Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

    You may return any answer array that satisfies this condition.



    Example 1:

    Input: [3,1,2,4]
    Output: [2,4,3,1]
    The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

    Note:

        1 <= A.length <= 5000
        0 <= A[i] <= 5000
 **********************************************************************************************************************/
/**
 * solution 1 : 分析法
 * 时间复杂度： O（n）
 * 空间复杂度：O（n）
 */
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        if(A.size()==1) return A;
        vector<int> odd;
        int i=0,j=0;
        for(;i<A.size();++i){
            if(A[i]%2==0){//even
                if(j<A.size()) A[j++]=A[i];
            }else{
                odd.push_back(A[i]);
            }
        }
        for(int num:odd) A[j++]=num;
        return A;
    }
};