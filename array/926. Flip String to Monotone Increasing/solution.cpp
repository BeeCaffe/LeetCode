/***********************************************************************************************************************
 * Created by caffe on 2019/11/26.
 * 926. Flip String to Monotone Increasing
 * A string of '0's and '1's is monotone increasing if it consists of some number of '0's (possibly 0), followed by some number of '1's (also possibly 0.)

    We are given a string S of '0's and '1's, and we may flip any '0' to a '1' or a '1' to a '0'.

    Return the minimum number of flips to make S monotone increasing.



    Example 1:

    Input: "00110"
    Output: 1
    Explanation: We flip the last digit to get 00111.

    Example 2:

    Input: "010110"
    Output: 2
    Explanation: We flip to get 011111, or alternatively 000111.

    Example 3:

    Input: "00011000"
    Output: 2
    Explanation: We flip to get 00000000.

    Note:

        1 <= S.length <= 20000
        S only consists of '0' and '1' characters.
 **********************************************************************************************************************/
/**
 * solution 1 : 动态规划
 * 这道题的题意是希望得到前面全为0，后面全为1的字符串序列（全为1的也算），问最小可以改变的字符数目。对于这个问题我们考虑如果
 * 我们希望改变的字符数目最少那么假设我们找到一个分割点，在分割点的左边肯定是要1最少，而分割殿的右边是0最少的情况，这样才能够
 * 使得最后的改变次数最少。具体的做法是，创建一个数组dp[i]记录以i为分割点左边一的数目，那么dp[0]肯定左边没有1，所以为0，dp[n]
 * 肯定是字符串中的所有1的数目。因此我们遍历每一个位置，假设每一个位置作为分割点，那么最后改变的字符数目就是左边的1的数目和右边
 * 的0的数目。这样一来再找到最小的改变次数就是答案。
 * 时间复杂度：O（n）
 * 空间复杂度：O（n）
 */
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        if(S.size()==1) return 0;
        int ans=INT_MAX;
        vector<int> dp(S.size()+1,0);
        for(int i=0;i<S.size();++i){
            dp[i+1]=dp[i]+(S[i]=='1' ? 1:0);
        }
        for(int x=0;x<=S.size();++x)
            ans=min(ans,(int)(dp[x]+S.size()-x-(dp[S.size()]-dp[x])));
        return ans;
    }
};