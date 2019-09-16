//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//

/**
 * 2.基于动态规划的递归算法
 *      这里的思路是回退，假设在位置(x,y)处的话，那么上一次的位置只可能是(x-1,y)或在(x,y-1)，那么可以考虑从终点回退
 *      如果能够到达（0，0）点则认为可以到达。代码虽然简单多了，但是时间复杂度依旧为O（n^2）.
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        return go(m,n);
    }
    int go(int row,int col){
        if(row==0&&col==0) return 1;
        if(row==0) return go(row,col-1);
        if(col==0) return go(row-1,col);
        return go(row-1,col)+go(row,col-1);
    }
};