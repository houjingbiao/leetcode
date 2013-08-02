//version 1: dfs method exceed the time limitation.
class Solution {
public:
	bool isPlaindrome(string str){
		for(int i = 0; i < (str.length()+1)/2; i++){
			if(str[i] != str[str.length()-1-i])
				return false;
		}
		return true;
	}
	
	void dfs(int b, int len, string& s, vector<string>& ret, int& mincut){
		
		ret.push_back(s.substr(b, len));
		int newstart = (b+len);
		if(newstart >= s.length()){
			mincut = (ret.size()-1) < mincut ? ret.size()-1: mincut;
			return;
		}
		if(mincut <= ret.size()) return;
		
		for(int newlen = s.length() - newstart; newlen >= 1; newlen--){
			if(isPlaindrome(s.substr(newstart, newlen))){
				dfs(newstart, newlen, s, ret, mincut);
				ret.pop_back();
			}
		}
	}
	
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		int mincut = s.length();
		for(int len = s.length(); len >= 1; len--){
			vector<string> ret;
			ret.clear();
			if(isPlaindrome(s.substr(0, len)))
				dfs(0, len, s, ret, mincut);
		}
        return mincut;
    }
};


//version 2: dp

class Solution {
public:
int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(s.length() < 2) return 0;
		
		vector<vector<bool>> marks(s.length(), vector<bool>(s.length(), false));
		
		for(int i = 0; i < s.length(); i++)
			marks[i][i] = true;
		
		for(int i = 1; i < s.length(); i++)
			if(s[i] == s[i-1]) marks[i-1][i] = true;
		
		for(int len = 3; len <= s.length(); len++){
			for(int i = len-1; i < s.length(); i++)
				if(s[i-len+1] == s[i] && marks[i-len+1+1][i-1] == true)
					marks[i-len+1][i] = true;
				else
					marks[i-len+1][i] = false;
		}
		int* dp = new int[s.length()+1];
		
		for(int i = 0; i < s.length(); i++)
			dp[i] = i;
		
		for(int i = 0; i < s.length(); i++){
			if(marks[0][i] == true){
				dp[i] = 0;
				continue;
			}
			for(int j = 1; j <= i; j++){
				if(marks[j][i] == true){
					dp[i] = dp[i] > dp[j-1]+1 ? dp[j-1]+1 : dp[i];
				}
			}
		}
		int mincut = dp[s.length()-1];
		delete[] dp;
        return mincut;
    }
};