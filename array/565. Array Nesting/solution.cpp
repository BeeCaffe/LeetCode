/***********************************************************************************************************************
 * Created by caffe on 2019/11/11.
 * 565. Array Nesting
 * A zero-indexed array A of length N contains all integers from 0 to N-1. Find and return the longest length of set S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.

    Suppose the first element in S starts with the selection of element A[i] of index = i, the next element in S should be A[A[i]], and then A[A[A[i]]]… By that analogy, we stop adding right before a duplicate element occurs in S.



    Example 1:

    Input: A = [5,4,0,3,1,6,2]
    Output: 4
    Explanation:
    A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

    One of the longest S[K]:
    S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}



    Note:

        N is an integer within the range [1, 20,000].
        The elements of A are all distinct.
        Each element of A is an integer within the range [0, N-1].
 **********************************************************************************************************************/
/**
 * solution 1 ： dfs（深度优先搜索）
 * 对数组按照A[A[i]]的方式进行深度优先搜索，当搜索到为S[i]的时候就返回，并且结果加一。
 * 时间复杂度：O（nlogn）
 * 空间复杂度：O（n）
 * 注意：时间超限，无法运行
 */
 //time limit  exceed
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int level=0;
        int res=0;
        vector<bool> mask(nums.size(),0);
        for(int i=0;i<nums.size();++i){
            int mx=0;
            help(nums,mask,i,level,mx);
            res=max(mx,res);
        }
        return res;
    }
    void help(vector<int> &nums,vector<bool> &mask,int index,int level,int &mx){
        if(index>=nums.size() && index<0) return;
        if(mask[index]==true) {
            mx=max(level,mx);
            return;
        }
        mask[index]=true;
        help(nums,mask,nums[index],level+1,mx);
        mask[index]=false;
    }
};
//time limit  exceed
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res=0;
        for(int i=0;i<nums.size();++i){
            int idx=i,deep=0;
            vector<bool> mask(nums.size(),0);
            while(idx>=0&&idx<nums.size()&&mask[idx]==false){
                mask[idx]=1;
                idx=nums[idx];++deep;
            }
            res=max(deep,res);
        }
        return res;
    }
};
//accept
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res=0;
        vector<bool> visited(nums.size(),0);
        for(int i=0;i<nums.size();++i){
            if(!visited[i]){
                int start=nums[i],deep=0;
                do{
                    start=nums[start];
                    ++deep;
                    visited[start]=true;
                }while(start!=nums[i]);
                res=max(deep,res);
            }
        }
        return res;
    }
};