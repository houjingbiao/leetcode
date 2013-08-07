class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(word1.length() == 0 || word2.length() == 0) return max(word1.length(), word2.length());
		vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), 0));
		if(word1[0] != word2[0]) dp[0][0] = 1;
		for(int i = 1; i < word1.length(); i++)
			if(word1[i] == word2[0]) dp[i][0] = dp[i-1][0];
			else dp[i][0] = dp[i-1][0]+1;
		
		for(int i = 1; i < word2.length(); i++)
			if(word1[0] == word2[i]) dp[0][i] = dp[0][i-1];
			else dp[0][i] = dp[0][i-1]+1;
		
		for(int i = 1; i < word1.length(); i++){
			for(int j = 1; j < word2.length(); j++){
				if(word1[i] == word2[j])  dp[i][j] = dp[i-1][j-1];
				else{
					int xx = min(dp[i-1][j-1], dp[i-1][j]);
					dp[i][j] = min(xx, dp[i][j-1])+1;
				}
			}
		}
        return dp[word1.length()-1][word2.length()-1];
    }
};