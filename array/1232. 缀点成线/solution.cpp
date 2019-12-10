/***********************************************************************************************************************
 * Created by caffe on 2019/12/10.
 * 在一个 XY 坐标系中有一些点，我们用数组 coordinates 来分别记录它们的坐标，其中 coordinates[i] = [x, y] 表示横坐标为 x、纵坐标为 y 的点。

    请你来判断，这些点是否在该坐标系中属于同一条直线上，是则返回 true，否则请返回 false.

 **********************************************************************************************************************/
/**
 * solution 1 : 分析法
 * 如果点在同一条直线上，那么它们的斜率必然相同。但是直接求斜率可能会是浮点数，且存在斜率无限大的情况。因此考虑使用公式
 * （yi-y0）/（xi-x0）=（y1-y0）/（x1-x0），转而采用乘法来进行验证。
 * 时间复杂度： O（n）
 * 空间复杂度： O（1）
 * 执行用时 :4 ms, 在所有 cpp 提交中击败了99.91% 的用户
 * 内存消耗 :10.2 MB, 在所有 cpp 提交中击败了100.00%
 */
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x0=coordinates[0][0],y0=coordinates[0][1];
        int x1=coordinates[1][0],y1=coordinates[1][1];
        for(int i=2;i<coordinates.size();++i){
            int xi=coordinates[i][0],yi=coordinates[i][1];
            if((y1-y0)*(xi-x0)!=(yi-y0)*(x1-x0)) return false;
        }
        return true;
    }
};