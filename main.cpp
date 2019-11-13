#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    static int findShortestSubArray(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int maxtimes=0,ans=0,i,j;
        vector<int> visited(nums.size(),0);
        for(i=0;i<nums.size()&&!visited[i];++i){
            for(j=nums.size()-1;j>=i;--j){
                if(nums[j]==nums[i]) break;
            }
            int len=j-i+1;
            int times=0;
            for(int k=i;k<=j;++k){
                if(nums[k]==nums[i]){++times;visited[k]=true;}
            }
            if(times>maxtimes){ans=len;maxtimes=times;}
            else if(times==maxtimes){
                ans=min(len,ans);
            }
        }
        return ans;
    }
};
int main() {
    vector<int> nums={1,1,2,2,2,1};
    Solution::findShortestSubArray(nums);
    return 0;
}