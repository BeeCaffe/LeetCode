/***********************************************************************************************************************
 * Created by caffe on 2019/12/10.
 * 1222. 可以攻击国王的皇后
 * 在一个 8x8 的棋盘上，放置着若干「黑皇后」和一个「白国王」。

    「黑皇后」在棋盘上的位置分布用整数坐标数组 queens 表示，「白国王」的坐标用数组 king 表示。

    「黑皇后」的行棋规定是：横、直、斜都可以走，步数不受限制，但是，不能越子行棋。

    请你返回可以直接攻击到「白国王」的所有「黑皇后」的坐标（任意顺序）。
 **********************************************************************************************************************/
/**
 * solution 1 : 分析法
 * 直接以国王为中心，朝8个方向搜索，返回碰到的第一个皇后并跳出。如果遇到边界则跳出。
 * 时间复杂度： O（n2）
 * 空间复杂度： O（1）
 */
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<bool>> board(8,vector<bool>(8,0));
        for(auto loc:queens){
            int x=loc[0],y=loc[1];
            board[x][y]=true;
        }
        vector<vector<int>> ans;
        search(board,king,1,1,ans);
        search(board,king,1,0,ans);
        search(board,king,1,-1,ans);
        search(board,king,0,-1,ans);
        search(board,king,-1,-1,ans);
        search(board,king,-1,0,ans);
        search(board,king,-1,1,ans);
        search(board,king,0,1,ans);
        return ans;
    }

    void search(vector<vector<bool>> &board,vector<int> &king,int dirx,int diry,vector<vector<int>> &ans){
        int i=king[0],j=king[1];
        while(i>=0&&i<8&&j>=0&&j<8){
            if(board[i][j]==true){
                ans.push_back({i,j});
                break;
            }
            i+=dirx;
            j+=diry;
        }
    }
};