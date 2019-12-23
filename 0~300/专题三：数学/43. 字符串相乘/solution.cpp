//
// Created by caffe on 2019/12/23.
//
/*
 * 43. 字符串相乘
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 */
/**
 * solution 1 : 暴力法
 * 按照手动算乘法的思路用代码实现即可，注意每一个中间步骤都必须使用string来存储，否则的话会造成溢出
 * 时间复杂度：O（n4）
 * 空间复杂度：O（）
 */
 //Time Limmit Exceed
 class Solution {
 public:
     string multiply(string num1, string num2) {
         int n1=num1.size(),n2=num2.size();
         if(n1==1&&num1[0]==0 || n2==1&&num2[0]==0) return 0;
         int res=0,cur=0,mul;
         string ans="",idx_="",idx="",tmp_mul="",tmp;
         for(int i=n1-1;i>=0;--i){
             res=0,cur=num1[i]-'0';
             idx="";
             tmp_mul = "";
             for(int j=n2-1;j>=0;--j){
                 mul= cur*(num2[j]-'0')+res;
                 tmp = to_string(mul%10);
                 tmp+=idx;
                 idx+="0";
                 str_add(tmp_mul,tmp);
                 res=mul/10;
             }
             if(res>0){
                 tmp = to_string(res);
                 tmp+=idx;
                 str_add(tmp_mul,tmp);
             }
             tmp_mul+=idx_;
             idx_+="0";
             str_add(ans,tmp_mul);
         }
         if(ans.size()>0&&ans[0]=='0') return "0";
         return ans;
     }

     void str_add(string &s1,string s2){
         int n1=s1.size(),n2=s2.size();
         int res=0,cur;
         string ans="";
         int i,j;
         for(i=n1-1,j=n2-1;j>=0,i>=0;--i,--j){
             cur = s1[i]-'0'+s2[j]-'0'+res;
             ans = to_string(cur%10)+ans;
             res = cur/10;
         }
         for(;i>=0;--i){
             cur = s1[i]-'0'+res;
             ans = to_string(cur%10)+ans;
             res = cur/10;
         }
         for(;j>=0;--j){
             cur = s2[j]-'0'+res;
             ans = to_string(cur%10)+ans;
             res = cur/10;
         }
         if(res>0) ans = to_string(res)+ans;
         s1=ans;
         return;
     }
 };
 /**
  * solution 1 ： 暴力破解
  * 一样是暴力破解，但是没有上面得解答那么复杂，时刻找到当前得出得数应该在得位置，并放在当前位置上就可以了
  * 时间复杂度：O（n2）
  * 空间复杂度：O（n+m）
  */
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size(),n2=num2.size();
        string ans(n1+n2,'0');
        int res=0;
        int i,j;
        for(i=n1-1;i>=0;--i){
            res = 0;
            for(j=n2-1;j>=0;--j){
                int pre = ans[i+j+1]-'0';
                int cur = (num1[i]-'0')*(num2[j]-'0')+res+pre;
                ans[i+j+1] = cur%10+'0';
                res = cur/10;
            }
            if(res>0) ans[i+j+1] = res+'0';
        }
        for(int i=0;i<ans.size();++i){
            if(ans[i]!='0' || i==ans.size()-1){
                ans = ans.substr(i,ans.size()-i);
                break;
            }
        }
        return ans;
    }
};