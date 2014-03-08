class Solution {
public:

    string c(string s) {
        string s1;
        int i,count;
        bool flag=false;
        for(i=0;i<s.size();i++){
            if(flag==false) {count=1;flag=true;continue;}
            else{
                while(i<s.size()&&s.at(i)==s.at(i-1)){
                    i++;
                    count++;
                }
                if(i==s.size()) {
					break;
				}
                else{
					s1.append(to_string(count));
                    s1.append(1,s.at(i-1));
                    count=1;
                }
            }
        }
		if(i==s.size()) {
			s1.append(to_string(count));
            s1.append(1,s.at(i-1));
		}
        return s1;
    }
    string countAndSay(int n) {
        string s="1";
        for(int i=1;i<n;i++){
            s=c(s);
        }
        return s;
    }
};