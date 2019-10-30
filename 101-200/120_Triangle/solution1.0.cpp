/***********************************************************************************************************************
 * Created by caffe on 2019/10/30.
 * 题干：
        Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
        For example, given the following triangle

        [
             [2],
            [3,4],
           [6,5,7],
          [4,1,8,3]
        ]

        The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 解法一：回溯法
 *      从最后一层开始，找到更后面一层左，右小的那一个加上当前一层的值，存储一个vector里面，就得到了到当前层的最短路径，后面依此类推。
 * 时间复杂度：O（n2）
 * 空间复杂度：O（n）
 **********************************************************************************************************************/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0) return 0;
        int deep=triangle.size();
        vector<int> res(deep+1,0);
        for(int i=deep-1;i>=0;i--){
            vector<int> tmp=triangle[i];
            for(int j=0;j<tmp.size();++j){
                res[j]=min(res[j],res[j+1])+tmp[j];
            }
        }
        return res[0];
    }
};