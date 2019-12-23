//
// Created by caffe on 2019/12/19.
//
/*
 * 9. 回文数
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 */
/*
 * solution 1 : two pointer
 * time complexity : O(n)
 * space complexity : O(n)
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 ) return false;
        if(x==0) return true;
        vector<int> num;
        while(x!=0){
            num.push_back(x%10);
            x/=10;
        }
        return check(num);
    }

    bool check(vector<int> &num){
        int left=0,right=num.size()-1;
        while(left<right&&num[left]==num[right]){
            ++left;
            --right;
        }
        if(left>=right) return true;
        return false;
    }
}
/*
 * solution 2 : math method
 * time complexity : O(n)
 * space complexity : O(1)
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==0) return true;
        int div=1;
        int num=x;
        while(num/10!=0) {div*=10;num/=10;}
        while(x!=0){
            int lower=x%10;
            int higher=x/div;
            if(lower!=higher) return false;
            x-=higher*div;
            x/=10;
            div/=100;
        }
        return true;

    }
};