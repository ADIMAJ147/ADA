#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_CHAR = 256;

void computeShifts(const string& pattern, vector<int>& shifts) {
    int m = pattern.size();

    // Initialize all shifts to the length of the pattern
    for (int i = 0; i < MAX_CHAR; ++i) {
        shifts[i] = m;
    }

    // Update shifts for characters present in the pattern
    for (int i = 0; i < m - 1; ++i) {
        shifts[pattern[i]] = m - 1 - i;
    }
}

int horspoolSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();

    // Create a shift table
    vector<int> shifts(MAX_CHAR);

    // Compute the shift values
    computeShifts(pattern, shifts);

    int i = 0;
    while (i <= n - m) {
        int j = m - 1;

        // Keep matching characters from right to left
        while (j >= 0 && pattern[j] == text[i + j]) {
            j--;
        }

        if (j < 0) {
            // Pattern found at index i
            return i;
        } else {
            // Shift the pattern based on the bad character in the text
            i += shifts[text[i + m - 1]];
        }
    }

    // Pattern not found
    return -1;
}

int main() {
    string text = "CGTGCCTAGCTTGC";
    string pattern = "GCTAGC";

    int result = horspoolSearch(text, pattern);

    if (result != -1) {
        cout << "Pattern found at index " << result << endl;
    } else {
        cout << "Pattern not found in the text" << endl;
    }

    return 0;
}
