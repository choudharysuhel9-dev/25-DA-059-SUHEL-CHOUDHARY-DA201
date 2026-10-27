
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, W;
    int weight[100], profit[100];
    int dp[101][1001] = {0};

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter weights of items: ";
    for (int i = 1; i <= n; i++)
        cin >> weight[i];

    cout << "Enter profits of items: ";
    for (int i = 1; i <= n; i++)
        cin >> profit[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weight[i] <= w) {
                dp[i][w] = max(
                    profit[i] + dp[i - 1][w - weight[i]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum profit: " << dp[n][W] << endl;

    return 0;
}
