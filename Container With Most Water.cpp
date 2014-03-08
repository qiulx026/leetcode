class Solution {
public:
   int maxArea(vector<int> &height) {  
     // Start typing your C/C++ solution below  
      // DO NOT write int main() function  
      int start =0;  
      int end = height.size()-1;  
      int maxV = INT_MIN;  
      while(start<end)  
      {  
        int contain = min(height[end], height[start]) * (end-start);  
        maxV = max(maxV, contain);  
        if(height[start]<= height[end])  
        {  
          start++;  
        }  
        else  
        {  
          end--;  
        }  
      }  
      return maxV;  
    }  
};