#include<bits/stdc++.h>

using namespace std;

// Function to compute the longest proper suffix which is also a prefix
void computeLPS(const string& pattern, vector<int>& lps) {
    int length = 0; // Length of the previous longest prefix suffix
    int i = 1;

    lps[0] = 0; // lps[0] is always 0

    while (i < pattern.length()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to perform pattern searching using KMP algorithm
void kmpSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    // Create the lps (longest proper suffix) array
    vector<int> lps(m, 0);
    computeLPS(pattern, lps);

    int i = 0; // Index for text[]
    int j = 0; // Index for pattern[]

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    string text, pattern;
    bool casesensitive ;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pattern);
    
    cout<< "Case Sensitive (1 or 0) : ";
    cin>>casesensitive;

    if (!casesensitive){
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        transform(pattern.begin(), pattern.end(), pattern.begin(), ::tolower);
    } 
    
    kmpSearch(text, pattern);

    return 0;
}
