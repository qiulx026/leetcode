class Solution {
public:
     vector<string> ans;
     bool valid(string s){
        if(s.empty()) {return false;}
        int i=atoi(s.c_str()),l=s.size();
        if(i>=0&&i<=255){
            if(l>1&&s[0]=='0') {return false;}
            else return true;
        }
        return false;
    }
	 void ip(string s1,string s2,int n){
        int i=0,l=s2.size();
        string s;
        string r;
        if(n==3){
			if(valid(s2)) ans.push_back(s1+s2);
        }
        if(n>=0&&n<=2){
            while(i<3&&i<l-3+n){
                s=string(s2,0,i+1);
                if(valid(s)) {
                    ip(s1+s+'.',string(s2,i+1),n+1);        
                }
				i++;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string s1;
        ip(s1,s,0);
        return ans;
    }
};