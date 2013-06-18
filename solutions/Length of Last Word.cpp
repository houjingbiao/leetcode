class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s == NULL)
            return 0;
        int len = 0;
        while(s[len])
            len++;

        int i = len-1;
        while(i >= 0 && s[i] == ' ')
            i--;
        int end = i;
        while(i >= 0 && s[i] != ' ')
            i--; 
        return end-i;
        
    }
};