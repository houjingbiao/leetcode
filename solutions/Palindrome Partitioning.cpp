class Solution {
public:
	bool isPlaindrome(string str){
		for(int i = 0; i < (str.length()+1)/2; i++){
			if(str[i] != str[str.length()-1-i])
				return false;
		}
		return true;
	}
	
	void dfs(int b, int len, string& s, vector<string>& ret, vector<vector<string>>& rets){
		
		ret.push_back(s.substr(b, len));
		int newstart = (b+len);
		if(newstart >= s.length()){
			rets.push_back(ret);
			return;
		}
		
		for(int newlen = 1; newlen <= s.length() - newstart; newlen++){
			if(isPlaindrome(s.substr(newstart, newlen))){
				dfs(newstart, newlen, s, ret, rets);
				ret.pop_back();
			}
		}
	}
	
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		vector<vector<string>> rets;
		for(int len = 1; len <= s.length(); len++){
			vector<string> ret;
			ret.clear();
			if(isPlaindrome(s.substr(0, len)))
				dfs(0, len, s, ret, rets);
		}
        return rets;
    }
};