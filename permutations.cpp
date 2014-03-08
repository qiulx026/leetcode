class Solution {
public:
    void builder(vector<vector<int> > &n, vector<int> res, vector<int> cur){
        int l=res.size();
        if(l==0){
            n.push_back(cur);
        }
        for(int i=0;i<l;i++){
            vector<int> temp(res);
            cur.push_back(temp[i]);
            vector<int>::iterator it=temp.begin();
            int j=0;
            while(j<i){
                ++it;
                ++j;
            }
            temp.erase(it);
            builder(n,temp,cur);
            cur.pop_back();
        }
    }
            
    
    
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> a;
        vector<int> cur;
        builder(a,num,cur);
        return a;
    }
};