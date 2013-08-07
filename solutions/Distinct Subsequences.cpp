class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(S.length() < T.length() || S.length() == 0 || T.length() == 0) return 0;
		
		vector<vector<int>> dp(T.length(), vector<int>(S.length(), 0));
		if(S[0] == T[0])
			dp[0][0] = 1;
		for(int j = 1; j < S.length(); j++)
			if(S[j] == T[0]) dp[0][j] = dp[0][j-1]+1;
			else dp[0][j] = dp[0][j-1];
		for(int i = 1; i < T.length(); i++)	if(T[i] == S[i]) dp[i][i] = dp[i-1][i-1];
		
		for(int i = 1; i < T.length(); i++){
			for(int j = i+1; j < S.length(); j++){
				if(S[j] == T[i])
					dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
				else
					dp[i][j] = dp[i][j-1];
			}
		}
		return dp[T.length()-1][S.length()-1];
    }
};