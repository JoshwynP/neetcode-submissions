class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
        {
            return 0;
        }
        
        int min = 0;
        int max = 0;
        int profit = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < prices[min] && i != prices.size()-1)
            {
                min = i;
                cout << "min: " << prices[min] << endl;
            }
            if (prices[i] > prices[max] || max < min)
            {
                // if (prices[max]-prices[min] > prices[i])
                max = i;
                cout << "max: " << prices[max] << endl;
            }
            if (prices[max]-prices[min] > profit)
            {
                profit = prices[max]-prices[min];
            }
            
        }

        return profit;
    }
};
