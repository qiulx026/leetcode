#include <string>

using namespace std; 

class Solution {
public:
    int romanToInt(string s){
        int i,n=0;
		char ch[2];
        string s1,s2,s3,s4;
        for (i=0;i<s.length();i++){
			ch[0]=s[i];
			ch[1]=0;
            if((i+1)<s.length()&&(s[i]=='I')&&(s[i+1]=='X')) {n+=9;i++;}
            else{
				if((i+1)<s.length()&&(s[i]=='X')&&(s[i+1]=='C')) {n+=90;i++;}
				else{ 
					if((i+1)<s.length()&&(s[i]=='C')&&(s[i+1]=='M')) {n+=900;i++;}
                    else{
                        if((s[i]=='V')||(s[i]=='I'))
                        s1.append(ch);
                        if((s[i]=='X')||(s[i]=='L'))
                        s2.append(ch);
                        if((s[i]=='C')||(s[i]=='D'))
                        s3.append(ch);
                        if(s[i]=='M')
                        s4.append(ch);
                    }
				}
			}
			
        }
        if(s4=="M") n+=1000;
        if(s4=="MM") n+=2000;
        if(s4=="MMM") n+=3000;
        if(s3=="C") n+=100;
        if(s3=="CC") n+=200;
        if(s3=="CCC") n+=300;
        if(s3=="CD") n+=400;
        if(s3=="D") n+=500;
        if(s3=="DC") n+=600;
        if(s3=="DCC") n+=700;
        if(s3=="DCCC") n+=800;
        if(s2=="X") n+=10;
        if(s2=="XX") n+=20;
        if(s2=="XXX") n+=30;
        if(s2=="XL") n+=40;
        if(s2=="L") n+=50;
        if(s2=="LX") n+=60;
        if(s2=="LXX") n+=70;
        if(s2=="LXXX") n+=80;
        if(s1=="I") n+=1;
        if(s1=="II") n+=2;
        if(s1=="III") n+=3;
        if(s1=="IV") n+=4;
        if(s1=="V") n+=5;
        if(s1=="VI") n+=6;
        if(s1=="VII") n+=7;
        if(s1=="VIII") n+=8;
        return n;
    }
};