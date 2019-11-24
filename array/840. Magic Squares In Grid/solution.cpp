/***********************************************************************************************************************
 * Created by caffe on 2019/11/24.
 * 840. Magic Squares In Grid
 * A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

    Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).



    Example 1:

    Input: [[4,3,8,4],
            [9,5,1,9],
            [2,7,6,2]]
    Output: 1
    Explanation:
    The following subgrid is a 3 x 3 magic square:
    438
    951
    276

    while this one is not:
    384
    519
    762

    In total, there is only one magic square inside the given grid.

    Note:

        1 <= grid.length <= 10
        1 <= grid[0].length <= 10
        0 <= grid[i][j] <= 15


 **********************************************************************************************************************/
/**
 * solution 1 : 分析法
 * 思路很简单，次次判断每个3x3的矩阵是不是幻方就可以了。问题在于判断有点麻烦。
 * 时间复杂度： O（n2）
 * 空间复杂度：O（n）
 */
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cols=grid[0].size(),rows=grid.size();
        if(rows<3||cols<3) return 0;
        int ans=0;
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j)
                if(isMagic(grid,i,j)) ++ans;
        }
        return ans;
    }
    bool isMagic(vector<vector<int>> &grid,int x0,int y0){
        int cols=grid[0].size(),rows=grid.size();
        vector<int> arr(10,0);
        if(x0+2>=rows||y0+2>=cols) return false;
        int sumc=0,sumr=0,sumd=0;
        for(int i=0;i<3;++i){
            sumd+=grid[x0+i][y0+i];
        }
        for(int i=0;i<3;++i){
            sumr=0;sumc=0;
            for(int j=0;j<3;++j){
                sumr+=grid[x0+i][y0+j];
                sumc+=grid[x0+j][y0+i];
                if(grid[x0+i][y0+j]>9||grid[x0+i][y0+j]<=0||arr[grid[x0+i][y0+j]]>=1) return false;
                else ++arr[grid[x0+i][y0+j]];
            }
            if(sumc!=sumr||sumr!=sumd||sumc!=sumd) return false;
        }
        return true;
    }
};