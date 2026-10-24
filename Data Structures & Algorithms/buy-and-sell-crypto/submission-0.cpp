class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        //vector<int>suf(n,0);
        //int maxVal = INT_MIN;
        int profit = INT_MIN;
        int SoldPrice = INT_MIN;
        for(int i=n-2;i>=0;i--){
            SoldPrice = max(SoldPrice,prices[i+1]);
            profit = max(profit , (SoldPrice - prices[i]));
        }
        return profit < 0 ? 0: profit;
    }
};
