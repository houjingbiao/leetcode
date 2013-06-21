class Solution {
public:
    void dfs(int idx, int n, vector<int> &ret, int k, vector<vector<int>> &rets)
    {
        ret.push_back(idx);
        if(ret.size() == k)
        {
            rets.push_back(ret);
            return;
        }
        for(int i = idx+1; i <= n; i++)
        {
            dfs(i, n, ret, k, rets);
            ret.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> rets;
        if(n < k)
            return rets;
        vector<int> ret;
        if(n == k)
        {
            for(int i = 1; i <= k; i++)
                ret.push_back(i);
            rets.push_back(ret);
            return rets;
        }
        for(int i = 1; i <= n; i++)
        {
            ret.clear();
            dfs(i, n, ret, k, rets);
        }
        return rets;
        
        
    }
};