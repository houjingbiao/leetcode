class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.size() == 0 || prices.size() == 1)
            return 0;
            
        vector<int> minn(prices.size(), prices[0]);
        vector<int> maxn(prices.size(), prices[prices.size()-1]);
        for(int i = 0; i < prices.size(); i++)
        {
            if(i > 0)
            {
                if(prices[i] < minn[i-1])
                    minn[i] = prices[i];
                else
                    minn[i] = minn[i-1];
            }
            if(i < prices.size()-1)
            {
                if(prices[i] > maxn[i+1])
                    maxn[i] = prices[i];
                else
                    maxn[i] = maxn[i+1];
            }
        }
        int ret = 0;
        for(int i = 0; i < prices.size(); i++)
            if(ret < maxn[i] - minn[i])
                ret = maxn[i] - minn[i];
        return ret;
    }
};