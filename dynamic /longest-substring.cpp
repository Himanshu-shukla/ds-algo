#include <iostream>
#include <vector>

using namespace std;

string longestCommonSubstring(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();

    // Create a 2D DP table to store the lengths of the common substrings
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int maxLength = 0; // Length of the longest common substring
    int endIndex = 0;  // Ending index of the longest common substring in str1

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // Extract the longest common substring using the endIndex and maxLength
    string longestSubstring = str1.substr(endIndex - maxLength, maxLength);
    return longestSubstring;
}

int main() {
    string str1, str2;
    cout << "Enter the first string: ";
    getline(cin, str1);

    cout << "Enter the second string: ";
    getline(cin, str2);

    string lcs = longestCommonSubstring(str1, str2);
    cout << "Longest Common Substring: " << lcs << endl;

    return 0;
}
