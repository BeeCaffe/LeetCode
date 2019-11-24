/***********************************************************************************************************************
 * Created by caffe on 2019/11/24.
 * 835. Image Overlap
 * Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

    We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

    (Note also that a translation does not include any kind of rotation.)

    What is the largest possible overlap?

    Example 1:

    Input: A = [[1,1,0],
                [0,1,0],
                [0,1,0]]
           B = [[0,0,0],
                [0,1,1],
                [0,0,1]]
    Output: 3
    Explanation: We slide A to right by 1 unit and down by 1 unit.

    Notes:

        1 <= A.length = A[0].length = B.length = B[0].length <= 30
        0 <= A[i][j], B[i][j] <= 1
 **********************************************************************************************************************/
/**
 * solution 1 ： 分析法
 * 时间复杂度 ： O（n2）
 * 空间复杂度： O（n2）
 */
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        unordered_map<string,int> hash_map;
        vector<vector<int>> vec_a,vec_b;
        int ans=0;
        for(int i=0;i<A.size();++i){
            for(int j=0;j<A[0].size();++j){
                if(A[i][j]==1) vec_a.push_back({i,j});
                if(B[i][j]==1) vec_b.push_back({i,j});
            }
        }

        for(auto ptA:vec_a){
            for(auto ptB:vec_b){
                ++hash_map[to_string(ptB[0]-ptA[0])+"_"+to_string(ptB[1]-ptA[1])];
            }
        }

        for(auto node:hash_map)
            ans=max(ans,node.second);
        return ans;
    }
};