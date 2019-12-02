#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
using namespace std;
class Solution {
public:
    static bool canThreePartsEqualSum(vector<int>& A) {
        vector<int> sum(A.size()+1,0);
        for(int i=1;i<sum.size();++i){
            sum[i]=sum[i-1]+A[i-1];
        }
        int left=1,right;
        while(left<sum.size()-1){
            right=left+1;
            int log=left;
            int keysum=sum[left];
            for(;right<sum.size();++right){
                if(right<A.size()&&A[right]==0) continue;
                if(sum[right]-sum[log]==keysum) log=right;
            }
            if(log==sum.size()-1) return true;
            ++left;
        }
        return false;
    }
};
int main() {
    vector<int> num={30,-23,3,14,-10,4,-6,6,18};
    Solution::canThreePartsEqualSum(num);
    return 0;
}