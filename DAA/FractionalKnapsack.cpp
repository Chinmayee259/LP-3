#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Item{
    public:
        int weight;
        int profit;
        double ratio;
};

bool compare(Item a, Item b){
    return a.ratio > b.ratio;
}

// Function to solve fractional knapsack
double fractionalKnapsack(vector<Item>& items, double capacity){
    // Calculate profit/weight ratio
    for(int i = 0; i < items.size(); i++){
        items[i].ratio = (double)items[i].profit/items[i].weight;
    }

    // Sort items according to their ratios
    sort(items.begin(), items.end(), compare);

    double totalProfit = 0;

    // Select items
    for(int i = 0; i < items.size(); i++){
        // If complete item can fit
        if(capacity <= items[i].weight){
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        }

        // If only fraction can fit
        else{
            totalProfit += items[i].ratio * capacity;
            capacity = 0;
            break;
        }
    }
    return totalProfit;
}


int main(){
    int n;
    double capacity;

    cout << "Enter the number of items : ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter weight and profit of each item : \n";

    for(int i = 0; i < items.size(); i++){
        cin >> items[i].weight >> items[i].profit;
    }

    cout << "Enter capacity of knapsack : ";
    cin >> capacity;

    double answer = fractionalKnapsack(items, capacity);
    cout << "Maximum Profit : " << answer;

    return 0;
}

// Compilation
// g++ FractionalKnapsack.cpp -o FractionalKnapsack 

// Run
// FractionalKnapsack

// TC - O(nlogn)
// nlogn - sorting
// n - To calculate Profit/Weight ratio
// n - Selecting  Items
// O(n) + O(nlog n) + O(n) = O(nlogn)