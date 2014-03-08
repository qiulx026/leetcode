class Solution {
public:
    string longestPalindrome(string s) {
        string s1=produce(s);
        int length=s1.length();
        vector<int> dp(length,0);
        int max=0,centre=0,maxlen=0;
        for(int i=1;i<length;i++){
            if(max>i){
                dp[i]=min(dp[2*centre-i],max-i);
            }
            
            while(i-dp[i]-1>=0&&i+dp[i]+1<length&&s1[i+dp[i]+1]==s1[i-dp[i]-1])
                dp[i]++;
            
            if((i+dp[i])>max){
                centre=i;
                max=i+dp[i];
            }
        }
        for(int i=1;i<length;i++){
            if(dp[i]>maxlen){
                centre=i;
                maxlen=dp[i];
            }
        }
        return s.substr((centre-dp[centre])/2,dp[centre]);
    }
    string produce(string s){
        if(s.empty()) return "#";
        string s1;
        for(int i=0;i<s.length();i++){
            s1.append(1,'#');
            s1.append(1,s[i]);
        }
        s1.append(1,'#');
        return s1;
    }
};