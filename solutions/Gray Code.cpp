//version 4: from liancheng :
class Solution {
public:
    vector<int> grayCode (int n)
    {
        vector<int> codes (1, 0);

        for (int i = 0; i < n; ++i)
            for (int j = (1 << i) - 1; j >= 0; --j)
                codes.push_back (codes [j] + (1 << i));

        return move (codes);
    }
};

//version 3: get the ith gray code from only i
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

//version 2:
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret(1, 0);
        int count = 1 << n;
        for(int i = 1; i < count; i++) {
            int mask = (i^i-1)+1>>1;//get the mask using bit operator, and the number operator is prior to bit operation
            int gray = ret[ret.size()-1]^mask;
            ret.push_back(gray);
        }
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