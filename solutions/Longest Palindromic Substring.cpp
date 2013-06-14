class Solution {
public:
	bool isPlaindrome(string s, int pos, int len)
	{
		for(int i = pos, j = pos+len-1; i < j; i++, j--)
		{
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
		for(int i = 0; i < s.length(); i++)
			len[i] = 1;

		for(int i = s.length()-2; i >= 0; i--)
		{
			for(int curLen = maxLen+1; curLen <= maxLen+2; curLen++)
			{
				if(isPlaindrome(s, i, curLen))
				{
					len[i] = curLen;
					maxLen = len[i];
					maxIdx = i;
				}
			}
		}
		return s.substr(maxIdx, maxLen);
	}
};