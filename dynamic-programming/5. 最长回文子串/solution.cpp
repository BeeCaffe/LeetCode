/***********************************************************************************************************************
 * Created by caffe on 2019/12/11.
 * 5. 最长回文子串
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 **********************************************************************************************************************/
/**
 * solution 1 : 暴力算法
 * 使用双指针遍历整个字符串，检测每个位置是否为回文数。
 * 时间复杂度：O（n3）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int maxlen=0;
        int n=s.size();
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                if(check(s,i,j)){
                    if(maxlen<j-i+1) {ans=s.substr(i,j-i+1);maxlen=j-i+1;}
                }
            }
        }
        return ans;
    }
    bool check(string &s,int left,int right){
        while(left<right){
            if(s[left]==s[right]){
                ++left;--right;
            }else return false;
        }
        return true;
    }
};
/**
 * solution 2 : 中心扩展算法
 * 遍历一次字符串，对于每个字符朝两边走，直到不是回文数。
 * 时间复杂度：O（n2）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int n=s.size();
        for(int i=0;i<n;++i){
            string tmp1=check(s,i,i+1);
            string tmp2=check(s,i,i);
            string tmpmax = (tmp1.size()>tmp2.size()) ? tmp1:tmp2;
            ans = tmpmax.size() > ans.size() ? tmpmax:ans;
        }
        return ans;
    }
    string check(string &s,int left,int right){
        while(left>=0&&right<s.size()&&s[left]==s[right]){
            --left;++right;
        }
        left++;
        right--;
        return s.substr(left,right-left+1);
    }
};
/**
 * solution 3 ： 动态规划
 * 时间复杂度：O（n2）
 * 空间复杂度：O（n2）
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string ans="";
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int r=0;r<n;++r){
            for(int l=0;l<=r;++l){
                if(s[l]==s[r] && (r-l<=2 || dp[l+1][r-1])){
                    dp[l][r]=true;
                    if(r-l+1>ans.size()) ans=s.substr(l,r-l+1);
                }
            }
        }
        return ans;
    }
};