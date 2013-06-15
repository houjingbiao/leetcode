class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = strlen(needle);
        int len2 = strlen(haystack);
        int len = len2 - len1;
        if(len == 0 && len1 == 0)
            return haystack;
        for(int i = 0; i <= len; i++)
        {
            int j = 0;
            for(; j < len1; j++)
            {
                if( *(haystack+i+j) != *(needle+j))
                    break;
            }
            if(j == len1)
                return haystack+i;
        }
        return NULL;
        
    }
};