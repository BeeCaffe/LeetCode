
//
// Created by caffe on 2019/12/17.
//
/*
 * 279. 完全平方数
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 */
/**
 * solution 1 : 动态规划
 * 首先，最差的情况是全部由1组成，所以此时的dp[i]=i。
 * 最好的情况是由i的上一个完全平方数j*j加上dp[i-j*j],也就是dp[i-j*j]+1。
 * 所以我们从1到i-j*j来找到当前的小于i的最大的完全平方数。
 * 时间复杂度：O(n2)
 * 空间复杂度：O（n）
 */
class Solution {
public:
    int numSquares(int n) {
        if(n<2) return n;
        vector<int> dp(n+1,0);
        dp[0]=0;
        for(int i=1;i<n+1;++i){
            dp[i]=i;
            for(int j=1;i-j*j>=0;++j){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};
