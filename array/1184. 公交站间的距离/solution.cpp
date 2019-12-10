/***********************************************************************************************************************
 * Created by caffe on 2019/12/9.
 * 1184. 公交站间的距离
 * 环形公交路线上有 n 个站，按次序从 0 到 n - 1 进行编号。我们已知每一对相邻公交站之间的距离，distance[i] 表示编号为 i 的车站和编号为 (i + 1) % n 的车站之间的距离。

    环线上的公交车都可以按顺时针和逆时针的方向行驶。

    返回乘客从出发点 start 到目的地 destination 之间的最短距离。
 **********************************************************************************************************************/
/**
 * solution 1 ： 分析法
 * 直接做就是了，没什么好说的。
 * 执行结果：
    通过
    显示详情
    执行用时 :4 ms, 在所有 cpp 提交中击败了96.47% 的用户
    内存消耗 :9 MB, 在所有 cpp 提交中击败了100.00%
 * 时间复杂度：O（n）
 * 空间复杂度： O（1）
 */
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int minpth1=0;
        int n=distance.size();
        for(int i=start;i!=destination;++i){
            minpth1+=distance[i];
            if(i==n-1) i=-1;
        }
        int minpth2=0;
        for(int i=start;i!=destination;--i){
            if(i==0) i=n;
            minpth2+=distance[i-1];
        }
        return min(minpth1,minpth2);
    }
};