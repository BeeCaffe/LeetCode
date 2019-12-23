
//
// Created by caffe on 2019/12/19.
//
/*
 * 29. 两数相除
 *
 */
/**
 * solution 1 : 位移法
 * 由于对于一个数每右移动一位代表乘以2的倍数，每左移动一位代表除以2，因此解决办法是将除数一直向右移动至小于
 * 被除数的剩余数。然后再将所有的倍数累计起来即可。
 * 时间复杂度：O（）
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0) return 0;
        bool op=true;
        if(dividend<0&&divisor>0 || dividend>0&&divisor<0) op=false;
        long ans=0;
        long long dividend_=abs(static_cast<long>(dividend));
        if(dividend_<0){dividend_=2147483684;}
        long long divisor_=abs(long(divisor));
        while(dividend_>=divisor_){
            long long tmp=divisor_;
            long long count=0;
            while(dividend_>=tmp) {tmp=tmp<<1;++count;}
            tmp=tmp>>1;--count;
            ans+=pow(2,count);
            if(op&&ans>INT_MAX || !op&&ans<INT_MIN) return INT_MAX;
            dividend_-=tmp;
        }
        return op ? ans : -ans;
    }
};