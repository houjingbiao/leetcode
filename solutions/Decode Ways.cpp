int numDecodings (string s)
{
	if (s.empty ())
		return 0;

	s += '\0';
	reverse (begin (s), end (s));

	vector<int> dp (s.size ());
	dp [0] = 1;
	dp [1] = s [1] == '0' ? 0 : 1;

	for (int i = 2; i < s.size (); ++i) {
		int n1 = s [i] - '0';
		int n2 = n1 * 10 + (s [i - 1] - '0');

		if (n1 == 0)
			dp [i] = 0;
		else if (n2 % 10 == 0 && n2 < 26)
			dp [i] = dp [i - 2];
		else if (1 <= n2 && n2 <= 26)
			dp [i] = dp [i - 1] + dp [i - 2];
		else
			dp [i] = dp [i - 1];
	}

	return dp.back ();
}

int numDecodings2(string s) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(s.length() == 0)
		return 0;

	vector<int> dp(s.length() + 1);
	dp[s.length()] = 1;
	dp[s.length() - 1] = s[s.length()-1] == '0'? 0 : 1;

	for(int i = s.length() - 2; i >= 0; i--)
	{
		int n1 = s[i] - '0';
		int n2 = s[i+1] - '0' + n1*10;

		if(n1 == 0)
			dp[i] = 0;
		else if(n2%10 == 0 && n2 <= 26)
			dp[i] = dp[i+2];
		/*else if(n2%10 == 0 && n2 > 26)
		dp[i] = 0;*/
		else if(n2 >= 1 && n2 <= 26)
			dp[i] = dp[i+1] + dp[i+2];
		else
			dp[i] = dp[i+1];
	}
	return dp[0];
}