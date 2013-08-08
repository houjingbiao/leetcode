//version 2:
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int ls = strlen(s);
		int lp = strlen(p);
		if(ls==lp && ls==0) return true;
		int ch_count = 0;
		for(int i = 0; i < lp; i++)
			if(p[i] != '*') ch_count++;
		if(ch_count > ls) return false;
		if(ls == 0 && ch_count == 0) return true;

		vector<vector<bool>> dp(lp, vector<bool>(ls, false));
		ch_count = 0;
		//the first row
		if(p[0] == '*'){
			for(int j = 0; j < ls; j++)
				dp[0][j] = true;
		}
		else{
			if(p[0] == '?' || p[0] == s[0])
				 dp[0][0] = true;
			else return false;
			
			for(int j = 1; j < ls; j++)
				dp[0][j] = false;
			ch_count++;
		}
		
		//the first column
		for(int i = 1; i < lp; i++){
			if(p[i] == '*'){
				dp[i][0] = dp[i-1][0];
			}
			else
			{
				ch_count++;
				if(ch_count == 1 && (p[i] == '?'||p[i] == s[0])) dp[i][0] = true;
				else dp[i][0] = false;
			}
		}
		
		//other rows and columns
		if(p[0] != '*') ch_count = 1;
		else ch_count = 0;
		for(int i = 1; i < lp; i++){
			if(p[i] != '*'){
				for(int j = 1; j < ls; j++){
					if(j < ch_count) dp[i][j] = false;
					else{
						if(p[i] == s[j] || p[i] == '?') dp[i][j] = dp[i-1][j-1];
						else dp[i][j] = false;
					}
				}
				ch_count++;
			}
			else{
				for(int j = 1; j < ls; j++){
					if(ch_count == 0)
						dp[i][j] = true;
					else if(ch_count == 1){
						dp[i][j] = dp[i-1][j] || dp[i][j-1];
					}
					else{// if(ch_count > 1)
						if(j < ch_count-1) dp[i][j] = false;
						else if(j == ch_count-1) dp[i][j] = dp[i-1][j];
						else dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i-1][j-1];
					}
				}
			}
		}
		return dp[lp-1][ls-1];
    }
};



//version 1: pass only the smaller case
class Solution {
public:
	int starCouont(const char *str)
	{
		int count = 0;
		while(*str)
		{
			if(*str == '*')
				count++;
			str++;
		}
		return count;
	}
	bool isMatch(const char *s, int sLen, const char *p, int pLen, int nStar)
	{
		/*printf("-------------------");

		printf("\n");
		for(int i = 0; i < sLen; i++)
			printf("%c", s[i]);
		printf("\n");
		for(int i = 0; i < pLen; i++)
			printf("%c", p[i]);
		printf("\n");*/
		if(sLen < pLen - nStar)
			return false;

		if(pLen == 0)
		{
			if(sLen != 0)
				return false;
			else
				return true;
		}
		else if(sLen == 0)
		{
			if(pLen != nStar)
				return false;
			else
				return true;
		}
		else if(pLen == nStar)
			return true;
		else if(nStar == 0 && sLen != pLen - nStar)
			return false;
		else
		{
			if(*p != '*' || *(p+pLen-1) != '*')
			{
				while(*p && *p != '*')
				{
					if(*p == *s || *p == '?')
					{
						p++;
						pLen--;
						s++;
						sLen--;
					}
					else
						return false;
				}

				if(pLen > 0 && sLen > 0)
				{
					const char *pEnd = p+pLen-1;
					const char *sEnd = s+sLen-1;
					while(pEnd != p && *pEnd != '*')
					{
						if(*pEnd == *sEnd || *pEnd == '?')
						{
							pEnd--;
							pLen--;
							sEnd--;
							sLen--;
						}
						else
							return false;
					}
				}
				return isMatch(s, sLen, p, pLen, nStar);
			}
			else if(*p == '*')
			{
				while(*p && *p == '*')
				{
					p++;
					nStar--;
					pLen--;
				}

				while(sLen > 0)
				{
					if(isMatch(s, sLen, p, pLen, nStar))
						return true;
					else
					{
						s++;
						sLen--;
					}
				}
				return false;
			}
		}
	}

	bool isMatch(const char *s, const char *p) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int sLen = strlen(s);
		int pLen = strlen(p);
		int nStar = starCouont(p);
		return isMatch(s, sLen, p, pLen, nStar);
	}
};