class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> mystack;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(mystack.empty())
                mystack.push(s[i]);
            else if(mystack.top() == '{' && s[i] == '}' 
                || mystack.top() == '[' && s[i] == ']' 
                || mystack.top() == '(' && s[i] == ')' )
                mystack.pop();
            else
                mystack.push(s[i]);
        }
        if(mystack.empty())
            return true;
        return false;
        
    }
};