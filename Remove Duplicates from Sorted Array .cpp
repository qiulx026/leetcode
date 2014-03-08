class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i=0,count=0;
        map<int,int> mmap;
        for(i=0;i<n;i++){
            if(mmap.find(A[i])==mmap.end()) {mmap[A[i]]=1;A[count]=A[i];count++;}
        }
        return count;
        
    }
};