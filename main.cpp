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
    static vector<int> sortedSquares(vector<int>& A) {
        if(A.size()==1) return {A[0]*A[0]};
        vector<int> ans;
        int mid=0;
        if(A[0]>=0) mid=0;
        if(A[0]<0){
            mid=A.size()-1;
            for(int i=1;i<A.size();++i) if(A[i-1]<0&&A[i]>=0){mid=i;break;}
        }
        int left=mid-1,right=mid;
        if(A[mid]=0) {left=mid-1;right=mid+1;ans.push_back(0);}
        while(left>=0 || right<A.size()){
            if(left>=0&&right<A.size()){
                if(abs(A[left])>abs(A[right])){
                    ans.push_back(A[right]*A[right]);
                    ans.push_back(A[left]*A[left]);
                }else{
                    ans.push_back(A[left]*A[left]);
                    ans.push_back(A[right]*A[right]);
                }
            }else if(left>=0) ans.push_back(A[left]*A[left]);
            else if(right<A.size()) ans.push_back(A[right]*A[right]);
            --left;++right;
        }
        return ans;
    }
};
int main() {
    vector<int> nums={-3,0,2};
    Solution::sortedSquares(nums);
    return 0;
}