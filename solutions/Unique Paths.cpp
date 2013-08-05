class Solution {
public:
	int multiply(int m, int n){
		unsigned long long ret = 1;
		for(int i = 1, j = n; i <= m-1; i++, j++){
			ret *= j;
			ret /= i;
		}
		return ret;
	}
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(m == 1||n == 1)
			return 1;
		if(m < n) return multiply(m, n);
		else return multiply(n, m);
    }
};

