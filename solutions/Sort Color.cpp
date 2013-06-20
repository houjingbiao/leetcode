class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int colorCounts[3];
        memset(colorCounts, 0, sizeof(int)*3);
        
        for(int i = 0; i < n; i++)
            colorCounts[A[i]]++;
            
        for(int i = 0; i < n; i++)
        {
            if(i < colorCounts[0])
                A[i] = 0;
            else if(i < colorCounts[0] + colorCounts[1])
                A[i] = 1;
            else //if(i < colorCounts[0])
                A[i] = 2;
        }
    }
};