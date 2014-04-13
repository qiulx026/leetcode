class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x < 0) return false;
        
        long long target = x;
        //if(target < 0) target = -target; 
        long long reverse = 0;
        long long curNum = target;
        while(curNum != 0)
        {
            reverse = 10*reverse+curNum%10;
            curNum /= 10;
        }
        
        return reverse == target;
    }
};