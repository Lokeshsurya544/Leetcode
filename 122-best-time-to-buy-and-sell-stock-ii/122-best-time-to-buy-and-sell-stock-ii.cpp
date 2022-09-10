class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int max_profit=0;
        for (int i=1;i<prices.size();i++){
            if (prices[i]>prices[i-1]){
                max_profit+=prices[i]-mini;
                mini=prices[i];
            }
            if (prices[i]<mini)
                mini=prices[i];
        }
        return max_profit;
    }
};