/***********************************************************************************************************************
 * Created by caffe on 2019/12/10.
 * 1260. 二维网格迁移
 * 给你一个 n 行 m 列的二维网格 grid 和一个整数 k。你需要将 grid 迁移 k 次。

    每次「迁移」操作将会引发下述活动：

        位于 grid[i][j] 的元素将会移动到 grid[i][j + 1]。
        位于 grid[i][m - 1] 的元素将会移动到 grid[i + 1][0]。
        位于 grid[n - 1][m - 1] 的元素将会移动到 grid[0][0]。

    请你返回 k 次迁移操作后最终得到的 二维网格。
 **********************************************************************************************************************/
/**
 * solution 1 ： 分析法
 * 直接按照要求做就可以了。
 * 时间复杂度：O（kmn）
 * 空间复杂度：O（nm）
 */
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        for(int i=0;i<k;++i) move(grid);
        return grid;
    }

    void move(vector<vector<int>> &grid){
        vector<vector<int>> grid_cp(grid);
        int rows=grid.size(),cols=grid[0].size();
        for(int r=0;r<rows;++r){
            for(int c=0;c<cols;++c){
                if(c+1<cols) grid_cp[r][c+1]=grid[r][c];
                if(r+1<rows&&c==cols-1) grid_cp[r+1][0]=grid[r][c];
                if(r==rows-1&&c==cols-1) grid_cp[0][0]=grid[r][c];
            }
        }
        grid=grid_cp;
    }
};