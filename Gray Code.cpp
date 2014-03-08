class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> a;
        int l=1<<n;
        for(int i=0;i<l;i++){
            a.push_back((i>>1)^i);
        }
        return a;
    }
};