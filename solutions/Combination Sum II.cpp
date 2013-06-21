class Solution {
public:
    bool isContained(vector<int> &ret, vector<vector<int>> &rets)
    {
        if(rets.size() == 0)
            return false;
        for(int i = 0; i < rets.size(); i++)
        {
            if(ret.size() != rets[i].size())
                continue;
            int j = 0;
            for(; j < ret.size(); j++)
            {
                if(ret[j] != rets[i][j])
                    break;
            }
            if(j == ret.size())
                return true;
        }
        return false;
    }
    void dfs(int idx, int sum, int target, vector<int> &num, vector<int> &ret, vector<vector<int>> &rets)
    {
        sum += num[idx];
        ret.push_back(num[idx]);
        if(sum > target)
            return;
        if(sum == target)
        {
            if(!isContained(ret, rets))
                rets.push_back(ret);
            return;
        }
        
        for(int i = idx+1; i < num.size(); i++)
        {
            dfs(i, sum, target, num, ret, rets);
            ret.pop_back();
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> rets;
        if(num.size() == 0)
            return rets;
        sort(num.begin(), num.end());
        
        for(int i = 0; i < num.size(); i++)
        {
            vector<int> ret;
            int sum = 0;
            dfs(i, sum, target, num, ret, rets);
        }
        return rets;
        
    }
};