/***********************************************************************************************************************
 * Created by caffe on 2019/11/13.
 * 695. Max Area of Island
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

    Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

    Example 1:

    [[0,0,1,0,0,0,0,1,0,0,0,0,0],
     [0,0,0,0,0,0,0,1,1,1,0,0,0],
     [0,1,1,0,1,0,0,0,0,0,0,0,0],
     [0,1,0,0,1,1,0,0,1,0,1,0,0],
     [0,1,0,0,1,1,0,0,1,1,1,0,0],
     [0,0,0,0,0,0,0,0,0,0,1,0,0],
     [0,0,0,0,0,0,0,1,1,1,0,0,0],
     [0,0,0,0,0,0,0,1,1,0,0,0,0]]

    Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.

    Example 2:

    [[0,0,0,0,0,0,0,0]]

    Given the above grid, return 0.

    Note: The length of each dimension in the given grid does not exceed 50.

 **********************************************************************************************************************/
/**
 * 错误思路 ： 扫描法
 * 我想的是由于是连续的，所以可以先找到最长的子行，然后在找到与子行同列的1就可以了，具体的方法是，依次遍历每一行，
 * 当该行的当前元素为1的时候，数一下列一共有多少个，然后数出最终的结果就可以了。
 * 但是实际上还存在这样的情况
 * [[0,1,1],
 *  [1,1,0]]
 *  它们实际上是连续的，但是并不是在最长子行的所有列上都有。所以这个思路是错误的，正确的思路应该是dfs。
 */
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int ans=0;
        int rows=grid.size(),cols=grid[0].size();
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(grid[i][j]){
                    int count=0;
                    count+=countRow(grid,i,j);
                    for(int k=j+1;k<cols;++k){
                        if(grid[i][k]==1) count+=countRow(grid,i,k);
                        else break;
                    }
                    ans=max(ans,count);
                }
            }
        }
        return ans;
    }
    int countRow(vector<vector<int>> &grid,int r,int c){
        int count=1;
        int up=r-1,down=r+1;
        while(up>=0 && grid[up--][c]==1) ++count;
        while(down<grid.size() &&grid[down++][c]==1) ++count;
        return count;
    }
};
/**
 * solution 1 ： dfs（深度优先遍历）
 * 时间复杂度：O（R*C）
 * 空间复杂度：O（mn）
 */
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        int ans=0;
        vector<vector<bool>> visited(rows,vector<bool>(cols,0));
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(grid[i][j]&&!visited[i][j]){
                    int islandNums=0;
                    maxIsland(grid,visited,islandNums,i,j);
                    ans=max(ans,islandNums);
                }
            }
        }
        return ans;
    }
    void maxIsland(vector<vector<int>> &grid,vector<vector<bool>> &visited,int &islandNums,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0) return;
        if(!visited[i][j]){
            islandNums++;
            visited[i][j]=true;
            maxIsland(grid,visited,islandNums,i+1,j);
            maxIsland(grid,visited,islandNums,i-1,j);
            maxIsland(grid,visited,islandNums,i,j+1);
            maxIsland(grid,visited,islandNums,i,j-1);
        }
    }
};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,0));
        int ans=0;
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                int nums=0;
                if(!visited[i][j]&&grid[i][j]==1) nums=maxIsland(grid,visited,i,j);
                ans=max(ans,nums);
            }
        }
        return ans;
    }

    int maxIsland(vector<vector<int>> &grid,vector<vector<bool>> &visited,int r,int c){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || visited[r][c] || grid[r][c]==0) return 0;
        visited[r][c]=1;
        return (1+maxIsland(grid,visited,r-1,c)+maxIsland(grid,visited,r+1,c)+maxIsland(grid,visited,r,c-1)+maxIsland(grid,visited,r,c+1));
    }
};