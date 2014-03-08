class Solution {
public:
    int climbStairs(int n) {
        if (n==1) return 1;
        if (n==2) return 2;
        int fn1=1,fn2=2,fn;
        for(int i=3;i<n+1;i++){
            fn=fn1+fn2;
            fn1=fn2;
            fn2=fn;
        }
        return fn;
    }
};