//
// Created by caffe on 2019/12/24.
//
/*
 * 67. 二进制求和
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。输入为非空字符串且只包含数字 1 和 0。
 */
/**
 * solution 1 ：暴力法
 * 直接采用竖式加法地形式来求解两个二进制字符串的和，并且将和存在一个字符串中并返回。
 * 时间复杂度：O（max（m，n））
 * 空间复杂度：O（n+m）
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int n1=a.size(),n2=b.size();
        int i=0,j=0,res=0,cur;
        string ans="";
        for(i=n1-1,j=n2-1;i>=0&&j>=0;--i,--j){
            cur = a[i]-'0'+b[j]-'0'+res;
            ans = to_string(cur%2)+ans;
            res = cur/2;
        }
        for(;i>=0;--i){
            cur = a[i]-'0'+res;
            ans = to_string(cur%2)+ans;
            res=cur/2;
        }
        for(;j>=0;--j){
            cur = b[j]-'0'+res;
            ans = to_string(cur%2)+ans;
            res=cur/2;
        }
        if(res>0) ans = to_string(res)+ans;
        return ans;
    }
};
