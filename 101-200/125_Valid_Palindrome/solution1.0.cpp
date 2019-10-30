/***********************************************************************************************************************
 * Created by caffe on 2019/10/30.
 * 题干：
        Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

        Note: For the purpose of this problem, we define empty string as valid palindrome.
 * 解法一：直接法
 *        将string存储在一个char[]中，然后对比其正序和反序列是否相等。
 *
 **********************************************************************************************************************/
class Solution {
public:
    static bool isPalindrome(string s) {
        if(s.size()==0 || s.size()==1) return true;
        vector<char> str;
        for(int i=0;i<s.size();++i){
            if((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z')){
                str.push_back(tolower(s[i]));
            }
        }
        vector<char> strrev=str;
        reverse(strrev.begin(),strrev.end());
        for(int i=0;i<str.size();++i)
            if(str[i]!=strrev[i]) return false
        return true;
    }
};