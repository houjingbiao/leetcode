class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = num.size()-1;
        for(; i >= 0; i--)
        {
            if(i == 0)
            {
                for(int m = i, n = num.size() - 1; m < n; m++, n--)
                {
                    int temp = num[m];
                    num[m] = num[n];
                    num[n] = temp;
                }
                break;
            }
            else if(num[i] > num[i - 1])
            {
                int j = num.size() - 1;
                for(; j > i-1; j--)
                {
                    if(num[j] > num[i-1])
                    {
                        int temp = num[j];
                        num[j] = num[i-1];
                        num[i-1] = temp;
                        for(int m = i, n = num.size() - 1; m < n; m++, n--)
                        {
                            int temp = num[m];
                            num[m] = num[n];
                            num[n] = temp;
                        }
                        break;
                    }
                }
                break;
            }
        }
        
    }
};