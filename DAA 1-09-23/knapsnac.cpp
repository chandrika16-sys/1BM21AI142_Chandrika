#include <iostream>

int knapsack(int weights[], int values[], int n, int capacity) {
    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; ++i) {
        dp[i] = new int[capacity + 1];
    }

    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = std::max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int result = dp[n][capacity];

    for (int i = 0; i <= n; ++i) {
        delete[] dp[i];
    }
    delete[] dp;

    return result;
}

int main() {
    int n;
    std::cout << "Enter the number of items: ";
    std::cin >> n;

    int* weights = new int[n];
    int* values = new int[n];

    std::cout << "Enter weights of items:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i];
    }

    std::cout << "Enter values of items:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }

    int capacity;
    std::cout << "Enter the knapsack capacity: ";
    std::cin >> capacity;

    int maxProfit = knapsack(weights, values, n, capacity);
    std::cout << "Maximum profit: " << maxProfit << "\n";

    delete[] weights;
    delete[] values;

    return 0;
}
