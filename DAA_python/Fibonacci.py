#Recursive
def fibo(n):
    if n == 0:
        return 0

    if n == 1:
        return 1

    return fibo(n - 1) + fibo(n - 2)


n = 7

for i in range(n):
    print(fibo(i), end=" ")




# Non recursive
n = 7

a = 0
b = 1

for i in range(n):
    print(a, end=" ")

    c = a + b
    a = b
    b = c