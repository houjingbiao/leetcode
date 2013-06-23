class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n < 3)
            return n;
        int i= 0;
        int j = 1;
        while(1)
        {
            int count = 1;
            while(j < n && A[i] == A[j])
            {
                count++;
                j++;
            }
            if(count >= 2)
            {
                i++;
                A[i] = A[i-1];
                i++;
                if(j < n)
                {
                    A[i] = A[j];
                    j++;
                }
                else
                    return i;
            }
            else
            {
                i++;
                if(j == n)
                {
                    return i;
                }
                else
                {
                    A[i] = A[j];
                    j++;
                }
            }
        }
        return i;
    }
};