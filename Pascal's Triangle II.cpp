class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows=rowIndex;
        vector<vector<int>> tri;
        vector<int> myrow(1,1);
        tri.push_back(myrow);
        int i=0;
        while(i<numRows){
            myrow.clear();
            myinsert(tri[i],myrow);
            tri.push_back(myrow);
            i++;
        }
        return tri[numRows];
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