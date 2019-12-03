/***********************************************************************************************************************
 * Created by caffe on 2019/12/3.
 * 1089. Duplicate Zeros
 * Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

    Note that elements beyond the length of the original array are not written.

    Do the above modifications to the input array in place, do not return anything from your function.

    Example 1:

    Input: [1,0,2,3,0,4,5,0]
    Output: null
    Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

    Example 2:

    Input: [1,2,3]
    Output: null
    Explanation: After calling your function, the input array is modified to: [1,2,3]

    Note:

        1 <= arr.length <= 10000
        0 <= arr[i] <= 9

 **********************************************************************************************************************/
/**
 * solution 1 : analysis
 * time complexity : O(n)
 * space complexity : O(n)
 */
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> tmp(arr);
        int index=0;
        for(int num:tmp){
            if(num==0&&index<arr.size()){
                arr[index++]=0;
                if(index<arr.size()) arr[index++]=0;
            }else if(num!=0&&index<arr.size()){
                arr[index++]=num;
            }
        }
        return;
    }
};