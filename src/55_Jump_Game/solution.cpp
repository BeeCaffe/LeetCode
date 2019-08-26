//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
#include <vector>
using namespace std;
class Solution {
public:
    static bool canJump(vector<int>& nums) {
        int i=0,step=0;
        for(i=0;i<nums.size();i+=step){
            step=nums[i];
        }
        return i==nums.size()-1 ? true:false;
    }
};

int main(){
    vector<int> num={2,3,1,1,4};
    Solution::canJump(num);
    return 0;
}