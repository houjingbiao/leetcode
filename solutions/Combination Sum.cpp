class Solution {
public:
    void dfs(int idx, int sum, int target, vector<int> &candidates, vector<int> &ret, vector<vector<int>> &rets)
    {
        sum += candidates[idx];
        if(sum > target)
            return;
            
        ret.push_back(candidates[idx]);
        if(sum == target)
        {
            
            rets.push_back(ret);
            return;
        }
        
        for(int i = idx; i < candidates.size(); i++)
        {
            if(sum + candidates[i] > target)
                break;
            dfs(i, sum, target, candidates, ret, rets);
            ret.pop_back();
        }
            
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> rets;
        if(candidates.size() == 0)
            return rets;
        sort(candidates.begin(), candidates.end());
        if(candidates[0] > target)
            return rets;
        int i = 1;
        while(i < candidates.size())
        {
            if(candidates[i] == candidates[i-1])
                candidates.erase(candidates.begin()+i);
            else
                i++;
        }
        
        for(int i = 0; i < candidates.size(); i++)
        {
            vector<int> ret;
            int sum = 0;
            if(sum + candidates[i] > target)
                break;
            dfs(i, sum, target, candidates, ret, rets);
        }
        return rets;
    }
};