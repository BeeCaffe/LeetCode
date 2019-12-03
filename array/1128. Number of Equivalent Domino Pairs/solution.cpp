/***********************************************************************************************************************
 * Created by caffe on 2019/12/3.
 * 1128. Number of Equivalent Domino Pairs
 * Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that is, one domino can be rotated to be equal to another domino.

    Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

    Example 1:

    Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
    Output: 1

    Constraints:

        1 <= dominoes.length <= 40000
        1 <= dominoes[i][j] <= 9
 **********************************************************************************************************************/
/**
 * solution 1 : two pointer
 * time complexity : O(n(n-1)/2)
 * space complexity : O(1)
 */
 //Time Limit Exceed
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans=0;
        for(int i=0;i<dominoes.size();++i){
            for(int j=i+1;j<dominoes.size();++j){
                if(check(dominoes[i],dominoes[j])) ++ans;
            }
        }
        return ans;
    }
    bool check(vector<int> &arr1,vector<int> &arr2){
        int a=arr1[0],b=arr1[1];
        int c=arr2[0],d=arr2[1];
        if((a==c&&b==d) || (a==d&&b==c)) return true;
        return false;
    }
};
/**
 * solution 1 : enhanced map
 * time complexity : < O(n)
 * space complexity : < O(n)
 */

 class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans=0;
        map<pair<int,int>,int> hashmap;//domain,numbers
        for(auto domin:dominoes){
            pair<int,int> pr(domin[0],domin[1]);
            hashmap[pr]++;
        }
        for(auto elem:hashmap){
            pair<int,int> domin=elem.first;
            int numbers=elem.second;
            if(numbers>0){
                ans+=(numbers*(numbers-1))/2;
                if(domin.first!=domin.second){
                    pair<int,int> reverse(domin.second,domin.first);
                    if(hashmap[reverse]>0) ans+=(hashmap[reverse]*(hashmap[reverse]-1))/2;
                    if(hashmap[reverse]>0) ans+=hashmap[reverse]*numbers;
                    hashmap[reverse]=0;
                }
                elem.second=0;
            }
        }
        return ans;
    }
};