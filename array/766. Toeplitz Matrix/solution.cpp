/***********************************************************************************************************************
 * Created by caffe on 2019/11/19.
 * 766. Toeplitz Matrix
 * A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

    Now given an M x N matrix, return True if and only if the matrix is Toeplitz.


    Example 1:

    Input:
    matrix = [
      [1,2,3,4],
      [5,1,2,3],
      [9,5,1,2]
    ]
    Output: True
    Explanation:
    In the above grid, the diagonals are:
    "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
    In each diagonal all elements are the same, so the answer is True.

    Example 2:

    Input:
    matrix = [
      [1,2],
      [2,2]
    ]
    Output: False
    Explanation:
    The diagonal "[1, 2]" has different elements.

 **********************************************************************************************************************/
/**
 * solution 1 : analysis
 * for first row and col,check row++ and col++,if matrix[row][col] != matrix[row-i][col-1] return false;
 * time complexity : O(mn)
 * space complexity : O(1)
 */
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int cols=matrix[0].size(),rows=matrix.size();
        if(cols==1&&rows==1) return true;
        for(int i=0;i<cols;++i){
            int r=0,c=i,num=matrix[r][c];
            while(r<rows&&c<cols){
                if(matrix[r][c]==num){
                    ++r;++c;
                }else return false;
            }
        }
        for(int i=1;i<rows;++i){
            int r=i,c=0,num=matrix[r][c];
            while(r<rows&&c<cols){
                if(matrix[r][c]==num){
                    ++r;++c;
                }else return false;
            }
        }
        return true;
    }
};