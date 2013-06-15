class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(divisor == 1) return dividend;
        if(dividend == divisor) return 1;
        if(divisor == -2147483648 && dividend > divisor) return 0;
        
        int remain = 0;
        if(dividend == -2147483648)
        {
            dividend = -2147483647;
            remain = -1;
        }

        int sign = 1;
        if(dividend < 0)
        {
            sign = ~(sign)+1;
            dividend = ~(dividend) + 1;
        }
        if(divisor < 0)
        {
            sign = ~(sign)+1;
            divisor = ~(divisor) + 1;
        }
        int ret = 1;
        if(dividend < divisor)
            ret = 0;
        else if(dividend == divisor)
            ret = 1;
        else
        {
            ret = 0;
            while(dividend > divisor)
            {
                int i = 0;
                int newdivisor = divisor;
                while(1)
                {
					if(i == 0)
						i = 1;
					else
						i = i << 1;
					if((newdivisor<<1) > 0 && dividend >= (newdivisor<<1))
						newdivisor = newdivisor << 1;
					else 
						break;
                }
                dividend -= newdivisor;
                ret += i;
                if(dividend < 1073741824 && remain == -1)
                {
                    dividend += 1;
                    remain = 0;
                }
            }
        }
        if(sign == -1)
            ret = ~(ret)+1;
        return ret;
    }
};