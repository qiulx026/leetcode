class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;
        int flag=0;
        int buy=prices[0],sell,max=0;
        vector<int>::iterator it;
        for(it=prices.begin();it!=prices.end();++it){
            if(flag==0){
                if(buy<*it) {flag=1;sell=*it;}
                else {buy=*it;}
            }
            else{
                if(sell>*it) {flag=0; max+=sell-buy; buy=*it;}
                else{sell=*it;}
            }
        }
        if(flag==1) max+=sell-buy;
        return max;
        
    }
};