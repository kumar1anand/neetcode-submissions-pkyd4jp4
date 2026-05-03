class Solution {
public:
    bool solve(vector<vector<char>>& board,int row,int col,string word,int ind){
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size()) return false;
        if(board[row][col]!=word[ind]) return false;
        if(ind==word.size()-1)return true;

        char temp = board[row][col];
        board[row][col]='#';//mark as visited
        bool op1= solve(board,row-1,col,word,ind+1);
        bool op2 = solve(board,row,col+1,word,ind+1);
        bool op3 = solve(board,row+1,col,word,ind+1);
        bool op4 = solve(board,row,col-1,word,ind+1);
        board[row][col]=temp;//backtrack
        return op1 || op2 || op3 || op4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(solve(board,i,j,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
