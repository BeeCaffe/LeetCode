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
    static int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans=0;
        map<pair<int,int>,int> hashmap;//domain,numbers
        for(auto domin:dominoes){
            pair<int,int> pr(domin[0],domin[1]);
            hashmap[pr]++;
        }
        for(auto elem:hashmap){
            pair<int,int> domin=elem.first;
            int numbers=elem.second;
            ans+=(numbers*(numbers-1))/2;
            elem.second=0;
            if(domin.first!=domin.second){
                pair<int,int> reverse(domin.second,domin.first);
                if(hashmap.find(reverse)!=hashmap.end()){
                    ans+=hashmap[reverse]*numbers;
                    hashmap[reverse]=0;
                }
            }
        }
        return ans;
    }
};


int main() {
//    vector<int> num1={8,4,5,0,0,0,0,7};
//    vector<int> num2={0,1,0,1,0,1,0,1};
    vector<vector<int>> num={{2,1},{1,2},{1,2},{1,2},{2,1},{1,1},{1,2},{2,2}};
    Solution::numEquivDominoPairs(num);
    return 0;
}