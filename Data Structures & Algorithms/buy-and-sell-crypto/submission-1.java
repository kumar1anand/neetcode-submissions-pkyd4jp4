class Solution {
    public int maxProfit(int[] prices) {
        int n=prices.length;
        //vector<int>suf(n,0);
        //int maxVal = INT_MIN;
        int profit = Integer.MIN_VALUE;
        int SoldPrice = Integer.MIN_VALUE;
        for(int i=n-2;i>=0;i--){
            SoldPrice = Math.max(SoldPrice,prices[i+1]);
            profit = Math.max(profit , (SoldPrice - prices[i]));
        }
        return profit < 0 ? 0: profit;
    }
}
