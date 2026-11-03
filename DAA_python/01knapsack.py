def knapsack(capacity, weight, profit, n):

    # Create DP table
    dp = [[0 for w in range(capacity + 1)]
          for i in range(n + 1)]

    # Consider items one by one
    for i in range(1, n + 1):

        # Check all possible capacities
        for w in range(1, capacity + 1):

            # If current item can fit
            if weight[i - 1] <= w:

                # Maximum of including or excluding item
                dp[i][w] = max(
                    dp[i - 1][w],
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]]
                )

            # If item cannot fit
            else:
                dp[i][w] = dp[i - 1][w]

    # Return maximum profit
    return dp[n][capacity]


# Main program
n = int(input("Enter the number of items: "))

weight = []
profit = []

print("Enter weights of items:")
for i in range(n):
    weight.append(int(input()))

print("Enter profits of items:")
for i in range(n):
    profit.append(int(input()))

capacity = int(input("Enter knapsack capacity: "))

maxProfit = knapsack(capacity, weight, profit, n)

print("Maximum Profit =", maxProfit)