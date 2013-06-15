class Solution {
public:
    bool _isNumber(const char *start, const char *end)
    {
        if(*start == '+' || *start == '-')
            start++;
        if(start == end)
            return false;

        if(*start == '.' && end == start+1)
            return false;

        int pointCount = 0;
        while(start != end)
        {
            if(*start == '.')
                pointCount++;
            else if(*start > '9' || *start < '0')
                return false;
            if(pointCount > 1)
                return false;
            start++;
        }
        return true;
    }
    bool _isPower(const char *start, const char *end)
    {
        if(*start == '+' || *start == '-')
            start++;
        if(start == end)
            return false;

        while(start != end)
        {
            if(*start > '9' || *start < '0')
                return false;
            start++;
        }
        return true;
    }
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while(*s == ' ')
            s++;
        const char* pEnd = s;
        while(*pEnd)
            pEnd++;
        while(pEnd > s && *(pEnd-1) == ' ')
            pEnd--;
        if(s >= pEnd)
            return false;
            
        const char *p = s;
        if(*p == '+' || *p == '-')
            p++;
        if(p == pEnd)
            return false;
        
        while(p < pEnd)
        {
            if(*p == 'e')
            {
                if(_isNumber(s, p) && _isPower(p+1, pEnd))
                    return true;
                else
                    return false;
            }
            else if(*p != '.' && (*p < '0' || *p > '9'))
                    return false;
            
            p++;
        }
        if(p == pEnd && _isNumber(s, pEnd))
            return true;
        return false;
    }
};