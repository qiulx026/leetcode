class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int length=digits.size();
        int i,flag=1,temp;
        for(i=length-1;i>=0&&flag==1;i--){
            temp=digits[i]+flag;
            digits[i]=temp%10;
            flag=temp/10;
        }
        vector<int>::iterator it=digits.begin();
        if(i==-1&&flag==1) digits.insert(it,1,1);
        return digits;
    }
};