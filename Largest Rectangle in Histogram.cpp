class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> s_height;
        stack<int> s_index;
        if(height.empty()) return 0;
        int i,area=0,llength=0,hheight=0;
        for(i=0;i<height.size();i++){
            if((s_height.empty())||(height[i]>s_height.top())){s_height.push(height[i]);s_index.push(i);}
            else if(height[i]<s_height.top()){
                llength=0;                
                while((!s_height.empty())&&(s_height.top()>height[i])){
                    llength=s_index.top();
                    hheight=s_height.top();
                    area=max(area,(i-llength)*hheight);
                    s_height.pop();
                    s_index.pop();
                }
                s_height.push(height[i]);
                s_index.push(llength);
            }
        }
        while(!s_height.empty()){
            llength=s_index.top();
            hheight=s_height.top();
            area=max(area,(i-llength)*hheight);
            s_index.pop();
            s_height.pop();
        }
        return area;
    }
};