class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;
        int min=prices[0],max=0;
        vector<int>::iterator it;
        for(it=prices.begin();it!=prices.end();it++){
            if(*it<min) {min=*it;}
            if((*it-min)>max) {max=(*it-min);}
        }
        return max;
    }
};