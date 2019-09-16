//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
#include <vector>
#include <iostream>
using namespace std;
/**
 * 1.递归暴力解法
 *      每次走到一个位置继续向下和向右走，直到走到终点为止，并记录下到达终点的方法数，但是这种方法时间消耗太大，无法AC
 *      时间复杂度为O(2^n),非常糟糕的时间复杂度，空间复杂度为O(1).同时我用栈来实现了递归算法的非递归形式，时间复杂度
 *      依旧为O(2^n)，空间复杂度为O(n)。
 */
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