class Solution {
public:
	string multiply(string num1, string num2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(num1.length() == 0 || num2.length() == 0)
			return string("0");
		if(num1.length() == 1 && num1[0] == '0' || num2.length() == 1 && num2[0] == '0')
			return string("0");
		string ret;
		for(int i = 0; i < num1.length(); i++)
		{
			int up = 0;
			string temp;
			int j = 0;
			for(; j < num2.length(); j++)
			{
				up = up + (num1[num1.length()-1-i]-'0')*(num2[num2.length()-1-j]-'0');
				temp.insert(temp.begin(), up%10 + '0');
				up /= 10;
			}
			if(up)
				temp.insert(temp.begin(), up + '0');
			if(i == 0)
				ret = temp;
			else
			{
				up = 0;
				for(int k = 0; k < temp.length(); k++)
				{
					int idx = ret.length()-1-i-k;
					up = up + temp[temp.length()-1-k] - '0' + ((idx >= 0)? ret[idx]-'0' : 0);
					if(idx >= 0)
						ret[idx] = up%10 + '0';
					else
						ret.insert(ret.begin(), up%10 + '0');
					up /= 10;
				}
				if(up)
					ret.insert(ret.begin(), up + '0');
			}
		}
		return ret;        
	}
};