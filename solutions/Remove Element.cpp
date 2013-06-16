class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0)
            return 0;
        int p = 0;
        while(p < n && A[p] != elem)
            p++;
        if(p == n)
            return n;
        int q = p+1;
        while(q < n)
        {
            if(A[q] != elem)
            {
                A[p] = A[q];
                p++;
            }
            q++;
        }
        return p;
    }
};