class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x < 0) 
            return -1;
        else if(x == 0|| x == 1)
            return x;
        else if(x >= 2147395600)
            return 46340;
        int start = 1;
        int end = x/2+1;
        if(end > 46340)
            end = 46340;
        while(1)
        {
            int i = (start + end)/2;
            int mult1 = i*i;
            int mult2 = mult1 + 2*i + 1;
            if(mult1 == x)
                return i;
            else if(mult2 == x)
                return i+1;
            else if(mult1 < x && mult2 > x)
                return i;
            else if(mult1 > x)
            {
                end = i;
            }
            else // mult2 < x
            {
                start = i+1;
            }
        }
        return -1;
    }
};