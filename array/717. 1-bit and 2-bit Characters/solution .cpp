/***********************************************************************************************************************
 * Created by caffe on 2019/11/14.
 * 717. 1-bit and 2-bit Characters
 * We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).

    Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.

    Example 1:

    Input:
    bits = [1, 0, 0]
    Output: True
    Explanation:
    The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.

    Example 2:

    Input:
    bits = [1, 1, 1, 0]
    Output: False
    Explanation:
    The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.

    Note:
    1 <= len(bits) <= 1000.
    bits[i] is always 0 or 1.
 **********************************************************************************************************************/
/**
 * un-accept solution 1 : Brute Force
 * using two for loop,when you find any equal pair in A and B,find the length after this number.
 * time complexity : O(n3)
 * space complexity : O(1)
 */
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if(A.empty()||B.empty()) return 0;
        int ans=0;
        for(int i=0;i<A.size();++i){
            for(int j=0;j<B.size();++j){
                int len=0,pa=i,pb=j;
                if(A[i]==B[j]){
                    while(pa<A.size() && pb<B.size() && A[pa++]==B[pb++]) ++len;
                }
                ans=max(ans,len);
            }
        }
        return ans;
    }
};
/**
 * solution 1 : dynamic programming[Accept]
 */
 //time limit exceed
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if(A.empty()||B.empty()) return 0;
        int ans=0;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<B.size();++i){
            auto iter=mp.find(B[i]);
            if(iter==mp.end()){
                mp.insert(pair<int,vector<int>>(B[i],{i}));
            }else{
                iter->second.push_back(i);
            }
        }
        for(int i=0;i<A.size();++i){
            for(int j:mp[A[i]]){
                int len=0;
                while(j+len<B.size() && i+len<A.size() && A[i+len]==B[j+len]) ++len;
                ans=max(ans,len);
            }
        }
        return ans;
    }
};
/**
 * solution 2 : Brute force with initial character map
 * Intuition and Algorithm
   Since a common subarray of A and B must start at some A[i] and B[j], let dp[i][j] be the longest common prefix of A[i:]
   and B[j:]. Whenever A[i] == B[j], we know dp[i][j] = dp[i+1][j+1] + 1. Also, the answer is max(dp[i][j]) over all i, j.
   We can perform bottom-up dynamic programming to find the answer based on this recurrence. Our loop invariant is that the
   answer is already calculated correctly and stored in dp for any larger i, j.
    Time Complexity: O(M∗N)O(M*N)O(M∗N), where M,NM, NM,N are the lengths of A, B.
    Space Complexity: O(M∗N)O(M*N)O(M∗N), the space used by dp.

 */
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if(A.empty()||B.empty()) return 0;
        int ans=0;
        vector<vector<int>> dp(A.size()+1,vector<int>(B.size()+1,0));
        for(int i=A.size()-1;i>=0;--i){
            for(int j=B.size()-1;j>=0;--j){
                if(A[i]==B[j]){
                    dp[i][j]=dp[i+1][j+1]+1;
                    if(ans<dp[i][j]) ans=dp[i][j];
                }
            }
        }
        return ans;
    }
};