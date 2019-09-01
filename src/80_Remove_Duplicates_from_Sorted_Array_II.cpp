//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//

#include <cstddef>
#include <vector>
using namespace std;
class Solution {
public:
    static int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        for(int i=0;i<nums.size()-1;i++){
            int count=0,j=i;
            while(j>0&&j<nums.size()&&nums[j-1]==nums[j++]) count++;
            if(count>1) nums.erase(nums.begin()+i+1,nums.begin()+i+count);
        }
        return nums.size();
    }
};

int main(){
    vector<int> nums={1,1,1,2,2,3};
    Solution::removeDuplicates(nums);
    return 0;
}