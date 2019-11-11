/***********************************************************************************************************************
 * Created by caffe on 2019/11/6.
 *
 **********************************************************************************************************************/
/**
 * solution1 : space O(n2)
 *      这道题主要是弄清楚题意，具体操作还是很简单的：
 *      活->死：cell<2
 *      活->活：2<=cell<3
 *      活->死：cell>3
 *      死->活：cell=3
 *      弄清楚死活状态的转换要求之后必须注意到，每一刻的死活状态变化都是根据上一刻的状态确定的。因此，必须同时改变全部细胞的死活状态，方法便
 *      是用一个副本记录下一刻的死活状态。
 * 时间复杂度：O（n2）
 * 空间复杂度：O（n2）
 */
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size()==0) return;
        vector<vector<int>> res(board);
        int rows=board.size(),cols=board[0].size();
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                int count=neighborNums(board,i,j);
                if(count<2) res[i][j]=0;
                else if(count==3){
                    res[i][j]=1;
                }else if(count>3){
                    res[i][j]=0;
                }
            }
        }
        board=res;
    }

    int neighborNums(vector<vector<int>> &board,int row,int col){
        int count=0;
        int rows=board.size(),cols=board[0].size();
        if(row-1>=0 && col-1>=0 && board[row-1][col-1]==1) count++;
        if(col-1>=0 && board[row][col-1]==1) count++;
        if(row+1<rows&&col-1>=0 && board[row+1][col-1]==1) count++;
        if(row-1>=0&&board[row-1][col]==1) count++;
        if(row+1<rows&&board[row+1][col]==1) count++;
        if(row-1>=0 && col+1<cols &&board[row-1][col+1]==1) count++;
        if(col+1<cols && board[row][col+1]) count++;
        if(row+1<rows && col+1<cols && board[row+1][col+1]==1) count++;
        return count;
    };

    class Solution {
    public:
        void gameOfLife(vector<vector<int>>& board) {
            if(board.size()==0) return;
            vector<vector<int>> res(board);
            int rows=board.size(),cols=board[0].size();
            for(int i=0;i<rows;++i){
                for(int j=0;j<cols;++j){
                    int count=neighborNums(board,i,j);
                    if(count<2) res[i][j]=0;
                    else if(count==3){
                        res[i][j]=1;
                    }else if(count>3){
                        res[i][j]=0;
                    }
                }
            }
            board=res;
        }

        int neighborNums(vector<vector<int>> &board,int row,int col){
            int count=0;
            int rows=board.size(),cols=board[0].size();
            vector<int> neighbors={0,1,-1};
            for(int i=0;i<3;++i){
                for(int j=0;j<3;++j){
                    if(!(neighbors[i]==0&&neighbors[j]==0)){
                        int r=row+neighbors[i];
                        int c=col+neighbors[j];
                        if((r<rows&&r>=0)&&(c<cols&&c>=0)&&board[r][c]==1) count++;
                    }
                }
            }
            return count;
        }
    };

    /**
     * solution2 : O(1) space solution
     *      另外一种方式是不建立辅助二维数组的方式，我们将原来是活的现在变成死的记录为-1，将原来是死的现在是活的记录成2。在判断邻居存活结点时将-1当作1看待，将2当作0看待即可。而在得到最后结果的时候，将-1看作0，2
     *      看作1即可。
     * 时间复杂度：O（mxn)
     * 空间复杂度：O（1）
     */
    class Solution {
    public:
        void gameOfLife(vector<vector<int>>& board) {
            if(board.size()==0) return;
            vector<int> neighbors={0,1,-1};
            int rows=board.size(),cols=board[0].size();
            for(int row=0;row<rows;++row){
                for(int col=0;col<cols;++col){
                    int count=0;
                    for(int i=0;i<3;++i){
                        for(int j=0;j<3;++j){
                            if(!(neighbors[i]==0&&neighbors[j]==0)){
                                int r=row+neighbors[i];
                                int c=col+neighbors[j];
                                if((r<rows&&r>=0)&&(c<cols&&c>=0)&&abs(board[r][c])==1) count++;
                            }
                        }
                    }
                    if(board[row][col]==1&&(count<2||count>3)) board[row][col]=-1;
                    if(count==3&&board[row][col]==0) board[row][col]=2;
                }
            }
            for(int i=0;i<rows;++i){
                for(int j=0;j<cols;++j){
                    if(board[i][j]>0) board[i][j]=1;
                    else board[i][j]=0;
                }
            }
        }
    };