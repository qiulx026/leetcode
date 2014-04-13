class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        map<char,int> temp;
        for(int i=0;i<9;i++){
            temp.clear();
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(temp.find(board[i][j])!=temp.end()) return false;
                else temp[board[i][j]]=0;
            }
        }
        for(int j=0;j<9;j++){
            temp.clear();
            for(int i=0;i<9;i++){
                if(board[i][j]=='.') continue;
                if(temp.find(board[i][j])!=temp.end()) return false;
                else temp[board[i][j]]=0;
            }
        }
        for(int i=0;i<9;i=i+3){
            for(int j=0;j<9;j=j+3){
                temp.clear();
                for(int m=i;m<i+3;m++){
                    for(int n=j;n<j+3;n++){
                        if(board[m][n]=='.') continue;
                        if(temp.find(board[m][n])!=temp.end()) return false;
                        else temp[board[m][n]]=0;
                    }
                }
            }
        }
        return true;
    }
};