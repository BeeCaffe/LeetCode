/***********************************************************************************************************************
 * Created by caffe on 2019/11/12.
 * 621. Task Scheduler
 * Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

    However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

    You need to return the least number of intervals the CPU will take to finish all the given tasks.



    Example:

    Input: tasks = ["A","A","A","B","B","B"], n = 2
    Output: 8
    Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.



    Note:

        The number of tasks is in the range [1, 10000].
        The integer n is in the range [0, 100].
 **********************************************************************************************************************/
/**
 * solution 1 ： sort法，map法
 * 题意：给定一个char数组代表CPU需要做的任务，包含A-Z，每个任务都能够在一个单位时间内完成，但是相同的任务必须间隔时间n来完成，因此，叫我们
 * 求完成任务的最短时间。
 * 思路：这样一来我们可以考虑先将所有任务进行一个排序，先执行数目更多的任务，这样数目更多的任务总的等待时间会更少，因此我们采用一个map来存储
 * 任务，由于map的底层机制是红黑树，因此其本身就会是有序的（升序）。
 * 时间复杂度：O(time)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> map(26,0);
        for(char c:tasks) map[c-'A']++;
        sort(map.begin(),map.end());
        int time=0;
        while(map[25]>0){
            int i=0;
            while(i<=n){
                if(map[25]==0) break;
                if(i<26&&map[25-i]>0) map[25-i]--;
                time++;
                i++;
            }
            sort(map.begin(),map.end());
        }
        return time;
    }
};