/***********************************************************************************************************************
 * Created by caffe on 2019/12/2.
 * 1014. Best Sightseeing Pair
 * Given an array A of positive integers, A[i] represents the value of the i-th sightseeing spot, and two sightseeing spots i and j have distance j - i between them.

    The score of a pair (i < j) of sightseeing spots is (A[i] + A[j] + i - j) : the sum of the values of the sightseeing spots, minus the distance between them.

    Return the maximum score of a pair of sightseeing spots.

    Example 1:

    Input: [8,1,5,2,6]
    Output: 11
    Explanation: i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11

    Note:

        2 <= A.length <= 50000
        1 <= A[i] <= 1000

 **********************************************************************************************************************/
/**
 * error solution 1 : two pointer
 * time complexity : O(n2)
 * space complexity : O(1)
 */
 //Time Limit Exceed
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ans=0;
        for(int i=0;i<A.size();++i){
            for(int j=i+1;j<A.size();++j){
                ans=max(ans,A[i]+A[j]+i-j);
            }
        }
        return ans;
    }
};
/**
 * solution 2 : sliding window
 * time complexity : O(n)
 * space complexity : O(1)
 */
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ans = A[0]+A[1]-1;
        int cur = max(A[0]-2, A[1]-1);
        for(int i=2; i<A.size(); i++) {
            ans = max(ans, cur+A[i]);
            cur = max(cur-1, A[i]-1);
        }
        return ans;
    }
};
