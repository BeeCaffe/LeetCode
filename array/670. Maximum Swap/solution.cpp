/***********************************************************************************************************************
 * Created by caffe on 2019/11/13.
 * 670. Maximum Swap
 *  Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

    Example 1:

    Input: 2736
    Output: 7236
    Explanation: Swap the number 2 and the number 7.

    Example 2:

    Input: 9973
    Output: 9973
    Explanation: No swap.

    Note:

        The given number is in the range [0, 108]
 **********************************************************************************************************************/
/**
 * solution 1： 分析法
 *  1）将nums的各位数拆开来，然后存在一个vector里面，从低位到高位
 *  2）将vector排序后，从vector的末尾开始遍历，找到第一个不是当前位置最大的数的index
 *  3）在0-index的范围内，找到最大的那个数字第一次出现的位置i，将i和index处的值互换
 *  4）将vector数组还原成为数字并返回
 *  时间复杂度：O（n）
 *  空间复杂度：O（n）
 */
class Solution {
public:
    int maximumSwap(int num) {
        vector<int> nums;
        while(num>0){
            nums.push_back(num%10);
            num/=10;
        }
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(),sortedNums.end());
        int index=0;
        for(int i=nums.size()-1;i>=0;--i){
            if(nums[i]!=sortedNums[i]){ index=i;break;}
        }
        int maximum=INT_MIN;
        for(int i=0;i<=index;++i){
            maximum=max(maximum,nums[i]);
        }
        for(int i=0;i<=index;++i){
            if(maximum==nums[i]){
                int tmp=nums[i];
                nums[i]=nums[index];
                nums[index]=tmp;
                break;
            }
        }
        int ans=0;
        for(int i=nums.size()-1;i>=0;--i){
            ans=ans*10+nums[i];
        }
        return ans;
    }
};