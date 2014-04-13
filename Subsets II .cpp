class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > myvec;
        if(S.size()==0)  return myvec;
        vector<int> sub;
        myvec.push_back(sub);
        sort(S.begin(), S.end());
        helper(myvec,0,sub,S);
        return myvec;
    }
    void helper(vector<vector<int> > &myvec, int step, vector<int> &sub, vector<int> &s){
        for(int i=step;i<s.size();i++){
            sub.push_back(s[i]);
            myvec.push_back(sub);
            if(i<s.size()-1)
                helper(myvec,i+1,sub,s);
            sub.pop_back();
            while(i<s.size()-1 && s[i]==s[i+1])
                i++;
        }        
    }
};