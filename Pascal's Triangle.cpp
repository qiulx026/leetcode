class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> tri;
        if(numRows==0) return tri;
        vector<int> myrow(1,1);
        tri.push_back(myrow);
        int i=0;
        while(i<numRows-1){
            myrow.clear();
            myinsert(tri[i],myrow);
            tri.push_back(myrow);
            i++;
        }
        return tri;
    }
    void myinsert(vector<int> first,vector<int> &myrow){
        int length=first.size();
        myrow.push_back(first[0]);
        for(int i=0;i<length-1;i++){
            myrow.push_back(first[i]+first[i+1]);
        }
        myrow.push_back(first[length-1]);
    }
};