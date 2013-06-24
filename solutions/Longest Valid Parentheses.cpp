class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.length() < 2)
            return 0;
        vector<bool> marks(s.size(), false);
        stack<int> mystack;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(')
            {
                mystack.push(i);
            }
            else
            {
                if(!mystack.empty())
                {
                    marks[mystack.top()] = true;
                    marks[i] = true;
                    mystack.pop();
                }
            }
        }
        int ret = 0;
        int count = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(marks[i])
                count++;
            else
            {
                ret = max(ret, count);
                count = 0;
            }
        }
        return max(ret, count);
    }
};