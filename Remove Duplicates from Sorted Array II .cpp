class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=1) return n;
        int i;
        int length=1;
        int pre=A[0];
        int cur=A[1];
        for(i=2;i<n;i++){
            if(pre==cur){
                while(A[i]==cur){
                    if(i==n-1) return length+1;
                    i++;
                }
            }
            pre=cur;
            cur=A[i];
            length++;
            A[length]=A[i];
            
        }
        return length+1;
    }
};