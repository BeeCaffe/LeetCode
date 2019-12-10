/***********************************************************************************************************************
 * Created by caffe on 2019/12/9.
 * 1200. 最小绝对差
 * 给你个整数数组 arr，其中每个元素都 不相同。

请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。



示例 1：

输入：arr = [4,2,1,3]
输出：[[1,2],[2,3],[3,4]]

示例 2：

输入：arr = [1,3,6,10,15]
输出：[[1,3]]

示例 3：

输入：arr = [3,8,-10,23,19,-4,-14,27]
输出：[[-14,-10],[19,23],[23,27]]



提示：

    2 <= arr.length <= 10^5
    -10^6 <= arr[i] <= 10^6
 **********************************************************************************************************************/
/**
 * solution 1 : map
 * 将绝对值相同的数对存储在一个map里面，找到绝对值最小的map即可。
 * 时间复杂度： O（n（n-1）/2）
 * 空间复杂度： O（n）
 */
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,vector<vector<int>>> hashmap;
        for(int i=0;i<arr.size();++i){
            for(int j=i+1;j<arr.size();++j){
                hashmap[abs(arr[j]-arr[i])].push_back(vector<int>({arr[i],arr[j]}));
            }
        }
        int minabs=INT_MAX;

        for(auto iter=hashmap.begin();iter!=hashmap.end();++iter){
            if(iter->first<=minabs) minabs=iter->first;
        }
        return hashmap[minabs];
    }
};
/**
 * solution 2 : 遍历法
 * 遍历数组一次，找到其中最小的绝对值
 * 遍历数组第二次，找到所有为绝对值最小的数对
 * 时间复杂度： O（nlog2n）
 * 空间复杂度： O（n）
 */
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int minabs=INT_MAX;
        for(int i=1;i<arr.size();++i){
            minabs=min(minabs,abs(arr[i]-arr[i-1]));
        }
        vector<vector<int>> ans;
        for(int i=1;i<arr.size();++i){
            if(arr[i]-arr[i-1]==minabs) ans.push_back({arr[i-1],arr[i]});
        }
        return ans;
    }
};