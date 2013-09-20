//version 2: get the ith gray code from only i
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        int count = 1 << n;
        for(int i = 0; i < count; i++)
            ret.push_back(i^(i>>1));
        return ret;
    }
};

//version 1: to get the (i+1)th gray code from the ith gray code and i, its drawback is that it have to be start from the first gray code
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        int gray = 0;
        ret.push_back(gray);
        int count = 1 << n;
        for(int i = 1; i < count; i++) {
            int mask = 1;
            while(((i-1) & mask) != 0)
                mask = mask << 1;
            gray = gray^mask;
            ret.push_back(gray);
        }
        return ret;
    }
};