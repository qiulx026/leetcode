class Solution {
public:
    void reverseWords(string &s) {
        int length=s.length();
        int i=0,low,high;
        while(i<length){
            if(s[i]==' '){
                while(i+1<length&&s[i+1]==' '){
                    s.erase(i+1,1);
                    length--;
                }
            }
            i++;    
        }
        if(!s.empty()&&s[length-1]==' ') s.erase(length-1,1);
        if(!s.empty()&&s[0]==' ') s.erase(0,1);
        i=0,length=s.length();
        reversefun(s,0,length-1);
        while(i<length){
            if(s[i]==' ') {
                i++;
                continue;
            }
            else{
                low=i++;
                while(i<length&&s[i]!=' ')
                    i++;
                high=i-1;
                if((i==length-1)&&(s[i]!=' ')) high=i;
                reversefun(s,low,high);
            }
        }

    }
    void reversefun(string &s,int low,int high){
        char c;
        while(low<high){
            c=s[low];
            s[low]=s[high];
            s[high]=c;
            low++,high--;
        }
    }
};