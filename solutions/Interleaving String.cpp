class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(s1.length() + s2.length() != s3.length())
            return false;
        
        vector<vector<bool>> match(s1.length()+1, vector<bool>(s2.length()+1, false));
        match[0][0] = true;
        for(int i1 = 1; i1 <= s1.length(); i1++)
        {
            char ch1 = s1[i1-1];
            char ch3 = s3[i1-1];
            if(ch1 == ch3)
                match[i1][0] = true;
            else
                break;
        }
        
        for(int i2 = 1; i2 <= s2.length(); i2++)
        {
            char ch2 = s2[i2-1];
            char ch3 = s3[i2-1];
            if(ch2 == ch3)
                match[0][i2] = true;
            else
                break;
        }
        
        for(int i1 = 1; i1 <= s1.length(); i1++)
        {
             for(int i2 = 1; i2 <= s2.length(); i2++)
             {
                char ch1 = s1[i1-1];
                char ch2 = s2[i2-1];
                char ch3 = s3[i1+i2-1];
                match[i1][i2] = (ch1 == ch3 && match[i1-1][i2]) || (ch2 == ch3 && match[i1][i2-1]);
             }
        }
        return match[s1.length()][s2.length()];
        
        
    }
};