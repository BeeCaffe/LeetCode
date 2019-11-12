/***********************************************************************************************************************
 * Created by caffe on 2019/11/12.
 * 628. Maximum Product of Three Numbers
 * Given an integer array, find three numbers whose product is maximum and output the maximum product.

    Example 1:

    Input: [1,2,3]
    Output: 6



    Example 2:

    Input: [1,2,3,4]
    Output: 24



    Note:

        The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
        Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

 **********************************************************************************************************************/
/**
 * solution 1 : dfs（深度优先遍历，模式匹配）
 * 直接三重循环解决不多bb，但是时间复杂度太高，无法ac
 * 时间复杂度：O（n3）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maximum=INT_MIN;
        int sz=nums.size();
        for(int i=0;i<sz;++i){
            for(int j=i+1;j<sz;++j){
                for(int k=j+1;k<sz;++k){
                    int sum=nums[i]*nums[j]*nums[k];
                    maximum=max(maximum,sum);
                }
            }
        }
        return maximum;
    }
};

/**
 * solution 2 ： sort法
 * 先排序，直接乘最后三个就可以了，或者最开始两个，乘最后一个数，最大的必须在这两个可能之一。
 * 时间复杂度：O（nlogn）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maximum=INT_MIN;
        int sz=nums.size();
        sort(nums.begin(),nums.end());
        maximum=max(nums[0]*nums[1]*nums[sz-1],nums[sz-1]*nums[sz-2]*nums[sz-3]);
        return maximum;
    }
};