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
    static string tictactoe(vector<vector<int>>& moves) {
        vector<vector<string>> board(3,vector<string>(3,""));
        for(int i=0;i<moves.size();++i){
            if(i+1>9) return "Draw";
            int x=moves[i][0],y=moves[i][1];
            if(i%2==0){//A->X
                board[x][y]="X";
                if(check(board,"X")!="pending") return check(board,"X");
            }else{
                board[x][y]="O";
                if(check(board,"O")!="pending") return check(board,"O");
            }
        }
        return "pending";
    }
    static string check(const vector<vector<string>> &board,string tag){
        int spacenum=0;//pending
        int xnum=0;
        int onum=0;
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                if(board[i][j]=="X") xnum++;
                else if(board[i][j]=="O") onum++;
            }
        }
        spacenum=9-xnum-onum;
        //A->X
        bool win=false;
        for(int i=0;i<3;++i){
            if(board[i][0]==tag&&board[i][1]==tag&&board[i][2]==tag) win=true;
        }
        for(int i=0;i<3;++i){
            if(board[0][i]==tag&&board[1][i]==tag&&board[2][i]==tag) win=true;
        }
        if(board[0][0]==tag&&board[1][1]==tag&&board[2][2]==tag) win=true;
        if(board[0][2]==tag&&board[1][1]==tag&&board[0][2]==tag) win=true;
        if(win){
            if(tag=="X") return "A";
            else if(tag=="O") return "B";
        }
        if(spacenum!=0) return"pending";
        return "Draw";
    }
};
int main() {
//    vector<int> num1={2,1,2};
//    string str("lyb");
    vector<vector<int>> moves={{0,0},{1,1},{2,0},{1,0},{1,2},{2,1},{0,1},{0,2},{2,2}};
    vector<string> str={"/a","/a/b","/c/d","/c/d/e","/c/f"};
    string str2="zjxss";

    Solution::tictactoe(moves);
    return 0;
}