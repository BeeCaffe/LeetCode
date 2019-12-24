//
// Created by caffe on 2019/12/24.
//
/*
 * 69. x 的平方根
 * 实现 int sqrt(int x) 函数。
 * 计算并返回 x 的平方根，其中 x 是非负整数。
 * 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 */
/**
 * solution 1 ： 牛顿法
 * 不想这么多，开根号一律用牛顿法来做，具体的：
 * sqrt(x)=n <=> x = n^2 <=> x-n^2=0
 * 令f(x)=x-a=0,其中a=n^2
 * 那么：f(x) = f(x0)+f'(x0)(x-x0)=0
 * 则：x-x0=-f'(x0)/f(x0) <=> xn+1 = xn - f(xn)/f'(xn)
 * 将f(x)=x^2-a 带回去
 * xn+1 = xn - (xn^2-a)/2xn
 * 上面就是牛顿迭代法的推导过程，然后写出代码，调整一下精度就行了。
 */
class Solution {
public:
    int mySqrt(int x) {
        double n = double(x);
        double cur = n;
        double err = 1e-1;
        while(abs(n-cur*cur)>err){
            cur = (cur+n/cur)/2.;
        }
        return static_cast<int>(cur);
    }
};