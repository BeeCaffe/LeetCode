/***********************************************************************************************************************
 * Created by caffe on 2019/10/31.
 * 题干：
        Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
        A region is captured by flipping all 'O's into 'X's in that surrounded region.
 * 解法一：BFS（广度优先遍历）
        先遍历矩阵的四条边，找到为O的，那么与它相连的所有O都不会被包围，将这一类的O先置为‘#’，然后将矩阵中剩余的O变成X即可，注意这里的相连
        是指在互相的四邻域内。
 * 时间复杂度：O(n2)
 * 空间复杂度：O(n)
 **********************************************************************************************************************/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0) return;
        int rows=board.size(),cols=board[0].size();
        for(int i=0;i<rows;++i){//rows
            if(board[i][0]=='O') bfs(board,i,0);
            if(board[i][cols-1]=='O') bfs(board,i,cols-1);
        }
        for(int i=0;i<cols;++i){
            if(board[0][i]=='O') bfs(board,0,i);
            if(board[rows-1][i]=='O') bfs(board,rows-1,i);
        }
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='#') board[i][j]='O';
            }
        }
        return;
    }

    void bfs(vector<vector<char>> &board,int rows,int cols){
        board[rows][cols]='#';
        queue<pair<int,int>> que;
        que.push(pair<int,int>(rows,cols));
        while(!que.empty()){
            int row=que.front().first;
            int col=que.front().second;
            que.pop();
            if(row-1>=0 && board[row-1][col]=='O'){
                board[row-1][col]='#';
                que.push(pair<int,int>(row-1,col));
            }
            if(row+1<board.size() && board[row+1][col]=='O'){
                board[row+1][col]='#';
                que.push(pair<int,int>(row+1,col));
            }
            if(col+1<board[0].size() && board[row][col+1]=='O'){
                board[row][col+1]='#';
                que.push(pair<int,int>(row,col+1));
            }
            if(col-1>=0 && board[row][col-1]=='O'){
                board[row][col-1]='#';
                que.push(pair<int,int>(row,col-1));
            }
        }
    }
};