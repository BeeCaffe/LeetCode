
//
// Created by caffe on 2019/12/18.
//
/*
 * 8. 字符串转换整数 (atoi)
 * 请你来实现一个 atoi 函数，使其能将字符串转换成整数。
   首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
   当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
   该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。
   注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。
   在任何情况下，若函数不能进行有效的转换时，请返回 0。
 */
/**
 * solution 1 : 暴力法
 * 注意需要考虑一些特殊情况可能会比较麻烦。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;
        long ans=0;
        char op=' ';
        for(int i=0;i<str.size();++i){
            char ch=str[i];
            if(ch==' ') continue;
            else if((ch=='-'||ch=='+') && (op==' ')){
                op=ch;
                if(i+1>str.size() || str[i+1]<'0' || str[i+1]>'9') return 0;
            }
            else if(ch>='0'&&ch<='9'){
                for(int j=i;j<str.size();++j){
                    if(str[j]>='0'&&str[j]<='9'){
                        ans= ans *10+str[j]-'0';
                        if((op=='+' || op==' ') && ans>INT_MAX) return INT_MAX;
                        if(op=='-' && -ans<INT_MIN) return INT_MIN;
                    }
                    else break;
                }
                break;
            }else break;
        }
        ans = op=='-' ? -ans:ans;
        if(ans>=INT_MAX) return INT_MAX;
        if(ans<=INT_MIN) return INT_MIN;
        return ans;
    }
};