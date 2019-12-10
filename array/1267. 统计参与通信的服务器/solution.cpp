/***********************************************************************************************************************
 * Created by caffe on 2019/12/10.
 * 1267. 统计参与通信的服务器
 * 这里有一幅服务器分布图，服务器的位置标识在 m * n 的整数矩阵网格 grid 中，1 表示单元格上有服务器，0 表示没有。

    如果两台服务器位于同一行或者同一列，我们就认为它们之间可以进行通信。

    请你统计并返回能够与至少一台其他服务器进行通信的服务器的数量。
 **********************************************************************************************************************/
/**
 * solution 1 ： 分析法
 * 遍历整个grid，当该点有电脑时，分别遍历四个方向，如果有其它电脑，则结果加一。
 * 时间复杂度：O（nm）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        int ans=0;
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(grid[i][j]){
                    if(check(grid,i,j,0,1)||check(grid,i,j,0,-1)||check(grid,i,j,1,0)||check(grid,i,j,-1,0)) ++ans;
                }
            }
        }
        return ans;
    }

    bool check(vector<vector<int>> &grid,int x,int y,int dirx,int diry){
        int i=x+dirx,j=y+diry;
        while(i>=0&&i<grid.size()&&j>=0&&j<grid[0].size()){
            if(grid[i][j]==1) return true;
            i+=dirx;
            j+=diry;
        }
        return false;
    }
};