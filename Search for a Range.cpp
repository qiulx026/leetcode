class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> a;
        for(int i=0;i<n;i++){
            if(A[i]<target) continue;
            if(A[i]==target){
                a.push_back(i);
                while(i<n){
                    if(A[i]==target) {i++;continue;}
                    else{a.push_back(i-1); return a;}
                }
                a.push_back(n-1);
                return a;
            }
        }
        a.push_back(-1);
        a.push_back(-1);
        return a;
    }
};