class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<string>::iterator it;
        stack<string> mystack;
        string temp1,temp2,result;
        for(it=tokens.begin();it!=tokens.end();it++){
            if((*it)=="+"){
                temp1=mystack.top();
                mystack.pop();
                temp2=mystack.top();
                mystack.pop();
                result=to_string(stoi(temp2)+stoi(temp1));
                mystack.push(result);
            }
            else if((*it)=="-"){
                temp1=mystack.top();
                mystack.pop();
                temp2=mystack.top();
                mystack.pop();
                result=to_string(stoi(temp2)-stoi(temp1));
                mystack.push(result);
            }
            else if((*it)=="*"){
                temp1=mystack.top();
                mystack.pop();
                temp2=mystack.top();
                mystack.pop();
                result=to_string(stoi(temp2)*stoi(temp1));
                mystack.push(result);
            }
            else if((*it)=="/"){
                temp1=mystack.top();
                mystack.pop();
                temp2=mystack.top();
                mystack.pop();
                result=to_string(stoi(temp2)/stoi(temp1));
                mystack.push(result);
            }
            else 
                mystack.push((*it));
        }
        return stoi(mystack.top());
    }
};