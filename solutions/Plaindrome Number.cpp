class Solution {
public:
    bool isPlainVector(vector<int> vec)
    {
        for(int i = 0, j = vec.size() - 1; i < j; i++, j--)
        {
            if(vec[i] != vec[j])
                return false;
        }
        return true;
    }
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x < 0) return false;
        if(x == 0) return true;
        
        vector<int> vecInt;
        int i = 0;
        while(x)
        {
            vecInt.push_back(x%10);
            x = x/10;
            i++;
        }
        if(i == 1) return true;
        return isPlainVector(vecInt);        
    }
};