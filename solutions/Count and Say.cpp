class Solution {
public:
    string itoa(int num)
    {
        if(num <= 0)
            return "";
        else
        {
            string ret;
            while(num)
            {
                char ch = (num%10) + '0';
                ret = ch + ret;
                num /= 10;
            }
			return ret;
        }
    }
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		string ret = "1";
		if(n == 1)
			return "1";
        
        for(int i = 2; i <= n; i++)
        {
            string str = ret;
            ret.clear();
            int count = 1;
            char ch = str[0];
            for(int j = 1; j < str.length(); j++)
            {
                if(str[j] != ch)
                {
                    ret += itoa(count);
                    ret += ch;
                    ch = str[j];
                    count = 1;
                }
                else
                    count++;
            }
			ret += itoa(count);
            ret += ch;
        }
        return ret;
    }
};