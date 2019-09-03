//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx=nums1.size()-1;
        int i=m-1,j=n-1;
        while(i>=0&&j>=0){
            if(nums1[i]>=nums2[j]&&idx>=0) nums1[idx--]=nums1[i--];
            else nums1[idx--]=nums2[j--];
        }
        if(i>=0){
            for(;i>=0;i--) nums1[idx--]=nums1[i];
        }
        if(j>=0){
            for(;j>=0;j--) nums1[idx--]=nums2[j];
        }
    }
};