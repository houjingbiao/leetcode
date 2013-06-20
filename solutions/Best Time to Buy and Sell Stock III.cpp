class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.size() <= 1)
            return 0;
        
        vector<int> sellProfit(prices.size(), 0);
        vector<int> buyProfit(prices.size(), 0);
        
        int min = prices[0];
        int max = prices[prices.size()-1];
        for(int i = 0; i < prices.size(); i++)
        {
            if(min > prices[i])
                min = prices[i];
            
			if(i == 0)
				sellProfit[i] = 0;
			else
				sellProfit[i] = sellProfit[i-1] < prices[i] - min ? prices[i] - min : sellProfit[i-1] ;
            
            if(max < prices[prices.size() - 1 - i])
                max = prices[prices.size() - 1 - i];
			
			if(i == 0)
				buyProfit[prices.size() - 1 - i] = 0;
			else
				buyProfit[prices.size() - 1 - i] = buyProfit[prices.size() - 1 - i + 1] < max - prices[prices.size() - 1 - i]?max - prices[prices.size() - 1 - i]:buyProfit[prices.size() - 1 - i + 1];
        }

        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            int profit = 0;
            if(i == prices.size() - 1)
                profit = sellProfit[i];
            else if(i == 0)
                profit = buyProfit[i];
            else
                profit = sellProfit[i] + buyProfit[i+1];
            maxProfit = (maxProfit < profit)?profit : maxProfit;
        }
        return maxProfit;
    }
};