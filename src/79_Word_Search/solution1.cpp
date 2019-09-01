//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * 1.dfs (deep first search)
 *      for each location in board,implement an "dfs" to find whether this loaction exist an solutions.
 *      if "i" is less than 0 or bigger than "rows-1", it must return a false,which means there is not exist a solution
 *      so as "j".
 *      Meanwhile,we should declare a 'visied' matrix to record whether this place has been visited.
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size(),cols=board[0].size();
        int index=0;
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(dfs(board,visited,i,j,index,word)) return true;
                index=0;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board,vector<vector<bool>>& visited,int i,int j,int& count,const string& word){
        int rows=board.size(),cols=board[0].size();
        if(count>=word.size()) return true;
        if(i<0 || i>rows-1) return false;
        if(j<0 || j>cols-1) return false;
        if(visited[i][j]) return false;
        if(word[count]==board[i][j]) {
            visited[i][j]=true;
            count++;
            if(dfs(board,visited,i,j+1,count,word) || dfs(board,visited,i+1,j,count,word),
                    dfs(board,visited,i,j-1,count,word) || dfs(board,visited,i-1,j,count,word)){
                return true;
            }else{
                count--;
                visited[i][j]=0;
                return false;
            }
        }
        else{
            return false;
        }
        return true;
    }
};