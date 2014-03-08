class Solution {
public:
    bool isNumber(const char *s) {
	string s1(s);
	int l=s1.length();
	int num_flag=0,dot_flag=0,e_flag=0,dote_flag=0,ee_flag=0,bar_flag=0,bare_flag=0;
	for(int i=0;i<l;i++){
		if (s[i]==' '){
			if(i<l-1&&num_flag==0&&dote_flag==0&&ee_flag==0&&bare_flag==0) {continue;}
			else{
				while(i<l){
				    if(i==l-1&&num_flag==0&&dote_flag==0&&ee_flag==0) {return false;}
					else if(s[i]!=' ') {return false;}
					i++;
				}
			}
		}
		else if (s[i]=='e'){
			if(num_flag==0||ee_flag==1||bar_flag==1||dot_flag==1) {return false;}
			else {e_flag=1;ee_flag=1;bar_flag=0;bare_flag=0;continue;}
		}
		else if(s[i]=='.'){
			if(ee_flag==1||dote_flag==1) {return false;}
			else { 
			    if (num_flag==0) {dot_flag=1;}
			    dote_flag=1;
			    continue;
			}
		}
		else if(s[i]=='-'||s[i]=='+'){
		    if(num_flag==1||dote_flag==1||bare_flag==1) {
		        if(num_flag==1&&i<l-1){
		            if (s[i+1]=='.') {dot_flag=1;dote_flag=1;i++;continue;}
		        }
		        if(num_flag==1&&i>0){
		            if (s[i-1]=='e') {bare_flag=1;continue;}
		        }
		        return false;
		    }
		    else {bare_flag=1;bar_flag=1;continue;}
		}
		else if (s[i]>='0'&&s[i]<='9'){
			if(e_flag==1) {e_flag=0;}
			if(dot_flag==1) {dot_flag=0;}
			if(bar_flag==1) {bar_flag=0;}
			num_flag=1;
			continue;
		}
		else {return false;}
	}
	if (dot_flag==1||e_flag==1||bar_flag==1) {return false;}
	return true;
}
};