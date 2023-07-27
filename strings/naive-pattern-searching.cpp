#include <iostream>
#include <string>

using namespace std;

// Function to perform pattern searching using the naive algorithm
void naiveSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++) {
        int j;
        // Check for a match starting at index i
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }

        // If the inner loop completes without a break, we found a match
        if (j == m)
            cout << "Pattern found at index " << i << endl;
    }
}

int main() {
    string text, pattern;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    naiveSearch(text, pattern);

    return 0;
}
