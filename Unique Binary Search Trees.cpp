class Solution {
public:
    int numTrees(int n) {
        if (n==0) return 0;
        if (n==1) return 1;
        int i,max=0;
        for(i=2;i<n;i++){
            max+=numTrees(i-1)*numTrees(n-i);
        }
        max+=2*numTrees(n-1);
        return max;
    }
};