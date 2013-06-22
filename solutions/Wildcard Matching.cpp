//a version that pass only the smaller case

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