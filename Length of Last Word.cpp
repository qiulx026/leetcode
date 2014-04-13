class Solution {
public:
    int lengthOfLastWord(const char *s) {
        string s1(s);
        int i,l=s1.length();
        for(i=0;i<l/2;i++){
            swap(s1[i],s1[l-i-1]);
        }
        int flag=0,count=0;
        for(i=0;i<l;i++){
            if(flag==0){
                if(s1[i]==' ') continue;
                else {
                    flag=1;
                    count++;
                    continue;
                }
            }
            else{
                if(s1[i]!=' '){
                    count++;
                    continue;
                }
                else break;
            }
        }
        return count;
    }
};