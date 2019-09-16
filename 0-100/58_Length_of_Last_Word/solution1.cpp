//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * 1.直接方法
 *   1）在字符串开头拼接一个空格，方便统一判断字符串的开头。
 *   2）当遇到字符串的开头的时候，找出这个单词的结尾。
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        s=' '+s;
        int sz=s.size();
        int stloc=0,endloc=0;
        for(int i=1;i<sz;i++){
            if(s[i]!=' ' && s[i-1]==' '){
                stloc=i;
                endloc=i;
                for(int j=i;s[j]!=' '&&s[j]!='\0';j++){
                    endloc++;
                }
            }
        }
        return endloc-stloc;
    }
};