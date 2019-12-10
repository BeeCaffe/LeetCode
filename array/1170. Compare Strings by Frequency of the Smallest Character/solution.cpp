/***********************************************************************************************************************
 * Created by caffe on 2019/12/4.
 * 1170. Compare Strings by Frequency of the Smallest Character
 * Let's define a function f(s) over a non-empty string s, which calculates the frequency of the smallest character in s. For example, if s = "dcce" then f(s) = 2 because the smallest character is "c" and its frequency is 2.

Now, given string arrays queries and words, return an integer array answer, where each answer[i] is the number of words such that f(queries[i]) < f(W), where W is a word in words.



Example 1:

Input: queries = ["cbd"], words = ["zaaaz"]
Output: [1]
Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").

Example 2:

Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
Output: [1,2]
Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").

Constraints:

    1 <= queries.length <= 2000
    1 <= words.length <= 2000
    1 <= queries[i].length, words[i].length <= 10
    queries[i][j], words[i][j] are English lowercase letters.
 **********************************************************************************************************************/
/**
 * solution 1 : analysis
 * time complexity : O(nm)
 * space complexity : O(nm)
 */
 //Time Limit Exceed
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ans(queries.size(),0);
        vector<int> fws(words.size(),0);
        for(int i=0;i<words.size();++i){
            fws[i]=f(words[i]);
        }
        for(int i=0;i<queries.size();++i){
            int cnt=0;
            for(int fw:fws){
                if(f(queries[i])<fw) ++cnt;
            }
            ans[i]=cnt;
        }
        return ans;
    }
    int f(const string &str){
        vector<int> count(26,0);
        for(int i=0;i<str.size();++i){
            int index=str[i]-'a';
            count[index]++;
        }
        int freq=0;
        for(int i=0;i<count.size();++i){
            if(count[i]>0){
                freq=count[i];
                break;
            }
        }
        return freq;
    }
};
/**
 * solution 2 : binary search
 * space complexity : O(nm)
 * time complexity : O(nlog2n)
 */
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ans(queries.size(),0);
        vector<int> fws(words.size(),0);
        for(int i=0;i<words.size();++i){
            fws[i]=f(words[i]);
        }
        sort(fws.begin(),fws.end());
        for(int i=0;i<queries.size();++i){
            int left=0,right=fws.size()-1;
            int target=f(queries[i]);
            while(left<=right){
                int mid=left+(right-left)/2;
                if(fws[mid]>target) right=mid-1;//bigger
                else left=mid+1;//smaller
            }
            ans[i]=fws.size()-left;
        }
        return ans;
    }
    int f(const string &str){
        vector<int> count(26,0);
        for(int i=0;i<str.size();++i){
            int index=str[i]-'a';
            count[index]++;
        }
        int freq=0;
        for(int i=0;i<count.size();++i){
            if(count[i]>0){
                freq=count[i];
                break;
            }
        }
        return freq;
    }
};