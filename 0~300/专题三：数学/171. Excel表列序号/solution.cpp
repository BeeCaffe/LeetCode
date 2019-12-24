//
// Created by caffe on 2019/12/24.
//
/*
 * 171. Excel表列序号
 * 给定一个Excel表格中的列名称，返回其相应的列序号。

    例如，

        A -> 1
        B -> 2
        C -> 3
        ...
        Z -> 26
        AA -> 27
        AB -> 28
        ...
 */
/*
 * solution 1 : 找规律
 * 实际上和上一道题是一个相反的过程，有点类似于进制转换的过程。
 * 时间复杂度：O（n）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    int titleToNumber(string s) {
        int sz=s.size();
        int ans=0,cur=0;
        for(int i=0;i<sz;++i){
            cur = s[i]-'A'+1;
            ans = ans*26 + cur;
        }
        return ans;
    }
};