class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) return 1;
        if(x == 0) return 0;
        
        if(x == 1.0) return 1.0;
        if(n == 1) return x;
        if(x == -1.0)
        {
            if(n%2)
                return -1.0;
            else
                return 1.0;
        }
        int remain = 0;
        if(n == -2147483648)
        {
            n == 2147483647;
            remain = -1;
        }
        
        if(n < 0)
        { 
            x = 1/x;
            n = -1*n;
        }
        double ret = 1;
        double power = x;
        while(n)
        {
            if(n%2)
                ret *= power;
            power *= power;
            n = n>>1;
        }
        if(remain == -1)
            ret = ret*x;
        return ret;
    }
};