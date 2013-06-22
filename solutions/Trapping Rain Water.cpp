//version that uses two extra arrays
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

//version 2: space: O(1), and time: O(n), why this method work? it's a 
class Solution {
public:
	int trap(int A[], int n) {
		if(n <= 2) return 0;
		int leftMax = A[0];
		int rightMax = A[n-1];
		int iL = 0;
		int iR = n-1;
		int ret = 0;
		while(iL <= iR)
		{
			if(leftMax < rightMax)
			{
				leftMax = max(leftMax, A[iL]);
				ret += leftMax - A[iL];
				iL++;
			}
			else
			{
				rightMax = max(rightMax, A[iR]);
				ret += rightMax - A[iR];
				iR--;
			}
		}
		return ret;
	}
};