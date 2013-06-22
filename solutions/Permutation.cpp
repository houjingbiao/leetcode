class Solution {
public:
    void dfs(int idx, vector<int> &num, vector<int> &ret, vector<bool> &marks, vector<vector<int>> &rets)
    {
        ret.push_back(num[idx]);
        marks[idx] = true;
        if(ret.size() == num.size())
        {
            rets.push_back(ret);
            return;
        }
        for(int i = 0; i < num.size(); i++)
        {
            if(!marks[i])
            {
                dfs(i, num, ret, marks, rets);
                ret.pop_back();
                marks[i] = false;
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> rets;
        if(num.size() == 0)
            return rets;
        if(num.size() == 1)
        {
            rets.push_back(num);
            return rets;
        }
        
        vector<bool> marks(num.size(), false);
        for(int i = 0; i < num.size(); i++)
        {
            vector<int> ret;
            dfs(i, num, ret, marks, rets);
            ret.pop_back();
            marks[i] = false;
        }
        return rets;
    }
};