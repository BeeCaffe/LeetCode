
//
// Created by caffe on 2019/12/19.
//
/*
 * 13. 罗马数字转整数
 *
 */
//执行用时 :8 ms, 在所有 cpp 提交中击败了97.85%的用户
//内存消耗 :8.4 MB, 在所有 cpp 提交中击败了89.24%的用户
/**
 * solution 1 : brute method
 * time complexity : O(n)
 * space complexity : O(1)
 */
class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;++i){
            char ch=s[i];
            if(ch=='I'){
                if(i+1<n&&s[i+1]=='V') {ans+=4;++i;}
                else if(i+1<n&&s[i+1]=='X'){ans+=9;++i;}
                else ans+=1;
            }else if(ch=='X'){
                if(i+1<n&&s[i+1]=='L'){ans+=40;++i;}
                else if(i+1<n&&s[i+1]=='C'){ans+=90;++i;}
                else ans+=10;
            }else if(ch=='C'){
                if(i+1<n&&s[i+1]=='D'){ans+=400;++i;}
                else if(i+1<n&&s[i+1]=='M'){ans+=900;++i;}
                else ans+=100;
            }else{
                if(ch=='V') ans+=5;
                else if(ch=='L') ans+=50;
                else if(ch=='D') ans+=500;
                else ans+=1000;
            }
        }
        return ans;
    }
};