class Solution {
public:
    bool isDigit(char ch)
    {
        if(ch >= '0' && ch <= '9')
            return true;
        return false;
    }
    bool isCharacter(char ch)
    {
        if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
            return true;
        return false;
    }
	bool isEqual(char ch1, char ch2)
	{
		if(isDigit(ch1) || isDigit(ch2))
			return ch1 == ch2;
		else
			return ch1 == ch2 || ch1 - 'a' == ch2 - 'A' || ch1 - 'A' == ch2 - 'a';
	}
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.length() <= 1)
            return true;
        int i = 0, j = s.length()-1;
        while(i < j)
        {
            if(!isDigit(s[i]) && !isCharacter(s[i]))
                i++;
            else if(!isDigit(s[j]) && !isCharacter(s[j]))
                j--;
            else if(isEqual(s[i], s[j]))
                i++,j--;
            else
                return false;
        }
        return true;
    }
};