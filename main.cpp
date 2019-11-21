#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
using namespace std;
class Solution {
public:
    static int numMatchingSubseq(string S, vector<string>& words) {
        int ans=0;
        for(string word:words){
            bool tmp=isSubSeq(S,word);
            if(tmp) ans++;
        }
        return ans;
    }
    static bool isSubSeq(string &S,string &sub_seq){
        int idx=0,i;
        int count=0;
        for(i=0;i<sub_seq.size();++i){
            while(idx<S.size()&&S[idx]!=sub_seq[i]) ++idx;
            char tmp1=S[idx++];
            char tmp2=sub_seq[i];
            if(tmp1==tmp2) ++count;
        }
        if(i==sub_seq.size()) return true;
        return false;
    }
};
int main() {
    vector<string> words={"a", "bb", "acd", "ace"};
    string S="abcde";
    Solution::numMatchingSubseq(S,words);
    return 0;
}