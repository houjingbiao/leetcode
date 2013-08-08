//version 1: this doesn't pass, perhaps because I misunderstand some rule of the regular expression matching
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
		int ls = strlen(s);
		int lp = strlen(p);
		if(ls == 0) return true;
		if(lp == 0 && ls > 0) return false;
		vector<vector<bool>> dp(ls, vector<bool>(lp, false));
		
		if('.' == p[0] || s[0] == p[0]) dp[0][0] = true;
		for(int j = 1; j < lp; j++){
			if('*' == p[0]) dp[0][j] = dp[0][j-1];
			else dp[0][j] = false;
		}
		
		for(int i = 1; i < ls; i++)
			dp[i][0] = false;
		
		for(int i = 1; i < ls; i++){
			for(int j = 1; j < lp; j++){
				if('.' == p[j] || s[i] == p[j]) dp[i][j] = dp[i-1][j-1];
				else if('*' == p[j]){
					int k = j-1;
					while(p[k] == '*') k--;
					if(p[k] == '.' || s[i] == p[k]) dp[i][j] = dp[i-1][j-1] || dp[i-1][j];
					else dp[i][j] = dp[i][j-1];
				}
				else dp[i][j] = false;
			}
		}
		return dp[ls-1][lp-1];
    }
};


//version 2:
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    
		if (!s || !p) return false;

		int slen = strlen(s);
		int plen = strlen(p);
		vector<bool> dp[plen+1];

		for (int i=0; i<=plen; i++)
			dp[i] = vector<bool> (slen+1, false);

		dp[0][0] = true;
		for (int i=1; i<=plen; i++) {
			switch(p[i-1]) {
			case '*':{
				dp[i][0] = i>1 ? dp[i-2][0] : false;
				if (i<2) continue;
				if (p[i - 2] != '.') {
					for (int j = 1; j <= slen; j++) {                               
						if (dp[i-1][j] || (i>=2 && dp[i-2][j]) || (j>=2 && dp[i][j-1] && s[j-1]==s[j-2] && s[j-2]==p[i-2]))
							dp[i][j] = true;
					}
				}else {
					int j = 1;
					while (!dp[i-2][j] && j<=slen && !dp[i-1][j]) j++;
					for (; j <= slen; j++) {
						dp[i][j] = true;
					}
				}
				break;
					 }
			default :{
				for (int j = 1; j <= slen; j++) {
					if (dp[i-1][j-1] && (s[j-1]==p[i-1] || p[i-1]=='.'))
						dp[i][j] = true;
				}
				break;
					 }
			}
		}
		return dp[plen][slen];
	}
};
