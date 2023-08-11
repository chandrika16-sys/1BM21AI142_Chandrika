#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int ALPHABET_SIZE = 256;

// To generate shift table
void generateShiftTable(const string& pattern, int shiftTable[]) {
    int m = pattern.length();

    // Initialising the shift table
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        shiftTable[i] = m;
    }

    // Fill in the shift values
    for (int i = 0; i < m - 1; ++i) {
        shiftTable[pattern[i]] = m - 1 - i;
    }
}

// string search function
int horspoolSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    if (n < m) {
        return -1; // no match
    }

    int shiftTable[ALPHABET_SIZE];
    generateShiftTable(pattern, shiftTable);

    int i = m - 1;
    int j;

    while (i < n) {
        j = m - 1;

        while (j >= 0 && text[i] == pattern[j]) {
            --i;
            --j;
        }

        if (j == -1) {
            return i + 1; // Match found
        }

        i += shiftTable[text[i]];
    }

    return -1; // No match found
}

int main() {
    string text = "Betty got some butter but butter was bitter";
    string pattern = "bitter";

    cout<<"Text in which the pattern has to be matched:"<<text<<endl;
    cout<<"The pattern to be matched: "<<pattern<<endl;

    int result = horspoolSearch(text, pattern);

    if (result != -1) {
        cout << "Pattern found at index " << result << endl;
    } else {
        cout << "Pattern not found in the text." << endl;
    }

    return 0;
}
