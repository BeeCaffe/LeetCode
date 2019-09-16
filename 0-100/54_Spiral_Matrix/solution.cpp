//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    static vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()==0 || matrix[0].size()==0) return res;
        int xmin=0,ymin=0,xmax=matrix[0].size()-1,ymax=matrix.size()-1;
        int i=0,j=0;
        res.push_back(matrix[i][j]);
        while(true){
            while(i<xmax) res.push_back(matrix[j][++i]) ;
            if(++ymin>ymax) break;
            while(j<ymax) res.push_back(matrix[++j][i]);
            if(--xmax<xmin) break;
            while(i>xmin) res.push_back(matrix[j][--i]);
            if(--ymax<ymin) break;
            while(j>ymin) res.push_back(matrix[--j][i]);
            if(++xmin>xmax) break;
        }
        return res;
    }
};

int main(){
    vector<vector<int>> matrix={{1,2,3},
                                {4,5,6},
                                {7,8,9}};
    vector<int> res=Solution::spiralOrder(matrix);
    for(auto dat:res){
        cout<<dat<<"    ";
    }
    return 0;
}