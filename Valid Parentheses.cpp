class Solution {
public:
    bool isValid(string s) {
        stack<char> c;
        int i;
        for(i=0;i<s.size();i++){
            if(s.at(i)=='{'||s.at(i)=='['||s.at(i)=='('){
                c.push(s.at(i));
            }
            if(c.empty()) return false;
            if(s.at(i)=='}'){
                if (c.top()=='{') {c.pop();}
                else return false;
            }
            if(s.at(i)==')'){
                if (c.top()=='(') {c.pop();}
                else return false;
            }
            if(s.at(i)==']'){
                if (c.top()=='[') {c.pop();}
                else return false;
            }
        }
        if(c.empty()) return true;
        else return false;
       
        
    }
};