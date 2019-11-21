/***********************************************************************************************************************
 * Created by caffe on 2019/11/21.
 * 792. 匹配子序列的单词数
 * 给定字符串 S 和单词字典 words, 求 words[i] 中是 S 的子序列的单词个数。
    示例:
    输入:
    S = "abcde"
    words = ["a", "bb", "acd", "ace"]
    输出: 3
    解释: 有三个是 S 的子序列的单词: "a", "acd", "ace"。
    注意:
        所有在words和 S 里的单词都只由小写字母组成。
        S 的长度在 [1, 50000]。
        words 的长度在 [1, 5000]。
        words[i]的长度在[1, 50]。
 **********************************************************************************************************************/
/**
 * error solution 1: 模式匹配
 * 时间复杂度：O（m2n）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int ans=0;
        for(string word:words){
            if(isSubSeq(S,word)) ans++;
        }
        return ans;
    }
    bool isSubSeq(string &S,string &sub_seq){
        int idx=0,i;
        int count=0;
        for(i=0;i<sub_seq.size();++i){
            while(idx<S.size()&&S[idx]!=sub_seq[i]) ++idx;
            if(idx<S.size()&&S[idx++]==sub_seq[i]) ++count;
        }
        if(count==sub_seq.size()) return true;
        return false;
    }
};
//Accepted
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int ans=0;
        unordered_map<string ,int > m;
        for(string s: words)
            m[s]++;
        for(auto p: m){
            if(isSubSeq(S,p.first)) ans+= p.second;
        }
        return ans;
    }
    bool isSubSeq(const string &S,const string &sub_seq){
        int idx=0,i;
        int count=0;
        for(i=0;i<sub_seq.size();++i){
            while(idx<S.size()&&S[idx]!=sub_seq[i]) ++idx;
            if(idx<S.size()&&S[idx++]==sub_seq[i]) ++count;
        }
        if(count==sub_seq.size()) return true;
        return false;
    }
};