/***********************************************************************************************************************
 * Created by caffe on 2019/10/30.
 * 题干：
        Say you have an array for which the ith element is the price of a given stock on day i.

        Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

        Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 * 解法一：动态规划
        同样可以求出前后两天的股票价格差值数组，只要差值为正的相加起来即可。因为你可以任意一天买入和卖出，因此所有为正的之和必然就是最大的结果。
 * 时间复杂度：O（n）
 * 空间复杂度：O（n）
 **********************************************************************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        vector<int> delta(prices.size());
        for(int i=1;i<prices.size();++i){
            delta[i]=prices[i]-prices[i-1];
        }
        int maxsum=0;
        for(int i=0;i<delta.size();++i){
            if(delta[i]>0) maxsum+=delta[i];
        }
        return maxsum;
    }
};