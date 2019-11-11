/***********************************************************************************************************************
 * Created by caffe on 2019/11/5.
   Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

    Note: The algorithm should run in linear time and in O(1) space.

    Example 1:

    Input: [3,2,3]
    Output: [3]

    Example 2:

    Input: [1,1,1,3,3,2,2,2]
    Output: [1,2]
 **********************************************************************************************************************/
/**
 * solution1:map
 *      用一个map记录各个元素出现的次数，当大于n/3的时候加入结果集合，返回即可。
 *      (这个思路行不通，首先用一个map的话空间复杂度不满足O（1）的要求)
 */
 /**
  * solution2 ： 观众投票法
  *         由于题目要求找到大于或者等于💠n/3的数，那么这样的数最多存在两个。因此，我们第一次遍历是希望能够找到这两个候选数字，第二次遍历是为
  *         了求出这两个数字的出现次数，最后返回大于n/3的那1个或者两个。对于第一遍遍历，如果某个数出现就加一次，不出现就减去一次，当出现次数
  *         为0的时候就更换一个数字，这样的话最后留下来的数字必然是出现次数最多的那两个
  * 时间复杂度：O（n）
  * 空间复杂度：O（1）
  */
 class Solution {
 public:
     vector<int> majorityElement(vector<int>& nums) {
         int client1=0,client2=0,cnt1=0,cnt2=0,n=nums.size();
         vector<int> res;
         for(int num:nums){
             if(num==client1) cnt1++;
             else if(num==client2) cnt2++;
             else if(cnt1==0){ client1=num; cnt1=1;}
             else if(cnt2==0){ client2=num; cnt2=1;}
             else{
                 cnt1--;
                 cnt2--;
             }
         }
         cnt1=0;cnt2=0;
         for(int num:nums){
             if(client1==num) cnt1++;
             else if(client2==num) cnt2++;
         }
         if(cnt1>n/3) res.push_back(client1);
         if(cnt2>n/3) res.push_back(client2);
         return res;
     }
 };