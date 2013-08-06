class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n == 0) return 0;
        int* sum = new int[n];
		sum[n-1] = A[n-1];
		int ret = sum[n-1];
		for(int i = n-2; i >= 0; i--){
			sum[i] = A[i] + max(0, sum[i+1]);
			ret = max(ret, sum[i]);
		}
		delete[] sum;
		return ret;
    }
};