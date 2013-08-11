//version 3:


//version 2: dynamic programming, but memory limit exceed
class Solution {
public:
	string longestPalindrome(string s) {
		if(s.length() <= 1) return s;
		bool* dp = new bool[s.length()*s.length()];
		memset(dp, false, s.length()*s.length()*sizeof(bool));
		for(int i = 0; i < s.length(); i++)
			dp[i*s.length()+i] = true;
		int maxPos = 0; 
		int maxLen = 1;
		for(int len = 2; len <= s.length(); len++){
			for(int i = 0; i <= s.length() - len; i++){
				if(s[i + len - 1] == s[i] && (i+1 >= i+len-2 || dp[(i+1)*s.length()+i+len-2])){
					dp[i*s.length()+i+len-1] = true;
					maxPos = i;
					maxLen = len;
				}
			}
		}
		delete[] dp;
		return s.substr(maxPos, maxLen);
	}
};

//version 1: from back to forth
class Solution {
public:
	bool isPlaindrome(string s, int pos, int len){
		for(int i = pos, j = pos+len-1; i < j; i++, j--){
			if(s[i] != s[j])
				return false;
		}
		return true;
	}
	string longestPalindrome(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(s.length() <= 1) return s;
		vector<int> len(s.length());
		int maxIdx = 0;
		int maxLen = 1;

		for(int i = s.length()-2; i >= 0; i--){
			for(int curLen = maxLen+1; curLen <= maxLen+2; curLen++){
				if(isPlaindrome(s, i, curLen)){
					maxLen = curLen;
					maxIdx = i;
				}
			}
		}
		return s.substr(maxIdx, maxLen);
	}
};