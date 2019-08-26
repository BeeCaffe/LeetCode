//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    static int uniquePaths(int m, int n) {
        int paths=0;
        vector<vector<int>> map;
        vector<int> temp(m,0);
        for(int i=0;i<n;i++){//rows
            map.push_back(temp);
        }
        go(map,0,0,paths);
        return paths;
    }
    static void go(vector<vector<int>>& map,int row,int col,int& paths){
        if(col==(map[0].size()-1) && row==(map.size()-1)){
            paths++;
            return;
        }else{
            if( col >map[0].size()-1 ){
                return;
            }else if(map[row][col]==0){
                map[row][col]=1;
                go(map,row,col+1,paths);
                map[row][col]=0;
            }
            if(row>map.size()-1){
                return;
            }else if(map[row][col]==0){
                map[row][col]=1;
                go(map,row+1,col,paths);
                map[row][col]=0;
            }
        }
    }
};

int main(){
    std::cout<<Solution::uniquePaths(3,2)<<endl;
    return 0;
}