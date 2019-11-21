/***********************************************************************************************************************
 * Created by caffe on 2019/11/21.
 * 779. 第K个语法符号
 * 在第一行我们写上一个 0。接下来的每一行，将前一行中的0替换为01，1替换为10。
    给定行数 N 和序数 K，返回第 N 行中第 K个字符。（K从1开始）
    例子:
    输入: N = 1, K = 1
    输出: 0
    输入: N = 2, K = 1
    输出: 0
    输入: N = 2, K = 2
    输出: 1
    输入: N = 4, K = 5
    输出: 1
    解释:
    第一行: 0
    第二行: 01
    第三行: 0110
    第四行: 01101001
 **********************************************************************************************************************/
/**
 * solution 1 ： bfs（广度优先遍历，层次遍历）
 * 先将0压入队列，再出队，每次遇到0或者1分别将01和10压入队列。当到达第N层的时侯，输出第K个数字即可；
 * 时间复杂度：(2^n)
 * 空间复杂度:(2^n)
 */
class Solution {
public:
    int kthGrammar(int N, int K) {
        queue<int> que;
        int level=1;
        que.push(0);
        while(!que.empty()&&level<N){
            for(int i=que.size()-1;i>=0;--i){
                int val=que.front();que.pop();
                if(val==0){
                    que.push(0);que.push(1);
                }else if(val==1){
                    que.push(1);que.push(0);
                }
            }
            ++level;
        }
        if(que.size()<K) return -1;
        for(int i=0;i<K-1;++i) que.pop();
        return que.front();
    }
};
/**
 * solution 2 : 递归（父子递推）
 * 第 K 个数字是上一行第 (K+1) / 2 个数字生成的。如果上一行的数字为 0，被生成的数字为
 * 1 - (K%2)，如果上一行的数字为 1，被生成的数字为 K%2。
 * 时间复杂度：O（n）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N==1) return 0;
        return (~K&1)^kthGrammar(N-1,(K+1)/2);
    }
};