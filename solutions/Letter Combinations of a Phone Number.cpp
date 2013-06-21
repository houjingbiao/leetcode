class Solution {
public:
	void dfs(int idx, string &str, string &digits, vector<string> dicts, vector<string> &ret)
	{
		str.push_back(dicts[digits[str.length()]-'1'][idx]);
		if(digits.size() == str.size())
		{
			ret.push_back(str);
			return;
		}

		for(int i=0; i<dicts[digits[str.length()]-'1'].size(); i++)
		{
			dfs(i, str, digits, dicts, ret);
			str.pop_back();
		}
	}
	vector<string> letterCombinations(string digits) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<string> ret;
		if(digits.size() == 0)
		{
			ret.push_back(digits);
			return ret;
		}

		vector<string> dicts;
		dicts.push_back(string(""));
		dicts.push_back(string("abc"));
		dicts.push_back(string("def"));
		dicts.push_back(string("ghi"));
		dicts.push_back(string("jkl"));
		dicts.push_back(string("mno"));
		dicts.push_back(string("pqrs"));
		dicts.push_back(string("tuv"));
		dicts.push_back(string("wxyz"));

		for(int i = 0; i < dicts[digits[0]-'1'].size(); i++)
		{
			string str;
			dfs(i, str, digits, dicts, ret);
		}

		return ret;

	}
};