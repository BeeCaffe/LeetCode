/***********************************************************************************************************************
 * Created by caffe on 2019/12/3.
 * 1052. Grumpy Bookstore Owner
 * Today, the bookstore owner has a store open for customers.length minutes.  Every minute, some number of customers (customers[i]) enter the store, and all those customers leave after the end of that minute.

    On some minutes, the bookstore owner is grumpy.  If the bookstore owner is grumpy on the i-th minute, grumpy[i] = 1, otherwise grumpy[i] = 0.  When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise they are satisfied.

    The bookstore owner knows a secret technique to keep themselves not grumpy for X minutes straight, but can only use it once.

    Return the maximum number of customers that can be satisfied throughout the day.

    Example 1:

    Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
    Output: 16
    Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes.
    The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.

    Note:
        1 <= X <= customers.length == grumpy.length <= 20000
        0 <= customers[i] <= 1000
        0 <= grumpy[i] <= 1

 **********************************************************************************************************************/
/**
 * error solution 1 : analysis method
 * 暴力算法的思路是先算出所有不生气时间的总满意时间数sum，再将X秒加在任意一段时间上，找到加上X秒的不生气时间之后的最大值
 * 再把两个部分的时间加起来就可以了。
 * time complexity : O(nx)
 * space complexity : O(1)
 */
 //Time Limit Exceed
 class Solution {
 public:
     int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
         int sum=0;
         for(int i=0;i<customers.size();++i) if(grumpy[i]==0) sum+=customers[i];
         int grumpy_sum=0;
         for(int i=0;i<customers.size();++i){
             int tmpsum=0;
             for(int j=i;j<i+X;++j){
                 if(j<grumpy.size()&&grumpy[j]==1) tmpsum+=customers[j];
             }
             grumpy_sum=max(grumpy_sum,tmpsum);
         }
         return sum+grumpy_sum;
     }
 };
 /**
  * solution 2 : sliding windows
  * 大概思路和思路一一样，都是先把grumpy为0的加起来，只是在求X的时间段的时候使用的滑动窗口的算法，因此可以AC
  * 时间复杂度：O（n）
  * 空间复杂度：O（1）
  */
 class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int sum=0;
        for(int i=0;i<customers.size();++i) if(grumpy[i]==0) sum+=customers[i];
        int grusum=0;
        for(int i=0;i<X;++i){
            if(grumpy[i]==1) grusum+=customers[i];
        }
        int maxsum=grusum;
        for(int i=X;i<grumpy.size();++i) {
            if(grumpy[i-X]==1) grusum-=customers[i-X];
            if(grumpy[i]==1) grusum+=customers[i];
            maxsum=max(maxsum,grusum);
        }
        return maxsum+sum;
    }
};

