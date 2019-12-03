/***********************************************************************************************************************
 * Created by caffe on 2019/12/3.
 * 1122. Relative Sort Array
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

    Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.

    Example 1:

    Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
    Output: [2,2,2,1,4,3,3,9,6,7,19]

    Constraints:

        arr1.length, arr2.length <= 1000
        0 <= arr1[i], arr2[i] <= 1000
        Each arr2[i] is distinct.
        Each arr2[i] is in arr1.
 **********************************************************************************************************************/
/**
 * solution 1 : map
 * time complexity : O(nlog2n)
 * space complexity : O(n)
 */
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        unordered_map<int,int> hashmap;//value,num
        for(int i=0;i<arr1.size();++i){
            if(hashmap.find(arr1[i])!=hashmap.end()) hashmap[arr1[i]]++;
            else hashmap.insert(pair<int,int>(arr1[i],1));
        }
        for(int num:arr2){
            for(int i=0;i<hashmap[num];++i){
                ans.push_back(num);
            }
            hashmap.erase(num);
        }
        vector<pair<int,int>> left(hashmap.begin(),hashmap.end());
        sort(left.begin(),left.end());
        for(auto pr:left){
            int value=pr.first,num=pr.second;
            for(int i=0;i<num;++i) ans.push_back(value);
        }
        return ans;
    }
};