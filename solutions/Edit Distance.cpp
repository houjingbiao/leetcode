//version 2:
class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(word1.length() == 0 || word2.length() == 0) return max(word1.length(), word2.length());
		vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), 0));
		if(word1[0] != word2[0]) dp[0][0] = 1;
		for(int i = 1; i < word1.length(); i++)
			if(word1[i] == word2[0]) dp[i][0] = i;
			else dp[i][0] = dp[i-1][0]+1;
		
		for(int i = 1; i < word2.length(); i++)
			if(word1[0] == word2[i]) dp[0][i] = i;
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

//version 1
class Solution {
public:
    inline int minInt(int a, int b){
        return (a< b?a:b);
    }
    inline int minInt(int a, int b, int c){
        return minInt(minInt(a, b), c);        
    }
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l1 = word1.length();
        int l2 = word2.length();
        string& w1 = (l1< l2?word1:word2);//shorter - horizontal
        string& w2 = (l1< l2?word2:word1);//longer - vertical
        int const length1 = w1.length();
        int const length2 = w2.length();
        if (!length1) return length2;
        vector< int> dist(length1,0);
        for(int ii = 0; ii < length1; ++ii){//row 0, dist[0] is not used
            dist[ii] = ii + 1;
        }//for ii
        for(int ii = 0; ii < length2; ++ii){//vertical, start from row 1 (when length2==1)
            int distDiag = ii;
            int distLeft = ii + 1;
            for(int jj = 0; jj < length1; ++jj){//horizontal
                int const distUp = dist[jj];
                if (w1[jj] == w2[ii]) dist[jj] = distDiag;
                else dist[jj] = minInt(distLeft, distUp, distDiag) + 1;
                distDiag = distUp;
                distLeft = dist[jj];
            }
        }
        return dist[length1-1];
    }
};

