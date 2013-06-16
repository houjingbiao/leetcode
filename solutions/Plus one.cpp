class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = digits.size()-1;
        for(; i >= 0; i--)
        {
            if(digits[i] < 9)
            {
                digits[i]++;
                break;
            }
            else   
                digits[i] = 0;
        }
        if(i < 0)
        {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
        
    }
};