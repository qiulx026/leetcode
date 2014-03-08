
class Solution {
public:
    vector<vector<int> > a;
    vector<int> mergesort(vector<int> num){
        if(num.size()==1) return num;
        int l=num.size()/2;
        vector<int>::iterator it=num.begin();
        while(l>0){
            l--;
            it++;
         }
        vector<int> front(num.begin(),it);
        vector<int> end(it,num.end());
        front=mergesort(front);
        end=mergesort(end);
        num=merge(front,end);
        return num;
    }
    vector<int> merge(vector<int> front, vector<int> end){
        vector<int> num;
        while(front.empty()==false&&end.empty()==false){
            if(front.front()>end.front()) {num.push_back(end.front()); end.erase(end.begin());}
            else {num.push_back(front.front());front.erase(front.begin());}
        }
        while(front.empty()==false){
            num.push_back(front.front());front.erase(front.begin());
        }
        while(end.empty()==false){
            num.push_back(end.front()); end.erase(end.begin());
        }
        return num;
    }
    void twosum(int n1,vector<int> num){
        for(vector<int>::iterator it=num.begin();it!=num.end();++it){
            for(vector<int>::iterator it1=it;it1!=num.end();++it1){
                if(n1+(*it)+(*it1)==0){
                    vector<int> ans;
                    ans.push_back(n1);
                    ans.push_back((*it));
                    ans.push_back((*it1));
                    a.push_back(ans);
                }
            }
        }
    }
    vector<vector<int> > threeSum(vector<int> &num) {
        if(num.empty()) return a;
        num=mergesort(num);
        vector<int> s;
        for(vector<int>::iterator it=num.begin();it!=num.end();++it){
            vector<int> s(it,num.end());
            twosum((*it),s);
        }
        return a;
    }
};
Submit Solution
