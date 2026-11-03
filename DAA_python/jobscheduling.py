class jobschedule:

    def solve(self):

        job = ['a', 'b', 'c', 'd', 'e']
        deadline = [2, 1, 2, 1, 3]
        profit = [100, 19, 27, 25, 15]

        # Sort jobs according to profit
        for i in range(5):
            for j in range(i + 1, 5):

                if profit[i] < profit[j]:
                    profit[i], profit[j] = profit[j], profit[i]
                    job[i], job[j] = job[j], job[i]
                    deadline[i], deadline[j] = deadline[j], deadline[i]

        # Find maximum deadline
        maxdeadline = 0

        for i in range(5):
            if deadline[i] > maxdeadline:
                maxdeadline = deadline[i]

        # Create slots
        slot = ['-'] * maxdeadline

        maxprofit = 0

        # Schedule jobs
        for i in range(5):

            for j in range(deadline[i] - 1, -1, -1):

                if slot[j] == '-':
                    slot[j] = job[i]
                    maxprofit += profit[i]
                    break

        # Print maximum profit
        print(maxprofit)

        # Print scheduled jobs
        for i in range(maxdeadline):
            if slot[i] != '-':
                print(slot[i], end="")


# Main program
obj = jobschedule()
obj.solve()