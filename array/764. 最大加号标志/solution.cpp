/***********************************************************************************************************************
 * Created by caffe on 2019/11/20.
 * 764. 最大加号标志
 * 在一个大小在 (0, 0) 到 (N-1, N-1) 的2D网格 grid 中，除了在 mines 中给出的单元为 0，其他每个单元都是 1。网格中包含 1 的最大的轴对齐加号标志是多少阶？返回加号标志的阶数。如果未找到加号标志，则返回 0。

一个 k" 阶由 1 组成的“轴对称”加号标志具有中心网格  grid[x][y] = 1 ，以及4个从中心向上、向下、向左、向右延伸，长度为 k-1，由 1 组成的臂。下面给出 k" 阶“轴对称”加号标志的示例。注意，只有加号标志的所有网格要求为 1，别的网格可能为 0 也可能为 1。



k 阶轴对称加号标志示例:

阶 1:
000
010
000

阶 2:
00000
00100
01110
00100
00000

阶 3:
0000000
0001000
0001000
0111110
0001000
0001000
0000000



示例 1：

输入: N = 5, mines = [[4, 2]]
输出: 2
解释:

11111
11111
11111
11111
11011

在上面的网格中，最大加号标志的阶只能是2。一个标志已在图中标出。



示例 2：

输入: N = 2, mines = []
输出: 1
解释:

11
11

没有 2 阶加号标志，有 1 阶加号标志。



示例 3：

输入: N = 1, mines = [[0, 0]]
输出: 0
解释:

0

没有加号标志，返回 0 。



提示：

    整数N 的范围： [1, 500].
    mines 的最大长度为 5000.
    mines[i] 是长度为2的由2个 [0, N-1] 中的数组成.
    (另外,使用 C, C++, 或者 C# 编程将以稍小的时间限制进行​​判断.)
 **********************************************************************************************************************/
/**
 * solution 1 ： 动态规划
 * 我们以每个点为加号中心，十字架的最大尺寸实际上就是最小的臂长。因此我们可以用一个二维数组dp[i][j]来记录以i，j为中心的最小臂长，然后找到dp
 * 中最大的数就是我们的结果。具体做法是，依次找到以i，j为中心的左，右，上，下四个臂的长度，然后将最小的存储在dp之中。
 * 时间复杂度： O（n2）
 * 空间复杂度： O（n2）
 */
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> dp(N,vector<int>(N,0));
        unordered_set<int> hash_set;
        int ans=INT_MIN;
        for(vector<int> pt:mines) hash_set.insert(pt[0]*N+pt[1]);
        for(int r=0;r<N;++r){
            int count=0;
            for(int c=0;c<N;++c){
                count=(hash_set.find(r*N+c)==hash_set.end()) ? count+1:0;
                dp[r][c]=count;
            }
            count=0;
            for(int c=N-1;c>=0;--c){
                count=(hash_set.find(r*N+c)==hash_set.end()) ? count+1:0;
                dp[r][c]=min(count,dp[r][c]);
            }
        }
        for(int c=0;c<N;++c){
            int count=0;
            for(int r=0;r<N;++r){
                count=(hash_set.find(r*N+c)==hash_set.end()) ? count+1:0;
                dp[r][c]=min(count,dp[r][c]);
            }
            count=0;
            for(int r=N-1;r>=0;--r){
                count=(hash_set.find(r*N+c)==hash_set.end()) ? count+1:0;
                dp[r][c]=min(count,dp[r][c]);
                ans=max(ans,dp[r][c]);
            }
        }
        return ans;
    }
};