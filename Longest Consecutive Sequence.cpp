class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        map<int,int> mfind,mvalue;
        int i,m,n=num.size(),count,maxx=0;
        for(i=0;i<n;i++){
            if(mfind.find(num[i])==mfind.end()) {mfind[num[i]]=0;mvalue[num[i]]=0;}
        }
        for(i=0;i<n;i++){
            if (mfind[num[i]]==0) {
            m=num[i];
            count=1;
            while(mfind.find(m+1)!=mfind.end()){
                if (mfind[m+1]==1) {count+=mvalue[m+1];break;}
                mfind[m+1]=1;
                count++;
                m++;
            }
            mvalue[num[i]]=count;
            mfind[num[i]]=1;
            }
        }
        for(i=0;i<n;i++){
            if(mvalue[num[i]]>maxx) maxx=mvalue[num[i]];
        }
        return maxx;
    }
};