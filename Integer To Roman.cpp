class Solution {
public:
    string intToRoman(int num) {
        int n;
        string s;
        n=num/1000;
        if(n==3) s.append("MMM");
        if(n==2) s.append("MM");
        if(n==1) s.append("M");
        n=(num%1000)/100;
        if(n==9) s.append("CM");
        if(n==8) s.append("DCCC");
        if(n==7) s.append("DCC");
        if(n==6) s.append("DC");
        if(n==5) s.append("D");
        if(n==4) s.append("CD");
        if(n==3) s.append("CCC");
        if(n==2) s.append("CC");
        if(n==1) s.append("C");
        n=(num%100)/10;
        if(n==9) s.append("XC");
        if(n==8) s.append("LXXX");
        if(n==7) s.append("LXX");
        if(n==6) s.append("LX");
        if(n==5) s.append("L");
        if(n==4) s.append("XL");
        if(n==3) s.append("XXX");
        if(n==2) s.append("XX");
        if(n==1) s.append("X");
        n=num%10;
        if(n==9) s.append("IX");
        if(n==8) s.append("VIII");
        if(n==7) s.append("VII");
        if(n==6) s.append("VI");
        if(n==5) s.append("V");
        if(n==4) s.append("IV");
        if(n==3) s.append("III");
        if(n==2) s.append("II");
        if(n==1) s.append("I");
        return s;
    }
};