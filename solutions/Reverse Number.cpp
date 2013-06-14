class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sign = x>=0?1:-1;
        x = sign*x;
        int newX = 0;
        while(x)
        {
            newX = newX*10 + x%10;
            x /= 10; 
        }
        return newX*sign;
    }
};