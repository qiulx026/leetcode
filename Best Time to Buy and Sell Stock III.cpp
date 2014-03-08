class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;
        int min=prices[0],max=0,max_po=0,min_po1=0,min_po=0;
        int i,l=prices.size();
        for(i=0;i<l;i++){
            if(prices[i]<min) {min=prices[i];min_po1=i;}
            if((prices[i]-min)>max) {max=(prices[i]-min);min_po=min_po1;max_po=i;}
        }
        vector<int> s1(prices.begin(),prices.begin()+min_po);
        vector<int> s2(prices.begin()+min_po+1,prices.begin()+max_po+1);
        vector<int> s3(prices.begin()+max_po+1,prices.end());
        int m1=search1(s1);
        int m2=search2(s2);
        int m3=search1(s3);
        if(m1<m2) m1=m2;
        if(m1<m3) m1=m3;
        max+=m1;
        return max;
    }
    int search1(vector<int> &price1){
        if(price1.empty()) return 0;
        int min=price1[0],max=0;
        vector<int>::iterator it;
        for(it=price1.begin();it!=price1.end();it++){
            if(*it<min) {min=*it;}
            if((*it-min)>max) {max=(*it-min);}
        }
        return max;
    }
    int search2(vector<int> &price2){
        if(price2.empty()) return 0;
        int max=price2[0],min=0;
        vector<int>::iterator it;
        for(it=price2.begin();it!=price2.end();it++){
            if(*it>max) {max=*it;}
            if((max-*it)>min) {min=(max-*it);}
        }
        return min;
    }
};