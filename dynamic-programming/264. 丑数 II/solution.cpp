
//
// Created by caffe on 2019/12/17.
//
/*
 * 264. 丑数 II
 * 编写一个程序，找出第 n 个丑数。
 * 丑数就是只包含质因数 2, 3, 5 的正整数。
 */
/**
 * solution 1 : 贪心算法（暴力）
 * 求出所有的丑数，然后返回第n个即可。
 * 时间复杂度：O（n3）
 * 空间复杂度：O（max）
 */
class Solution {
public:
    static int nthUglyNumber(int n) {
        vector<int> ans;
        for(long a=1;a<INT_MAX;a*=2)
            for(long b=a;b<INT_MAX;b*=3)
                for(long c=b;c<INT_MAX;c*=5)
                    ans.push_back(c);
        sort(ans.begin(),ans.end());
        return ans[n-1];
    }
};