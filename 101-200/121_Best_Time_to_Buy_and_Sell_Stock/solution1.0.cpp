/***********************************************************************************************************************
 * Created by caffe on 2019/10/30.
 * 题干：
 *      Say you have an array for which the ith element is the price of a given stock on day i.

        If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

        Note that you cannot sell a stock before you buy one.
 * 解法一：动态规划
 *      通过把相邻股票价格相减得到一组差价，问题就转变成为最大子列和的问题。
 *      即从前往后依次计算和，得到的最大的那一个就是最大的利润，因为这个序列中所有的数都是股票价格的差值，只要从前往后相加就可以得到每两天之
 *      间的股票价格差值。
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 **********************************************************************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        vector<int> delta(prices.size(),0);
        for(int i=1;i<prices.size();++i){
            delta[i]=prices[i]-prices[i-1];
        }
        vector<int> sum(prices.size(),0);
        int maxprof=0;
        sum[0]=delta[0];
        for(int i=1;i<sum.size();++i){
            sum[i]=max(delta[i],sum[i-1]+delta[i]);
            maxprof=max(maxprof,sum[i]);
        }
        return maxprof;
    }
};