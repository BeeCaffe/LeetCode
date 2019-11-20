/***********************************************************************************************************************
 * Created by caffe on 2019/11/19.
 *
 **********************************************************************************************************************/
/**
 * error solution 1 : dfs(shortest paths)(Time Limit Exceed)
 * time complexity : O(2log2n)
 * space complexity : O(1)
 */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int mincost=INT_MAX;
        assist(cost,mincost,0,0);
        assist(cost,mincost,0,1);
        return mincost;
    }
    void assist(vector<int> &cost,int &mincost,int sum,int index){
        if(index>=cost.size()){
            mincost=min(mincost,sum);
            return;
        }
        sum+=cost[index];
        assist(cost,mincost,sum,index+1);
        assist(cost,mincost,sum,index+2);
    }
};
/**
 * solution 1 : Dynamic Programming
 * 我们用一个数组dp来存放到达每一层所需要的花费值，则最终结果是求dp[cost.size()]。由于每次可以走一层或者两层，
 * 并且可以从0层或者1层开始，所以可以得到dp[0]=0,dp[1]=0.那么对于dp[i]可以由dp[i-2]走两层或者dp[i-1]走一层
 * 到达，而i-2和i-1层的花费分别是cost[i-2]和cost[i-1]，所以说，dp[i]=min(dp[i-2]+cost[i-2],dp[i-1]+cost[i-1))
 * time complexity : O(n)
 * space cimplexity : O(n)
 */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1);
        dp[0]=dp[1]=0;
        for(int i=2;i<cost.size()+1;++i) dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        return dp[cost.size()];
    }

};