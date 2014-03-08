class Solution {
public:
	   int lengthOfLongestSubstring(string s) {
        int i,j,count,mmax=0,n=0;
        for(i=0;i<s.length();i++){
            map<char,int> mmap;
            count=0;
            for(j=i;j<=s.length();j++){
				if(j==s.length()) {mmax=count;break;}	
				if(mmap.find(s[j])==mmap.end())	{mmap[s[j]]=1;count++;}				
				else{mmax=count;break;}			
			}
			if (mmax>n) n=mmax;
        }
        return n;
    }
};