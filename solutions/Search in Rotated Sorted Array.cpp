class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(target < A[0] && target > A[n-1])
            return -1;
        if(n == 1)
        {
            if(A[0] == target)
                return 0;
            else
                return -1;
        }
        
        int start = 0;
        int end = n-1;
        while(start < end)
        {
            int mid = 0;
            mid = start/2 + end/2;
            if(target == A[start])
                return start;
            else if(target == A[end])
                return end;
            else if(target == A[mid])
                return mid;
            else if(target > A[start])
            {
                if(A[start] <= A[mid])
                {
                    if(target <= A[mid])
                        end = mid;
                    else
                        start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            else if(target < A[end])
            {
                if(A[end] <= A[mid])
                {
                    start = mid + 1;
                }
                else
                {
                    if(target > A[mid])
                        start = mid + 1;
                    else
                        end = mid;
                }
            }
            else
                return -1;
        }
        return -1;
    }
};