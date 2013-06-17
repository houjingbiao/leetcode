class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0 || n == 1)
            return n;
        int i = 0; 
        int j = 1; 
        while(j < n)
        {
            if(A[i] != A[j])
            {
                i++;
                A[i] = A[j];
            }
            j++;
        }
        return i+1;
    }
};