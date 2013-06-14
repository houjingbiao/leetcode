class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(nRows <= 1) return s;
        vector<string> vecStrs(nRows);
        int vecIdx = 0;
        bool isAdd = true;
        for(int i = 0; i < s.length(); i++)
        {
            vecStrs[vecIdx].append(1, s[i]);
            if(vecIdx == 0)
                isAdd = true;
            else if(vecIdx == nRows-1)
                isAdd = false;
            vecIdx = isAdd?vecIdx +1:vecIdx -1;
        }
        string ret = vecStrs[0];
        for(int i = 1; i < nRows; i++)
        {
            ret += vecStrs[i];
        }
        return ret;
    }
};