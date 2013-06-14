class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //int len = strlen(str);
        //if(len <= 0);
        //    return 0;
        int sign = 1;
        int num = 0;
        const char* p = str;
        while(*p == ' ')
            p++;
            
        bool isNumber = false;
        bool hasSign = false;
        while(*p)
        {
            if(*p == '-')
            {
                if(isNumber||hasSign)
                    return 0;
                else
                {
                    sign = -1;
                    isNumber = true;
                    hasSign = true;
                }
            }
            else if(*p == '+')
            {
                if(isNumber||hasSign)
                    return 0;
                else
                {
                    sign = 1;
                    isNumber = true;
                    hasSign = true;
                }
            }
            else if(*p >= '0' && *p <= '9')
            {
                if((INT_MAX/10) < num)
                {
                    if(sign == 1) 
                        return INT_MAX;
                    else
                        return INT_MIN;
                }
                if(sign == 1 && INT_MAX - num*10 < (*p - '0'))
                    return INT_MAX;
                if(sign == -1 && num*10*sign - INT_MIN < (*p - '0') && num != 0)
                    return INT_MIN;
                    
                num = num*10 + (*p - '0');
                isNumber = true;
                hasSign = true;
            }
            else if(isNumber)
                break;
            else
                return 0;
            p++;
        }
            
        return sign*num;
    }
};