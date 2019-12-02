/***********************************************************************************************************************
 * Created by caffe on 2019/11/29.
 * 999. Available Captures for Rook
 * On an 8 x 8 chessboard, there is one white rook.  There also may be empty squares, white bishops, and black pawns.  These are given as characters 'R', '.', 'B', and 'p' respectively. Uppercase characters represent white pieces, and lowercase characters represent black pieces.

    The rook moves as in the rules of Chess: it chooses one of four cardinal directions (north, east, west, and south), then moves in that direction until it chooses to stop, reaches the edge of the board, or captures an opposite colored pawn by moving to the same square it occupies.  Also, rooks cannot move into the same square as other friendly bishops.

    Return the number of pawns the rook can capture in one move.
 **********************************************************************************************************************/
/**
 * solution 1 : analysis method
 * time complexity : O(n)
 * space complexity : O(1)
 */
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int Br=0,Bc=0;
        int ans=0;
        int rows=board.size(),cols=board[0].size();
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(board[i][j]=='R'){Br=i;Bc=j;}
            }
        }
        int r=Br-1,c=Bc;
        while(r>=0&&board[r][c]=='.') --r;
        if(r>=0&&board[r][c]=='p') ++ans;
        r=Br+1,c=Bc;
        while(r<rows&&board[r][c]=='.') ++r;
        if(r<rows&&board[r][c]=='p') ++ans;
        r=Br,c=Bc-1;
        while(c>=0&&board[r][c]=='.') --c;
        if(c>=0&&board[r][c]=='p') ++ans;
        r=Br,c=Bc+1;
        while(c<cols&&board[r][c]=='.') ++c;
        if(c<cols&&board[r][c]=='p') ++ans;
        return ans;
    }
};