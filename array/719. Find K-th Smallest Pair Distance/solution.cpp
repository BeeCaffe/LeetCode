/***********************************************************************************************************************
 * Created by caffe on 2019/11/14.
 * 719. Find K-th Smallest Pair Distance
 * Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

    Example 1:

    Input:
    nums = [1,3,1]
    k = 1
    Output: 0
    Explanation:
    Here are all the pairs:
    (1,3) -> 2
    (1,1) -> 0
    (3,1) -> 2
    Then the 1st smallest distance pair is (1,1), and its distance is 0.

    Note:

        2 <= len(nums) <= 10000.
        0 <= nums[i] < 1000000.
        1 <= k <= len(nums) * (len(nums) - 1) / 2.
 ************************************************************************************************************************/
/**
 * error solution : two pointer[Time limit Exceed]
 * time complexity : O(n2)
 * space complexity : O(n2)
 */
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<vector<bool>> visited(nums.size(),vector<bool>(nums.size(),0));
        multiset<int> dists;
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                if(!visited[i][j]){
                    int dist=abs(nums[i]-nums[j]);
                    visited[i][j]=true;
                    dists.insert(dist);
                }
            }
        }
        auto iter=dists.begin();
        for(int i=1;i<k;++i){
            iter++;
        }
        return *iter;
    }
};