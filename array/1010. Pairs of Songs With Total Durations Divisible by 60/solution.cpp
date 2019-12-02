/***********************************************************************************************************************
 * Created by caffe on 2019/12/2.
 * 1010. Pairs of Songs With Total Durations Divisible by 60
 * In a list of songs, the i-th song has a duration of time[i] seconds.

    Return the number of pairs of songs for which their total duration in seconds is divisible by 60.  Formally, we want the number of indices i < j with (time[i] + time[j]) % 60 == 0.

    Example 1:

    Input: [30,20,150,100,40]
    Output: 3
    Explanation: Three pairs have a total duration divisible by 60:
    (time[0] = 30, time[2] = 150): total duration 180
    (time[1] = 20, time[3] = 100): total duration 120
    (time[1] = 20, time[4] = 40): total duration 60

    Example 2:

    Input: [60,60,60]
    Output: 3
    Explanation: All three pairs have a total duration of 120, which is divisible by 60.

    Note:

        1 <= time.length <= 60000
        1 <= time[i] <= 500
 **********************************************************************************************************************/
/**
 * error solution 1 : two pointer
 * time complexity : O(n2)
 * space complexity : O(1)
 */
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int left=0,right;
        int ans=0;
        while(left<time.size()){
            right=left+1;
            while(right<time.size()){
                if((time[right++]+time[left])%60==0) ++ans;
            }
            ++left;
        }
        return ans;
    }
};
/**
 * solution 2 : count method
 * 将所有元素取余60的值放在一个数组cnt里面并计数，然后遍历整个数组，对数组下标i找到60-i下标中的元素个数，如果两者元素
 * 个数都不为0，那么能够组合在一起并且能够被60整除的数目一共有cnt[i]*cnt[60-i],并且当前的i已经全部算过了，所以其中的
 * 个数需要置为0。但是当i等于0或者30的时候情况就有所不同了，这个时候需要和自己组合才行，我们考虑其中每一个取余为0或30的
 * 数与其它n-1个数组合，以此类推就应该是1+2+...+n-1，这样一来个数应该是n*（n-1）/2个。
 * space complexity : O(n)
 * time complexity : O(60)
 */
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60,0);
        int ans=0;
        for(int num:time) cnt[num%60]++;
        for(int i=0;i<60;++i){
            if(i==0 || i==30) ans+=(cnt[i]-1)*cnt[i]/2;
            else{
                int tmp=60-i;
                if(tmp<60&&cnt[tmp]!=0) ans+=cnt[i]*cnt[tmp];
                cnt[i]=0;
            }
        }
        return ans;
    }
};