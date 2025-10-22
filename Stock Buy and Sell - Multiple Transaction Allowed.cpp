#include <iostream>
#include <vector>
using namespace std;

int maxProfitExpected(const vector<int> &prices)
{
    int res = 0;

    // Keep on adding the difference between
    // adjacent when the prices a
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
            res += prices[i] - prices[i - 1];
    }

    return res;
}

int maxProfitBetter(vector<int> &prices)
{
    int n = prices.size();

    // Local Minima
    int lMin = prices[0];

    // Local Maxima
    int lMax = prices[0];
    int res = 0;

    int i = 0;
    while (i < n - 1)
    {

        // Find local minima
        while (i < n - 1 && prices[i] >= prices[i + 1])
        {
            i++;
        }
        lMin = prices[i];

        // Local Maxima
        while (i < n - 1 && prices[i] <= prices[i + 1])
        {
            i++;
        }
        lMax = prices[i];

        // Add current profit
        res = res + (lMax - lMin);
    }

    return res;
}

// Recursive function to find max profit
int maxProfitRec(vector<int> &price, int start, int end)
{
    int res = 0;

    // Try every possible pair of buy (i) and sell (j)
    for (int i = start; i < end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {

            // Valid transaction if selling price > buying price
            if (price[j] > price[i])
            {

                // Current profit + profit from left and right parts
                int curr = (price[j] - price[i]) +
                           maxProfitRec(price, start, i - 1) +
                           maxProfitRec(price, j + 1, end);
                res = max(res, curr);
            }
        }
    }
    return res;
}

int maxProfit(vector<int> &prices)
{
    return maxProfitRec(prices, 0, prices.size() - 1);
}

int main()
{
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
    cout << maxProfit(prices) << endl;
    cout << maxProfitBetter(prices) << endl;
    cout << maxProfitExpected(prices) << endl;
    return 0;
}