class Solution {
public:
    bool canJump(int A[], int n) {
        int i,max=0;
        for(int i=0;i<n;i++){
            if(i>max) return false;
            else{
                if(i+A[i]>max) max=i+A[i];
                if(max>=n-1) return true;
            }
        }
        return false;
    }
};