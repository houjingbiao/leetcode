class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0)
            return 1;
        bool *mark = new bool[n+1];
        memset(mark, false, n+1);
        for(int i = 0; i < n; i++)
        {
            if(A[i] > 0 && A[i] <= n)
                mark[A[i]] = true;
        }
        int i = 1;
        for(; i < n+1; i++)
            if(!mark[i])
                break;
        return i;
    }
};