/***********************************************************************************************************************
 * Created by caffe on 2019/11/24.
 * 830. Positions of Large Groups
 * In a string S of lowercase letters, these letters form consecutive groups of the same character.

    For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".

    Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.

    The final answer should be in lexicographic order.
    Example 1:
    Input: "abbxxxxzzy"
    Output: [[3,6]]
    Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.

    Example 2:

    Input: "abc"
    Output: []
    Explanation: We have "a","b" and "c" but no large group.
    Example 3:
    Input: "abcdddeeeeaabbbcd"
    Output: [[3,5],[6,9],[12,14]]
    Note:  1 <= S.length <= 1000
 **********************************************************************************************************************/
/**
 * solution 1 : two pointer
 * time complexity : O(n2)
 * space complexity : O(1)
 */

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        int pbeg=0,pend;
        while(pbeg<S.size()){
            pend=pbeg+1;
            while(pend<S.size()&&S[pend]==S[pbeg]) ++pend;
            if(pend-pbeg>=3) res.push_back({pbeg,pend-1});
            pbeg=pend;
        }
        return res;
    }
};