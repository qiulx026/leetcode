class Solution {
public:
    int longestValidParentheses(string s) {
        int last=-1,max=0,temp=0;
        int length=s.length();
        stack<int> mystk;
        for(int i=0;i<length;i++){
            if(s[i]=='('){
                mystk.push(i);
            }
            else{
                if(mystk.empty()){
                    last=i;
                }
                else{
                    mystk.pop();
                    if(mystk.empty()){
                        temp=i-last;
                        if(temp>max) max=temp;
                    }
                    else{
                        temp=i-mystk.top();
                        if(temp>max) max=temp;
                    }
                }
            }
        }

        return max;
    }
};