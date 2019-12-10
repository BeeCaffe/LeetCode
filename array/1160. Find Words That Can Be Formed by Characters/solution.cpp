/***********************************************************************************************************************
 * Created by caffe on 2019/12/4.
 * 1160. Find Words That Can Be Formed by Characters
 * You are given an array of strings words and a string chars.

    A string is good if it can be formed by characters from chars (each character can only be used once).

    Return the sum of lengths of all good strings in words.

    Example 1:

    Input: words = ["cat","bt","hat","tree"], chars = "atach"
    Output: 6
    Explanation:
    The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

    Example 2:

    Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
    Output: 10
    Explanation:
    The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.

    Note:

        1 <= words.length <= 1000
        1 <= words[i].length, chars.length <= 100
        All strings contain lowercase English letters only.

 **********************************************************************************************************************/
/**
 * solution 1 : map method
 * stores char and numbers pair into a hash map,then travel the words array,check each words, if this
 * word is consists by the char exist in the hash map return true, otherwise return false.if check()
 * function return true, answer plus this word's length.
 * time complexity : O(nm)
 * space complexity : O(n)
 */
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> hashmap;
        int ans=0;
        for(int i=0;i<chars.size();++i){
            hashmap[chars[i]]++;
        }
        for(string word:words){
            if(check(hashmap,word)) ans+=word.size();
        }
        return ans;
    }
    bool check(const unordered_map<char,int> &mp,const string &word){
        unordered_map<char,int> hashmap(mp);
        for(int i=0;i<word.size();++i){
            if(hashmap.find(word[i])==hashmap.end()) return false;
            else if(hashmap[word[i]]>0) --hashmap[word[i]];
            else if(hashmap[word[i]]==0) return false;
        }
        return true;
    }
};