//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
//2.动态规划
//  要想知道能否跳到最后一个点，只需要知道前一个点最远还能跳多远。
//  到第i个点时，前面最远还能跳：dp[i]=max(dp[i-1],nums[i])-1
//  时间复杂度O（n），空间复杂度O（n）
class Solution {
public:
    #define max(a,b) (a>b ? a:b)
    bool canJump(vector<int>& nums) {
        int sz=nums.size();
        vector<int> dp(sz,0);
        for(int i=1;i<sz;i++){
            dp[i]=max(dp[i-1],nums[i-1])-1;
            if(dp[i]<0) return false;
        }
        return dp[sz-1]<0 ? false:true;
    }
};