class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret(2, -1);
        if(n == 0 || target < A[0] || target > A[n-1])
            return ret;
        int start =0; 
        int end = n - 1;
        while(start < end)
        {
            int mid = start/2 + end/2;
            if(target <= A[mid])
                end = mid;
            else
                start = mid + 1;
        }
        
        if(A[end] == target)
        {
            int i = end;
            while(i >= 0 && target == A[i])
                i--;
            ret[0] = i+1;
            i = end;
            while(i < n && target == A[i])
                i++;
            ret[1] = i-1;
        }
        return ret;
    }
};