class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0; 
        int right = n-1;
        while(left < right)
        {
            int mid = left+(right-left)/2;
            if(A[mid] >= A[left])//left side sorted, including mid,
            {
                if(A[left] <= target && target <= A[mid]) right = mid;
                else left = mid+1;
            }
            else//right side sorted
            {
                if(A[mid] <= target && target <= A[right]) left = mid;
                else right = mid-1;
            }
        }
        if(right >= 0 && right < n && A[right] == target) return right;
        else return -1;
    }
};