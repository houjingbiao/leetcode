class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0 || n == 1)
            return 1;
        
        int ret = 0;
        for(int i = 1; i <= n; i++)
        {
            ret += numTrees(i - 1) * numTrees(n - i);
        }
        return ret;
    }
};