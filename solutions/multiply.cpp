class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num1.length() == 0 || num2.length() == 0)
            return string('0');
        string ret;
        for(int i = 0; i < num1; i++)
        {
            int up = 0;
            string temp('0', num2.length());
            int j = 0;
            for(; j < num2; j++)
            {
                up = up + (num1[num1.length()-1-i]-'0')*(num2[num2.length()-1-j]-'0');
                temp[i+j] = up%10 + '0';
                up /= 10;
            }
            if(up)
                temp.insert(temp.begin(), up + '0');
            if(i == 0)
                ret = temp;
            else
            {
                int up2 = 0;
                for(int i = 0; i < temp.length())
            }
        }
        return ret;        
    }
};