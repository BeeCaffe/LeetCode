//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * 1. Binary search
 *      using binary search to search target's row and column index.and time complexity is Log2(n),the space
 *      complexity is O(1).
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0) return false;
        int rows=matrix.size(),cols=matrix[0].size();
        int left=0,right=rows-1;
        //search row
        while(left<=right){
            int mid=(left+right)/2;
            if(matrix[mid][0]==target) return true;
            else if(matrix[mid][0]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        int row=right;
        if(row<0||row>rows-1) return false;
        //search col
        left=0;
        right=cols-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(matrix[row][mid]==target) return true;
            else if(matrix[row][mid]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        int col=right;
        if(col<0||col>cols-1) return false;
        if(matrix[row][col]==target) return true;
        else return false;
    }
};