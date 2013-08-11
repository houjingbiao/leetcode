//version:
class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n == 0 || n == 1) return true;
		int MaxN = 0;
		for(int i = 0; i < n; i++){
			if(MaxN < i)
				return false;
			if(i + A[i] > MaxN)
				MaxN = i + A[i];
			if(MaxN >= n-1)
				return true;
		}
		return true;
    }
};

//version: dp, can't pass large case
class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n == 0 || n == 1) return true;
		bool* dp = new bool[n];
		memset(dp, 0, n);
		dp[n-1] = true;
		for(int i = n-2; i >= 0; i--){
			for(int j = i+1; j <= i+A[i] && j < n; j++){
				if(dp[j]){
					dp[i] = true;
					break;
				}
			}
		}
		bool ret = dp[0];
		delete[] dp;
		return ret;
    }
};
//version: dfs, can't pass large case 
class Solution {
public:
	bool dfs(int A[], int n, int pos){
		if(pos >= n-1) return true;
		for(int i = A[pos]; i > 0; i--){
			if(dfs(A, n, pos+i))
				return true;
		}
		return false;
	}
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n == 0 || n == 1) return true;
		for(int i = A[0]; i > 0; i--){
			if(dfs(A, n, 0+i))
				return true;
		}
		return false;
    }
};

