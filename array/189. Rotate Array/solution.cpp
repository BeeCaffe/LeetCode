/***********************************************************************************************************************
 * Created by caffe on 2019/11/1.
 * 题干：
        Given an array, rotate the array to the right by k steps, where k is non-negative.
 **********************************************************************************************************************/
/**
 * solution1：直接法
 *          开辟一个新的vector，存储旋转后对应位置的值，注意处理k>nums.size()的情况。
 * 时间复杂度：O（n）
 * 空间复杂度：O（n）
 * */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0 || nums.size()==1) return;
        vector<int> res;
        if(k>nums.size()) k%=nums.size();
        for(int i=nums.size()-k;i<nums.size();++i) res.push_back(nums[i]);
        for(int i=0;i<nums.size()-k;++i) res.push_back(nums[i]);
        nums=res;
    }
};

/***
 * solution2：分段reverse
 *      将key值后的部分和key值前半部分先分别旋转，然后再整体旋转
 *
 * 时间复杂度：O（n）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0 || nums.size()==1) return;
        int sz=nums.size()-1;
        if(k>sz+1) k%=sz+1;
        reverse(nums.begin(),nums.begin()+sz-k+1);
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};