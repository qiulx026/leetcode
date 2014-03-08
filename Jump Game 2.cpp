class Solution {
public:
    int jump(int A[], int n) {
        if(n==0) return 0;
        vector<int> myvector(n,0);
        int max=0;
        for(int i=0;i<n&&max<n;i++){
            if(i+A[i]<= max) continue;
            else{
                for(int j=max+1;j<n&&j<=i+A[i];j++){
                    myvector[j]=myvector[i]+1;
                }
                max=i+A[i];
            }
            
        }
        return myvector[n-1];
    }
};