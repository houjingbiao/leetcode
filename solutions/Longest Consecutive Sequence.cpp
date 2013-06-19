class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        
        int maxLen = 1;
        vector<int> lengths(num.size(), 1);
        for(int i = num.size()-2; i >= 0; i--)
        {
            if(num[i] == num[i+1]-1)
            {
                lengths[i] = lengths[i+1]+1;
                if(maxLen < lengths[i])
                    maxLen = lengths[i];
            }
            else if(num[i] == num[i+1])
            {
                lengths[i] = lengths[i+1];
            }
        }
        return maxLen;
    }
};