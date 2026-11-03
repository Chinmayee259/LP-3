#include<iostream>
using namespace std;

void fibonacci(int n){
    int a = 0;
    int b = 1;
    int c;
    int stepCount = 0;

    cout << "Fibonacci Series : ";

    for(int i = 0; i < n; i++){
        cout << a << " ";
        c = a + b;
        stepCount++;

        a = b;
        b = c;
    }

    cout << "\nStep Count : " << stepCount << endl;

}

int main(){
    int n;
    
    cout << "Enter the number of terms : ";
    cin >> n;

    fibonacci(n);

    return 0;
}

// Compilation
// g++ Fibonacci.cpp -o Fibonacci 

// Run
// Fibonacci

// TC - O(n)


//recursive
#include <iostream>
using namespace std;

int fibo(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int n = 7;

    for (int i = 0; i < n; i++)
    {
        cout << fibo(i) << " ";
    }

    return 0;
}