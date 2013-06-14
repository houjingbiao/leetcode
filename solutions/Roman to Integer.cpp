class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.empty()) return 0;
        int ret = 0;
        int i = 0;
        for(; i < s.length(); i++)
        {
            if(s[i] == 'I')
            {
                ret += 1;
                //break;
            }
            else if(s[i] == 'V'||s[i] == 'X')
            {
                ret += 5;
                if(s[i] == 'X')
                    ret += 5;
                if(i - 1 >= 0 && s[i-1] == 'I')
                    ret -= 2;
            }
            else if(s[i] == 'L'||s[i] == 'C')
            {
                ret += 50;
                if(s[i] == 'C')
                    ret += 50;
                if(i - 1 >= 0 && s[i-1] == 'X')
                    ret -= 20;
            }
            else if(s[i] == 'D'||s[i] == 'M')
            {
                ret += 500;
                if(s[i] == 'M')
                    ret += 500;
                if(i - 1 >= 0 && s[i-1] == 'C')
                    ret -= 200;
            }
            else
                break;
        }
        return ret;
    }
};