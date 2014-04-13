class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector< int> > myvec(m,vector<int>(n,0));
        int i,j;
        myvec[0][0]=grid[0][0];
        for(i=1;i<m;i++){
            myvec[i][0]=myvec[i-1][0]+grid[i][0];
        }
        for(j=1;j<n;j++){
            myvec[0][j]=myvec[0][j-1]+grid[0][j];
        }
        for(i=1;i<m;i++)
            for(j=1;j<n;j++){
                myvec[i][j]=min(myvec[i-1][j],myvec[i][j-1])+grid[i][j];
            }
        return myvec[m-1][n-1];
    }
};