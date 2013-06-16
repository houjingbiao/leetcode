class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(a.empty())
            return b;
        else if(b.empty())
            return a;
            
        int len = a.length() >= b.length() ? a.length() : b.length();

        string ret;
        int up = 0;
        for(int i = 0; i < len; i++)
        {
            int m = a.length() - 1 - i;
            int n = b.length() - 1 - i;
            up = up 
                + (m >= 0 ? (a[m] - '0') : 0)
                + (n >= 0 ? (b[n] - '0') : 0);
            switch(up)
            {
                case 0:
                    ret = "0" + ret;
                    up = 0;
                    break;
                case 1:
                    ret = "1" + ret;
                    up = 0;
                    break;
                case 2:
                    ret = "0" + ret;
                    up = 1;
                    break;
                case 3:
                    ret = "1" + ret;;
                    up = 1;
                    break;
                default:
                    break;
            }
        }
        if(up == 1)
            ret = "1" + ret;

        return ret;
        
    }
};