class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int l=gas.size();
        vector<int> myvec(l,0);
        int i=0,max_gas=0,max_pos=0,temp_gas=0,temp_pos=0;
        for(i=0;i<l;i++){
            myvec[i]=gas[i]-cost[i];
        }
        for(i=0;i<2*l-1;i++){
            int pos=i%l;
            temp_gas=temp_gas+myvec[pos];
            if(temp_gas>max_gas) {
                max_gas=temp_gas;
                max_pos=temp_pos;
            }
            if(temp_gas<0) {
                temp_gas=0;
                temp_pos=(pos+1)%l;
            }
        }
        temp_gas=0;
        for(i=0;i<l;i++){
            temp_pos=(i+max_pos)%l;
            temp_gas=temp_gas+myvec[temp_pos];
            if(temp_gas<0) return -1;
        }
        return max_pos;
    }
};