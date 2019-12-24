//
// Created by caffe on 2019/12/24.
//
/*
 * 168. Excel表列名称
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
   例如，
        1 -> A
        2 -> B
        3 -> C
        ...
        26 -> Z
        27 -> AA
        28 -> AB
        ...
 */
/**
 * solution 1 : 找规律
 * 仔细观察会发现，从后往前，每一位都为n%26的结果。
 * 时间复杂度：O（n/26）
 * 空间复杂度：O（n）
 */
class Solution {
public:
    string convertToTitle(int n) {
        if(n==0) return "";
        string ans="";
        int tmp;
        string str=" ";
        while(n > 0){
            tmp = n%26;
            if(tmp==0){
                str[0]='A'+25;
                ans = str + ans;
            }else{
                str[0]='A'+n%26-1;
                ans = str + ans;
            }
            n= (n-1)/26;
        }
        return ans;
    }
};