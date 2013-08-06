class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n == 0 || n == 1) return true;
		int pos = 0;
		while(pos < n-1){
			if(A[pos] == 0) return false;
			pos += A[pos];
		}
		return pos >= n-1;
    }
};