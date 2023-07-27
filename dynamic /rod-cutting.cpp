#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cutRod(vector<int>& prices, int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int maxPrice = 0;
        for (int j = 1; j <= i; j++) {
            maxPrice = max(maxPrice, prices[j - 1] + dp[i - j]);
        }
        dp[i] = maxPrice;
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the prices for each length: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int maxPrice = cutRod(prices, n);
    cout << "Maximum value that can be obtained: " << maxPrice << endl;

    return 0;
}
