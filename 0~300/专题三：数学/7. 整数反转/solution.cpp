
//
// Created by caffe on 2019/12/18.
//
/*
 * 7. 整数反转
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 */

/**
 * solution : 暴力法
 * 直接每一位拿出来并且重新组合起来
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int reverse(int x) {
        long ans=0;
        int count=0;
        long num=abs(long(x));
        if(num<10) return x;
        while(num!=0){
            int this_bit=num%10;
            num/=10;
            ans=ans*10+this_bit;
        }
        ans = x<0 ? -ans:ans;
        if(ans>INT_MAX || ans<INT_MIN) return 0;
        return ans;
    }
};