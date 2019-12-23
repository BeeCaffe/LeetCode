//
// Created by caffe on 2019/12/23.
//
/*
 * 50. Pow(x, n)
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 */
/**
 * solution 1 : 暴力解法
 * 直接把x乘以n次就可以了。注意当n<0时，我们应该将x转变成1/x
 * 时间复杂度：O（n）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        double ans = 1;
        long long N=n;
        if(N<0){
            x=1/x;
            N=-N;
        }
        for(int i=0;i<N;++i) ans*=x;
        return ans;
    }
};
/**
 * solution 2 : 快速递归法
 */
class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        if(N<0){
            N=-N;
            x=1/x;
        }
        return assist(x,N);
    }
    double assist(double x,long long n){
        if(n==0) return 1.;
        double half = assist(x,n/2);
        if(n%2==0) return half*half;
        return half*half*x;
    }
};