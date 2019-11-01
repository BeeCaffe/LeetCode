/***********************************************************************************************************************
 * Created by caffe on 2019/10/31.
 * 题干：
        给定两个单词（beginWord和endWord），和一个单词字典，找到所有从beginWord到endWord的最短转换，使得：
        1.每次只能改变一个字母；
        2.每个转换单词都必须在单词字典中，注意到，beginWord不是一个转换单词。
        注意到：
            1）如果不存在满足条件的转换序列，则返回空列表。
            2）所有的单词都有相同的长度
            3）所有的单词都只包含小写的阿拉伯字符
            4）假设列表中没有重复单词
            5）假设beginWord和endWord非空，并且不相同
 *  解法一：BFS（广度优先搜索）
        采用广度优先搜索遍历，即将beginword看作树的根节点，每次一个节点能够通过变换一个字符而成的且存在于wordList中的单词看作孩子节点。
        这样的化，求解最短转换，就变成了从beginword节点到endword节点的一个最短路径的问题，那么求解这个最短路径问题所用到的方法就是广度优先
        遍历。广度优先遍历类似于树的层次遍历，都是通过一个队列来实现的，本题的具体算法实现如下。
 *  时间复杂度：由于采用了两层循环来查找当前节点的邻节点时间复杂度为O（n2），而本身广度优先遍历时间复杂度为O（n），因此时间复杂度为O（n3）
 *  空间复杂度：辅助队列，O（n）
 *  注意：如果采用Vector和find的话，由于时间复杂度过高，这个解答并不能ac。但是思路是对的
 **********************************************************************************************************************/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        queue<pair<string,int>> que;
        que.push({beginWord,1});
        while(!que.empty()){
            string cur=que.front().first;
            int level=que.front().second;
            que.pop();
            if(cur==endWord) return level;
            vector<string> neighbors=findNeighbors(cur,wordSet);
            for(string iter:neighbors){
                que.push({iter,level+1});
            }
        }
        return 0;
    }
    vector<string> findNeighbors(string cur,unordered_set<string> &wordSet){
        vector<string> ret;
        for(int i=0;i<cur.size();++i){
            char c=cur[i];
            for(int j=0;j<26;++j){
                if(c=='a'+j) continue;
                cur[i]='a'+j;
                if(wordSet.count(cur)){
                    ret.push_back(cur);
                    wordSet.erase(cur);
                }
                cur[i]=c;
            }
        }
        return ret;
    }
};