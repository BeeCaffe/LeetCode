#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
class Solution {
public:
        static int minSubArrayLen(int s, vector<int>& nums) {
            if(nums.size()==0) return 0;
            if(nums.size()==1) return 1;
            int minum=INT_MAX;
            help(nums,s,0,nums.size()-1,0,minum);
            return minum;
        }
        static void help(vector<int> &nums,int target,int beg,int end,int deep,int &minum){
            deep++;
            if(beg>end || target==0) return;
            for(int i=beg;i<=end;++i){
                if(target<=nums[i]){
                    minum=min(minum,deep);
                    return;
                }else{
                    help(nums,target-nums[i],i+1,end,deep,minum);
                }
            }
        }
    };

int main() {
    vector<int> nums({12,28,83,4,25,26,25,2,25,25,25,12});
    int s=213;
    cout<<Solution::minSubArrayLen(s,nums);
    return 0;
}