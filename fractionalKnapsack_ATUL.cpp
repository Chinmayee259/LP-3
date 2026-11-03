#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Knapsack
{
public:
    void solve()
    {
        vector<int> weight = {10, 20, 30};
        vector<int> profit = {60, 100, 120};

        int n = 3;
        int capacity = 50;

        float ratio[3];

        // Calculate profit/weight ratio
        for(int i = 0; i < n; i++)
        {
            ratio[i] = (float)profit[i] / weight[i];
        }

        // Sort items according to ratio
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(ratio[i] < ratio[j])
                {
                    swap(ratio[i], ratio[j]);
                    swap(weight[i], weight[j]);
                    swap(profit[i], profit[j]);
                }
            }
        }

        float totalProfit = 0;

        // Fill the knapsack
        for(int i = 0; i < n; i++)
        {
            if(capacity >= weight[i])
            {
                totalProfit += profit[i];
                capacity -= weight[i];
            }
            else
            {
                totalProfit += ratio[i] * capacity;
                capacity = 0;
                break;
            }
        }

        cout << "Maximum Profit: " << totalProfit;
    }
};

int main()
{
    Knapsack obj;
    obj.solve();

    return 0;
}
  ani fractional napsack cha haa code kartoy me ..
