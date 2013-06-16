class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a = m-1;
        int b = n-1;
        int i = m+n-1;
        for(; i >= 0 && a >= 0 && b >= 0; i--)
        {
            if(A[a] > B[b])
            {
                A[i] = A[a];
                a--;
            }
            else //if(A[a] )
            {
                A[i] = B[b];
                b--;
            }
        }
        if(a == -1 && b == -1)
        {
            return;
        }
        else if(a == -1)
        {
            for(int j = 0; j <= b; j++)
                A[j] = B[j];
        }
    }
};