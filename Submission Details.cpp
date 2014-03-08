class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int i=0;
        while(A[i]<target&&i<n){
            i++;
        }
        return i;
    }
};