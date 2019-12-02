/***********************************************************************************************************************
 * Created by caffe on 2019/11/29.
 * 1002. Find Common Characters
 * Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]
Note:

    1 <= A.length <= 100
    1 <= A[i].length <= 100
    A[i][j] is a lowercase letter
 **********************************************************************************************************************/
/**
 * solution 1 : analysis method
 * time complexity : O(n*m)
 * space complexity : O(26)
 */
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> ans;
        vector<int> min_occur(26,INT_MAX);
        for(int i=0;i<A.size();++i){
            string str=A[i];
            vector<int> occur(26,0);
            for(int j=0;j<str.size();++j){
                int index=str[j]-'a';
                occur[index]++;
            }
            for(int j=0;j<26;++j) min_occur[j]=min(min_occur[j],occur[j]);
        }
        for(int i=0;i<26;++i)
            if(min_occur[i]>0) {
                for(int j=0;j<min_occur[i];++j){
                    string tmp(1,'a'+i);
                    ans.push_back(tmp);
                }
            }
        return ans;
    }
};