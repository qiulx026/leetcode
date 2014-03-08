class Solution {
public:
    int maxSubArray(int A[], int n) {
        int temp=0,max=A[0];
        for(int i=0;i<n;i++){
            temp=temp+A[i];
            if(temp>max) max=temp;
            if(temp<0) temp=0;
        }
        return max;
    }
};