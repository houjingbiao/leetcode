class Solution {
public:
	void dfs(int level, int pos, int len, string &str, string &s, vector<string> &rets)
	{
		string seg;
		if(level > 1)
			seg = ".";
		seg = seg+s.substr(pos, len);

		str = str + seg;
		
		if(len == 3)
		{
			int number = 0;
			int i = 0;
			while(i < len)
			{
				number = number*10 + s[pos+i] - '0';
				i++;
			}
			if(number > 255)
				return;
		}

		if(level == 4)
		{
			if(s.length() == pos + len)
				rets.push_back(str);
			return;
		}

		for(int newlen = 1; newlen < 4; newlen++)
		{
			if(pos+len+newlen > s.length() || level > 3 || (s[pos+len] == '0' && newlen > 1) || (level == 3&&pos+len+newlen < s.length()))
				continue;
			dfs(level+1, pos+len, newlen, str, s, rets);
			str.erase(str.length()-1-newlen, newlen+1);
		}
	}
	vector<string> restoreIpAddresses(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<string> rets;
		if(s.length() < 4)
			return rets;
		for(int len = 1; len < 4; len++)
		{
			if(len> s.length() || (s[0] == '0' && len > 1))
				continue;
			string str;
			dfs(1, 0, len, str, s, rets);
		}
		return rets;
	}
};