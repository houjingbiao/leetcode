class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 2)
            return 0;
        
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        
        leftMax[0] = A[0];
        rightMax[n-1] = A[n-1];

        for(int i = 1; i < n-1; i++)
        {
            leftMax[i] = max(leftMax[i-1], A[i]);
            rightMax[n-1-i] = max(rightMax[n-1-i+1], A[n-1-i]);
        }
        
        int ret = 0;
        for(int i = 1; i< n-1; i++)
        {
            ret += (leftMax[i] > rightMax[i]?rightMax[i]:leftMax[i])-A[i];
        }
        return ret;
    }
};