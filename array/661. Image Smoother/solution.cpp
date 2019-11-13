/***********************************************************************************************************************
 * Created by caffe on 2019/11/13.
 * 661. Image Smoother
 * Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

    Example 1:

    Input:
    [[1,1,1],
     [1,0,1],
     [1,1,1]]
    Output:
    [[0, 0, 0],
     [0, 0, 0],
     [0, 0, 0]]
    Explanation:
    For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
    For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
    For the point (1,1): floor(8/9) = floor(0.88888889) = 0

    Note:

        The value in the given matrix is in the range of [0, 255].
        The length and width of the given matrix are in the range of [1, 150].
 **********************************************************************************************************************/
/**
 * solution 1： 分析法
 * 没啥好说的直接算就是
 * 时间复杂度：O（mn）
 * 空间复杂度：O（mn）
 */
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int rows=M.size(),cols=M[0].size();
        vector<int> neighbors={0,-1,1};
        vector<vector<int>> ans(M);
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                int sum=0;
                int count=0;
                for(int r=0;r<3;++r){
                    for(int c=0;c<3;++c){
                        int row=i+neighbors[r];
                        int col=j+neighbors[c];
                        if(row>=0&&row<rows&&col>=0&&col<cols){
                            sum+=M[row][col];
                            ++count;
                        }
                    }
                }
                ans[i][j]=sum/count;
            }
        }
        return ans;
    }
};