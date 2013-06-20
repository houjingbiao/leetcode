class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.size() <= 1)
            return 0;
        int ret = 0;
        int min = 0;
        for(int i = 0; i < prices.size(); i++)
        {    
            if(i == 0)
            {
                if(prices[i] <= prices[i+1])
                    min = prices[i];
            }
            else if(i > 0 && i < prices.size()-1)
            {
                if(prices[i] > prices[i-1] && prices[i] >= prices[i+1])
                    ret += prices[i] - min;
                else if(prices[i] <= prices[i-1] && prices[i] < prices[i+1])
                    min = prices[i];
            }
            else
            {
                if(prices[i] > prices[i-1])
                    ret += prices[i] - min;
            }
        }
        return ret;
    }
};