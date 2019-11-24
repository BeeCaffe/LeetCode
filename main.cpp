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
    static vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        sort(A.begin(),A.end());
        for(int i=0;i<B.size();++i){
            int left=0,right=A.size();
            while(left<=right){
                int mid=left+(right-left)/2;
                if(A[mid]>B[i]) right=mid-1;
                else left=mid+1;
            }
            if(left<A.size()&&A[left]>B[i]) {
                ans.push_back(A[left]);
                A.erase(A.begin()+left);
            }else{
                ans.push_back(A[0]);
                A.erase(A.begin());
            }
        }
        return ans;
    }
};
int main() {
    vector<int> nums={0};
    vector<int> nums1={0};
    Solution::advantageCount(nums,nums1);
    return 0;
}