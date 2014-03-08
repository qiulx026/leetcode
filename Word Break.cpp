class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n=dict.size(),l=s.length();
        vector<bool> a;
        string s1;
        int m;
        bool flag;
        unordered_set<string>::iterator iterCur;
        for(int i=0;i<l;i++){
            a.push_back(false);
            for(iterCur = dict.begin();iterCur != dict.end();++iterCur){
                s1=*iterCur;
                m=s1.size();
                if (i+1==m) {flag=true;}
                if (i+1>m) {flag=a[i-m];}
                if((i+1>=m)&&(s[i]==s1[m-1])&&flag){
                   a[i]=true;
                   break;
                }
            }
        }
        if(a[l-1]==true) return true;
        else return false;
        
    }
};