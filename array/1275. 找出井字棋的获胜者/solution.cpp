/***********************************************************************************************************************
 * Created by caffe on 2019/12/10.
 * 1275. 找出井字棋的获胜者
 * A 和 B 在一个 3 x 3 的网格上玩井字棋。
    井字棋游戏的规则如下：

        玩家轮流将棋子放在空方格 (" ") 上。
        第一个玩家 A 总是用 "X" 作为棋子，而第二个玩家 B 总是用 "O" 作为棋子。
        "X" 和 "O" 只能放在空方格中，而不能放在已经被占用的方格上。
        只要有 3 个相同的（非空）棋子排成一条直线（行、列、对角线）时，游戏结束。
        如果所有方块都放满棋子（不为空），游戏也会结束。
        游戏结束后，棋子无法再进行任何移动。

    给你一个数组 moves，其中每个元素是大小为 2 的另一个数组（元素分别对应网格的行和列），它按照 A 和 B 的行动顺序（先 A 后 B）记录了两人各自的棋子位置。

    如果游戏存在获胜者（A 或 B），就返回该游戏的获胜者；如果游戏以平局结束，则返回 "Draw"；如果仍会有行动（游戏未结束），则返回 "Pending"。

    你可以假设 moves 都 有效（遵循井字棋规则），网格最初是空的，A 将先行动。
 **********************************************************************************************************************/
/**
 * solution 1 : 分析法
 * 暴力解法，考虑周全就行
 * 时间复杂度：O（n）
 * 空间复杂度：O（1）
 */
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<string>> board(3,vector<string>(3,""));
        for(int i=0;i<moves.size();++i){
            if(i+1>9) return "Draw";
            int x=moves[i][0],y=moves[i][1];
            if(i%2==0){//A->X
                board[x][y]="X";
                if(check(board,"X")!="Pending") return check(board,"X");
            }else{
                board[x][y]="O";
                if(check(board,"O")!="Pending") return check(board,"O");
            }
        }
        return "Pending";
    }
    string check(const vector<vector<string>> &board,string tag){
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
        if(board[0][2]==tag&&board[1][1]==tag&&board[2][0]==tag) win=true;
        if(win){
            if(tag=="X") return "A";
            else if(tag=="O") return "B";
        }
        if(spacenum!=0) return"Pending";
        return "Draw";
    }
};