class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> myvector(2,0);
        map<int,int> mymap;
        int temp;
        for(int i=0;i<numbers.size();i++){
            temp=target-numbers[i];
            if(mymap.find(temp)!=mymap.end()){
                myvector[0]=mymap[temp]+1;
                myvector[1]=i+1;
                return myvector;
            }
            else{
                mymap[numbers[i]]=i;
            }
            
        }
        return myvector;
    }
};