/***********************************************************************************************************************
 * Created by caffe on 2019/11/24.
 * 870. Advantage Shuffle
 * Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].

Return any permutation of A that maximizes its advantage with respect to B.



Example 1:

Input: A = [2,7,11,15], B = [1,10,4,11]
Output: [2,11,7,15]

Example 2:

Input: A = [12,24,8,32], B = [13,25,32,11]
Output: [24,32,8,12]



Note:

    1 <= A.length = B.length <= 10000
    0 <= A[i] <= 10^9
    0 <= B[i] <= 10^9


 **********************************************************************************************************************/
/**
 * solution 1 ： 分析法
 * 这道题的题意是田忌赛马，希望使得总体而言A数组中的元素值大于B数组。方法是，对于数组B中的每个元素，在A中寻找恰好大于该元素的元素
 * 如果存在，就将该元素push到结果数组里面，如果不存在，就取A里面最小的那个即可。
 * 时间复杂度：O（nlog2n）
 * 空间复杂度：O（n）
 */
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        sort(A.begin(),A.end());
        for(int i=0;i<B.size();++i){
            int left=0,right=A.size();
            while(left<=right){
                int mid=left+(right-left)/2;
                if(mid<A.size()&&A[mid]>B[i]) right=mid-1;
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