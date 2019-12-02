
/***********************************************************************************************************************
 * Created by caffe on 2019/12/2.
 * 1007. Minimum Domino Rotations For Equal Row
 * In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the i-th domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

    We may rotate the i-th domino, so that A[i] and B[i] swap values.

    Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.

    If it cannot be done, return -1.
 **********************************************************************************************************************/
/**
 * solution 1 : analysis method
 * time complexity : O(6n)
 * space complexity : O(1)
 */
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int ans=INT_MAX,N=A.size();
        for(int i=1;i<=6;++i){
            int cnt1=0,cnt2=0;
            for(int j=0;j<N;++j){
                if(A[j]==i) cnt1++;
                if(A[j]!=i&&B[j]==i) cnt2++;
            }
            if(cnt1+cnt2==A.size()) ans=min(cnt2,ans);
            cnt1=0,cnt2=0;
            for(int j=0;j<N;++j){
                if(B[j]==i) cnt1++;
                if(B[j]!=i&&A[j]==i) cnt2++;
            }
            if(cnt1+cnt2==A.size()) ans=min(cnt2,ans);
        }
        return ans==INT_MAX ? -1:ans;
    }
};