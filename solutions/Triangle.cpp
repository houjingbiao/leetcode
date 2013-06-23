class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(triangle.size() == 0)
            return 0;
        else if(triangle.size() == 1)
            return triangle[0][0];
        int level = 1;
        while(level < triangle.size())
        {
            triangle[level][0] += triangle[level-1][0];
            for(int i = 1; i < level; i++)
                triangle[level][i] += min(triangle[level-1][i-1], triangle[level-1][i]);
            triangle[level][level] += triangle[level-1][level-1];
            level++;
        }
        int ret = 100000;
        for(int i = 0; i < level; i++)
        {
            ret = min(ret, triangle[level-1][i]);
        }
        return ret;
    }
};