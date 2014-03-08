class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty()==true) return;
        int a=matrix.size();
        int b=matrix[0].size();
        vector<int> row(a,0);
        vector<int> colomn(b,0);
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    colomn[j]=1;
                }
        }
        
        }
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(row[i]==1||colomn[j]==1)
                    matrix[i][j]=0;
    }
    }
    }
};