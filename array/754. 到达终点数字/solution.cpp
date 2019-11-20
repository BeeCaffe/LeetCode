/***********************************************************************************************************************
 * Created by caffe on 2019/11/19.
 * 754. 到达终点数字
 * 在一根无限长的数轴上，你站在0的位置。终点在target的位置。

    每次你可以选择向左或向右移动。第 n 次移动（从 1 开始），可以走 n 步。

    返回到达终点需要的最小移动次数。

    示例 1:

    输入: target = 3
    输出: 2
    解释:
    第一次移动，从 0 到 1 。
    第二次移动，从 1 到 3 。

    示例 2:

    输入: target = 2
    输出: 3
    解释:
    第一次移动，从 0 到 1 。
    第二次移动，从 1 到 -1 。
    第三次移动，从 -1 到 2 。

    注意:

        target是在[-10^9, 10^9]范围中的非零整数。
 **********************************************************************************************************************/
/**
 * error solution 1 : bfs(bread first search)(Time Limit Exceed)
 * time complexity : O(log2n)
 * space complexity : O(1)
 */
class Solution {
public:
    int reachNumber(int target) {
        int n=1,now=0;
        queue<int> qu;
        qu.push(0);
        while(true){
            for(int i=qu.size()-1;i>=0;--i){
                int now=qu.front();qu.pop();
                if(now==target) return n-1;
                qu.push(now+n);
                qu.push(now-n);
            }
            ++n;
        }
        return 0;
    }
};
