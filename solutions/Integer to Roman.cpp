class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int base = 10;
        int i = 0;
        string ret;
        while(num && i < 4)
        {
            i++;
            int remain = num%10;
            switch(i)
            {
                case 1:
                {
                    if(remain == 1)
                        ret = "I" + ret;
                    else if(remain == 2)
                        ret = "II" + ret;
                    else if(remain == 3)
                        ret = "III" + ret;
                    else if(remain == 4)
                        ret = "IV" + ret;
                    else if(remain == 5)
                        ret = "V" + ret;
                    else if(remain == 6)
                        ret = "VI" + ret;
                    else if(remain == 7)
                        ret = "VII" + ret;
                    else if(remain == 8)
                        ret = "VIII" + ret;
                    else if(remain == 9)
                        ret = "IX" + ret;
                }
                break;
                case 2:
                {
                    if(remain == 1)
                        ret = "X" + ret;
                    else if(remain == 2)
                        ret = "XX" + ret;
                    else if(remain == 3)
                        ret = "XXX" + ret;
                    else if(remain == 4)
                        ret = "XL" + ret;
                    else if(remain == 5)
                        ret = "L" + ret;
                    else if(remain == 6)
                        ret = "LX" + ret;
                    else if(remain == 7)
                        ret = "LXX" + ret;
                    else if(remain == 8)
                        ret = "LXXX" + ret;
                    else if(remain == 9)
                        ret = "XC" + ret;
                }
                break;
                case 3:
                {
                    if(remain == 1)
                        ret = "C" + ret;
                    else if(remain == 2)
                        ret = "CC" + ret;
                    else if(remain == 3)
                        ret = "CCC" + ret;
                    else if(remain == 4)
                        ret = "CD" + ret;
                    else if(remain == 5)
                        ret = "D" + ret;
                    else if(remain == 6)
                        ret = "DC" + ret;
                    else if(remain == 7)
                        ret = "DCC" + ret;
                    else if(remain == 8)
                        ret = "DCCC" + ret;
                    else if(remain == 9)
                        ret = "CM" + ret;
                }
                break;
                case 4:
                {
                    if(remain == 1)
                        ret = "M" + ret;
                    else if(remain == 2)
                        ret = "MM" + ret;
                    else if(remain == 3)
                        ret = "MMM" + ret;
                    /*else if(remain == 4)
                        ret = "CD" + ret;
                    else if(remain == 5)
                        ret = "D" + ret;
                    else if(remain == 6)
                        ret = "DC" + ret;
                    else if(remain == 7)
                        ret = "DCC" + ret;
                    else if(remain == 8)
                        ret = "DCCC" + ret;
                    else if(remain == 9)
                        ret = "CM" + ret;*/
                }

                break;
                default:
                break;
            }
            num = num/10;
        }
        return ret;
    }
};