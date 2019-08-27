//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * 1. records all locations of value=1,and travel these point and set the rows and cols to 0;
 *    the time complexity is O(n^2) but the space complexity is O(n);
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size();
        vector<pair<int,int>> record;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    record.push_back(pair(i,j));
                }
            }
        }
        for(int x=0;x<record.size();x++){
            int row=record[x].first;
            int col=record[x].second;
            for(int i=0;i<cols;i++){
                matrix[row][i]=0;
            }
            for(int i=0;i<rows;i++){
                matrix[i][col]=0;
            }
        }
    }
};