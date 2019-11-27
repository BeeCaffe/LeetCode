
/***********************************************************************************************************************
 * Created by caffe on 2019/11/27.
 * 962. Maximum Width Ramp
 * Given an array A of integers, a ramp is a tuple (i, j) for which i < j and A[i] <= A[j].  The width of such a ramp is j - i.

Find the maximum width of a ramp in A.  If one doesn't exist, return 0.



Example 1:

Input: [6,0,8,2,1,5]
Output: 4
Explanation:
The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and A[5] = 5.

Example 2:

Input: [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation:
The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and A[9] = 1.



Note:

    2 <= A.length <= 50000
    0 <= A[i] <= 50000


 **********************************************************************************************************************/
/**
 * solution 1 : 双指针
 * 时间复杂度：O（n）
 * 空间复杂度：O（1）
 */
 //Time Limit Exceed
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int left=0,right;
        int ans=0;
        while(left<A.size()){
            right=left+1;
            while(right<A.size()){
                if(A[left]<=A[right]) ans=max(ans,right-left);
                ++right;
            }
            ++left;
        }
        return ans;
    }
};
/**
 * solution 2 : sort法
 * 将数组A的value和key放在一个pair里面，对value进行排序。那么必然小的元素会在前面，大的元素会在后面，而且我们也知道每个元素
 * 的下标。那么最大的坡度长度就是当前值的下面减去前面最小的下标，再找到最大的长度就是结果。
 * 时间复杂度：O（nlog2n）
 * 空间复杂度：O（n）
 */
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int ans=0;
        vector<pair<int,int>> B(A.size());//(value,index)
        for(int i=0;i<B.size();++i){
            B[i].first=A[i];
            B[i].second=i;
        }
        sort(B.begin(),B.end());
        int min_index=B[0].second;
        for(auto pr:B){
            ans=max(ans,pr.second-min_index);
            min_index=min(min_index,pr.second);
        }
        return ans;
    }
};