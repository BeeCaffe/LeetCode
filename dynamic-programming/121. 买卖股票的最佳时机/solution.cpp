/***********************************************************************************************************************
 * Created by caffe on 2019/12/13.
 * 121. 买卖股票的最佳时机
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

    如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

    注意你不能在买入股票前卖出股票。
 **********************************************************************************************************************/
/**
 * solution 1 ： 暴力算法
 * 找到每两天之间卖出股票的收入并找到最大值就ok
 * 时间复杂度：O（n2）
 * 空间复杂度：O（n2）
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        int ans=INT_MIN;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int profit=max(0,prices[j]-prices[i]);
                ans=max(ans,profit);
            }
        }
        return ans;
    }
};

/**
 * solution 2 : 动态规划
 * 时间复杂度：O（n）
 * 空间复杂度：O（n）
 */
//执行用时 :8 ms, 在所有 cpp 提交中击败了82.26% 的用户
//内存消耗 :9.6 MB, 在所有 cpp 提交中击败了19.79%的用户
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        vector<int > dif(n-1,0);
        vector<int > dp(n,0);
        for(int i=1;i<n;++i){
            dif[i-1]=prices[i]-prices[i-1];
        }

        int ans=INT_MIN;
        for(int i=1;i<n;++i){
            dp[i]=max(0,dp[i-1]+dif[i-1]);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};