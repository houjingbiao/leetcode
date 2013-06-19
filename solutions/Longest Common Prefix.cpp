class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret;
        if(strs.size() == 0)
            return ret;
        else if(strs.size() == 1)
            return strs[0];
        sort(strs.begin(), strs.end());
        int len = min(strs[0].length(), strs[strs.size()-1].length());
        if(len == 0)
            return ret;
        int i = 0;
        while(i < len && strs[0][i] == strs[strs.size()-1][i])
        {
            ret += strs[0][i];
            i++;
        }
        return ret;
    }
};