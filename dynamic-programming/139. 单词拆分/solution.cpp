//
// Created by caffe on 2019/12/16.
//
/*
 * 139. 单词拆分
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
   说明：
        拆分时可以重复使用字典中的单词。
        你可以假设字典中没有重复的单词。
 */
/**
 * solution 1 : 动态规划
 * 考虑字符“catsandog”和词语字典["cats","and"，"dog"],动态规划的主要思路是假设我们把原来字符串分成"cats","andog"两部分
 * ,那么前面部分的"cats"显然是可以在词语字典中找到的，只需要看后面部分是否符合要求。具体的，我们设字符串的总长度为n，设i为从0
 * 开始长度为i的s的子字符串，j为子字符串i的划分位置，那么对于长度为i的子字符串就可以被划分成[0,j-1]和[j+1,i]的两个部分。我们
 * 用i表示所有的子字符串的长度，然后对于每一个子字符串，我们通过下标j将其拆分为两个部分，如果前一个部分为true，那么就检查后一个
 * 部分是否在字典当中，如果在的话就把dp[i]置为true就可以了。
 **/
//执行用时 :12 ms, 在所有 cpp 提交中击败了73.82%的用户
//内存消耗 :14.1 MB, 在所有 cpp 提交中击败了61.64%的用户
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string> hashset(wordDict.begin(),wordDict.end());
        vector<bool> dp(n+1,0);
        dp[0]=true;
        for(int i=1;i<n+1;++i){
            for(int j=0;j<i;++j){
                if(dp[j]&&hashset.find(s.substr(j,i-j))!=hashset.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
