/***********************************************************************************************************************
 * Created by caffe on 2019/12/9.
 * 1218. 最长定差子序列
 * 给你一个整数数组 arr 和一个整数 difference，请你找出 arr 中所有相邻元素之间的差等于给定 difference 的等差子序列，并返回其中最长的等差子序列的长度。



示例 1：

输入：arr = [1,2,3,4], difference = 1
输出：4
解释：最长的等差子序列是 [1,2,3,4]。

示例 2：

输入：arr = [1,3,5,7], difference = 1
输出：1
解释：最长的等差子序列是任意单个元素。

示例 3：

输入：arr = [1,5,7,8,5,3,4,2,1], difference = -2
输出：4
解释：最长的等差子序列是 [7,5,3,1]。



提示：

    1 <= arr.length <= 10^5
    -10^4 <= arr[i], difference <= 10^4
 **********************************************************************************************************************/
//Time Limit Exceed
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int maxlen=0;
        int left=0,right;
        while(left<arr.size()){
            right=left+1;
            int tmplen=1;
            int lastindex=left;
            while(right<arr.size()){
                if(arr[right]-arr[lastindex]==difference){
                    ++tmplen;
                    lastindex=right;
                }
                ++right;
            }
            maxlen=max(maxlen,tmplen);
            ++left;
        }
        return maxlen==0?arr.size():maxlen;
    }
};