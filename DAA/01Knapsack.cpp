#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int knapsack(int capacity, vector<int> weight, vector<int> profit, int n){
    // Create DP table, Rows represent items(from 0 items to n items), Columns represent knapsack capacity(0 capacity to capacity)
    vector<vector<int>> dp(n+1, vector<int>(capacity + 1, 0));

    // Consider items one by one
    for(int i = 1; i <= n; i++){

        // Check all possible capacities for that item
        for(int w = 1; w <= capacity; w++){

            // If current item can fit in the knapsack
            if(weight[i-1] <= w){
                // Choose maximum of: 1. Not including the current item , 2. Including the current item
                // For every item, we decide whether to include it or exclude it, and take whichever gives higher profit.
                dp[i][w] = max(dp[i-1][w], profit[i-1] + dp[i-1][w-weight[i-1]]);
            }

            // If current item cannot fit
            else{
                // Do not include the current item. Use previous result
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    // Return maximum profit
    return dp[n][capacity];
}

int main(){
    int n, capacity;
    cout << "Enter the number of items : ";
    cin >> n;

    // Create vectors to store weights and profits
    vector<int> weight(n);
    vector<int> profit(n);

    cout << "Enter weights of items : \n";
    for(int i = 0; i < n; i++){
        cin >> weight[i];
    }

    cout << "Enter profits of items : \n";
    for(int i = 0; i < n; i++){
        cin >> profit[i];
    }

    cout << "Enter knapsack capacity : ";
    cin >> capacity;

    int maxProfit = knapsack(capacity, weight, profit, n);

    cout <<"Maaximum Profit = " << maxProfit;

    return 0;

}

// Compilation
// g++ 01Knapsack.cpp -o 01Knapsack 

// Run
// 01Knapsack

// TC - O(n * w)
// n - no of items, w - Knapsack capacity
// n * w - filling dp table

// SC - O(n * w)