// Brute force takes O(n^2) time
// SC=O(1)

int bestTimeToBuyAndSellStock(vector<int>&prices) {
  // checking for every possible combination and stores max profit in maxProfit which is later returned
  // if starting from day 1 then check selling at day 2,day 3,day 4,day 5....
  // else if starting from day 2 then check selling at day 3,day 4..
  // else if starting from day 3 then check selling at day 4,day 5..
    int maxProfit=0;   
    for(int i=0;i<prices.size()-1;i++)
    {
        for(int j=i+1;j<prices.size();j++)
        {
            if(prices[j]>prices[i])
            {
                int profit=prices[j]-prices[i];
               maxProfit=max(maxProfit,profit);
            }
        }
    }
    return maxProfit;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Optimal solution
// TC=O(n), SC=O(1)
int bestTimeToBuyAndSellStock(vector<int>& prices) {
  int maxProfit = 0;
  int curr = 1, mini = 0;

  while (curr != prices.size()) {
    // we know that if the curr price > min price there is profit
    if (prices[curr] > prices[mini]) {
      // so if curr price > min price cal profit and check if it is max profit
      // using max(maxprofit,profit)
      int profit = prices[curr] - prices[mini];
      maxProfit = max(profit, maxProfit);
      // increment curr to find if profit greater than curr exists
      curr++;
    }

    else {
      // else then it means there is a point at which the price is lower than
      // that of min, move min to curr and increment curr to again compute if
      // there is a possibility
      mini = curr;
      curr++;
    }
  }
  // At last the maxProfit will have the maximum profit accumilated return it.
  return maxProfit;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
