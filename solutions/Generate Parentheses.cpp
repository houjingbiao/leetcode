class Solution {
public:
    void dfs(char ch, string &str, int leftPrtCount, vector<string> &ret, int n)
    {
        str.push_back(ch);
        if(ch == '(')
        {
            leftPrtCount++;
        }
        else
        {
            leftPrtCount--;
            n--;
        }
        
        if(n == 0)
        {
            ret.push_back(str);
            return;
        }
        if(leftPrtCount > 0)
        {
            dfs(')', str, leftPrtCount, ret, n);
            str.pop_back();
        }
        if(n > leftPrtCount)
        {
            dfs('(', str, leftPrtCount, ret, n);
            str.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<string> ret;
        string str;
        if(n == 0)
        {
            ret.push_back(str);
            return ret;
        }
        
        str.push_back('(');
        int leftPrtCount = 1;
        if(leftPrtCount > 0)
        {
            dfs(')', str, leftPrtCount, ret, n);
            str.pop_back();
        }
        if(n > leftPrtCount)
        {
            dfs('(', str, leftPrtCount, ret, n);
                str.pop_back();
        }
        return ret;
        
    }
};