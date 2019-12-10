/***********************************************************************************************************************
 * Created by caffe on 2019/12/10.
 * 1252. 奇数值单元格的数目
 * 给你一个 n 行 m 列的矩阵，最开始的时候，每个单元格中的值都是 0。

    另有一个索引数组 indices，indices[i] = [ri, ci] 中的 ri 和 ci 分别表示指定的行和列（从 0 开始编号）。

    你需要将每对 [ri, ci] 指定的行和列上的所有单元格的值加 1。

    请你在执行完所有 indices 指定的增量操作后，返回矩阵中 「奇数值单元格」 的数目。`
 **********************************************************************************************************************/
/**
 * solution 1 : map 法
 * 将所有坐标信息存储在map里面，放置迭代访问，增加速度。
 * 时间复杂度：O（n）
 * 空间复杂度：O（nm）
 */
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        map<pair<int,int>,int> hashmap;//pt,nums
        int rows=n,cols=m;
        for(vector<int> index:indices){
            int r=index[0],c=index[1];
            for(int i=0;i<rows;++i){
                hashmap[pair<int,int>(i,c)]++;
            }
            for(int j=0;j<cols;++j){
                hashmap[pair<int,int>(r,j)]++;
            }
        }
        int ans=0;
        for(auto iter=hashmap.begin();iter!=hashmap.end();++iter){
            if((iter->second%2)!=0) ++ans;
        }
        return ans;
    }
};