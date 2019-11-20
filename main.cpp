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
    static bool cmp(const pair<char,int> &a,const pair<char,int> &b){
        return a.second>b.second;
    }
    static string reorganizeString(string S) {
        map<char,int> table_map;
        for(int i=0;i<S.size();++i){
            if(table_map.find(S[i])==table_map.end()) table_map.insert(pair<char,int>(S[i],1));
            else table_map.find(S[i])->second++;
        }
        vector<pair<char,int>> table(table_map.begin(),table_map.end());
        sort(table.begin(),table.end(),cmp);
        string ans;
        while(table.size()>0){
            for(int i=0;i<2;++i){
                if(table[i].second!=0){
                    ans+=table[i].first;
                    table[i].second--;
                }
                if(table[i].second==0) table.erase(table.begin()+i);
            }
            int size=table.size();
            if(table.size()==1&&table.begin()->second>1) return "";
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> board={{4,2}};
    string str("aab");
    Solution::reorganizeString(str);
    return 0;
}