/**
 * There are three steps to slove this problem in total.
 * 1. check each rows, we set a array to record whether the number appeared in this line.
 * 2. check each cols.
 * 3. check each boxes.
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(size_t i=0;i<9;i++){
            int line[9]={0};
            int cols[9]={0};
            for(size_t j=0;j<9;j++){
                //check rows
                if(board[i][j]!='.'){
                    int index=board[i][j]-'0';
                    if(line[index-1]==0) line[index-1]=1;
                    else return false;
                }
                //check cols
                if(board[j][i]!='.'){
                    int index=board[j][i]-'0';
                    if(cols[index-1]==0) cols[index-1]=1;
                    else return false;
                }
            }
        }
        //check 3x3 boxes
        for(size_t i=0;i<9;i+=3){
            for(size_t j=0;j<9;j+=3){
                int box[9]={0};
                for(size_t k=0;k<3;k++){
                    for(size_t l=0;l<3;l++){
                        if(board[i+k][j+l]!='.'){
                            int index=board[i+k][j+l]-'0';
                            if(box[index-1]==0) box[index-1]=1;
                            else return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};