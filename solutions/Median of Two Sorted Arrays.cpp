class Solution {
public:
	double getNumber(int A[], int m, int B[], int n, int k)
	{
		if(m == 0) return B[k - 1];
		if(n == 0) return A[k - 1];
		if(m >= k && A[k-1] <= B[0]) return A[k-1];
		if(n >= k && B[k-1] <= A[0]) return B[k-1];

		int A_start = n >= k ? 0 : k - n - 1;
		int A_end = m > k-1? k - 2 : m - 1;

		int i = A_end;
		int j = k - i - 2;

		while(1)
		{
			if(A[i] >= B[j])
			{
				if(j == n-1 || A[i] <= B[j+1])
					return A[i];
				else
				{
					A_end = i;
					i = (A_start + A_end)/2;
					j = k - i - 2;
				}
			}
			else// if(A[i] < B[j])
			{
				if(i == m - 1 || B[j] <= A[i+1])
					return B[j];
				else
				{
					A_start = i;
					i = (A_start + A_end)/2;
					j = k - i - 2;
				}
			}
		}
	}

	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int k = (m+n+1)>>1;
		if( (m+n)%2 == 0 )
			return (getNumber(A, m, B, n, k) + getNumber(A, m, B, n, k+1))/2;
		else
			return getNumber(A, m, B, n, k);
	}
};