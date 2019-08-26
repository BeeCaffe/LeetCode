//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(0);
            }
            res.push_back(temp);
        }
        if(n==0) return res;
        int xmin=0,ymin=0,xmax=n-1,ymax=n-1;
        int number=0,i=0,j=0;
        res[i][j]=++number;
        while(true){
            while(i<xmax) res[j][++i]=++number;
            if(++ymin>ymax) break;
            while(j<ymax) res[++j][i]=++number;
            if(--xmax<xmin) break;
            while(i>xmin) res[j][--i]=++number;
            if(--ymax<ymin) break;
            while(j>ymin) res[--j][i]=++number;
            if(++xmin>xmax) break;
        }
        return res;
    }
};s