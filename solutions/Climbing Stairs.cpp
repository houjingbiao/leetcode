class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n == 0) return 0;
		if(n == 1) return 1;
		if(n == 2) return 2;
		int f1 = 1; 
		int f2 = 2;
		for(int i = 3; i <= n; i++){
			int tmp = f2;
			f2 = f1 + f2;
			f1 = tmp;
		}
		return f2;
    }
};