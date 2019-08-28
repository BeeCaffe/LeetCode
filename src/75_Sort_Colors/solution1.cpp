//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3]={0};
        for(int i=0;i<nums.size();i++){
            switch(nums[i]){
                case 0:
                    count[0]++;
                    break;
                case 1:
                    count[1]++;
                    break;
                case 2:
                    count[2]++;
                    break;
                default:
                    break;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(i<count[0]) nums[i]=0;
            else if(count[0]<=i&&i<count[0]+count[1]) nums[i]=1;
            else nums[i]=2;
        }
    }
};