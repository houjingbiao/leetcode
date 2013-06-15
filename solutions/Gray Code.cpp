class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if(n == 0)
        {
            ret.push_back(0);
            return ret;
        }
            
        int num = 0;
        ret.push_back(num);
        int count = 1 << n;
        for(int i = 0; i < count-1; i++)
        {
            int mask = 1;
            while((i & mask) != 0)
            {
                mask = mask << 1;
            }
            num = (num^mask);
            ret.push_back(num);
        }
        return ret;
    }
};