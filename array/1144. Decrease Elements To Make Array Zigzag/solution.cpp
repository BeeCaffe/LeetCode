/***********************************************************************************************************************
 * Created by caffe on 2019/12/4.
 * 1144. Decrease Elements To Make Array Zigzag
 * Given an array nums of integers, a move consists of choosing any element and decreasing it by 1.

    An array A is a zigzag array if either:

        Every even-indexed element is greater than adjacent elements, ie. A[0] > A[1] < A[2] > A[3] < A[4] > ...
        OR, every odd-indexed element is greater than adjacent elements, ie. A[0] < A[1] > A[2] < A[3] > A[4] < ...

    Return the minimum number of moves to transform the given array nums into a zigzag array.

    Example 1:

    Input: nums = [1,2,3]
    Output: 2
    Explanation: We can decrease 2 to 0 or 3 to 1.

    Example 2:

    Input: nums = [9,6,1,6,2]
    Output: 4

    Constraints:

        1 <= nums.length <= 1000
        1 <= nums[i] <= 1000
 **********************************************************************************************************************/
/**
 * solution 1 : analysis method
 * there are two situations in the Zigzag array, that is "even>odd<even" and "odd>even<odd",so we take
 * two travel to solve this problem.meanwhile,because we can only decrease the element by 1 ,the best
 * idea is to decrease the middle element in each unit.In the end, return the minimum answer for each
 * situations.
 * time complexity : O(n)
 * space complexity : O(n)
 */
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n=nums.size();
        int ans1=0;
        vector<int> nums1(nums);
        for(int i=0;i<n;++i){
            if(i==0){//even
                while(i+1<n&&nums[i]>=nums[i+1]){--nums[i];++ans1;}
            }else if(i==n-1 && i%2==0){
                while(i-1>=0 && nums[i]>=nums[i-1]){--nums[i];++ans1;}
            }else if(i%2==0){
                while(i-1>=0 && nums[i]>=nums[i-1]){--nums[i];++ans1;}
                while(i+1<n && nums[i]>=nums[i+1]){--nums[i];++ans1;}
            }
        }
        int ans2=0;
        for(int i=1;i<n;++i){
            if(i==n-1 && i%2!=0){
                while(i-1>=0 && nums1[i]>=nums1[i-1]){--nums1[i];++ans2;}
            }else if(i%2!=0){
                while(i-1>=0 && nums1[i]>=nums1[i-1]){--nums1[i];++ans2;}
                while(i+1<n && nums1[i]>=nums1[i+1]){--nums1[i];++ans2;}
            }
        }
        return min(ans1,ans2);
    }
};