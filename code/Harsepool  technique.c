Program:
#include <iostream>
#include <string.h>
using namespace std;

void computeShiftTable(char pattern[], int m, int shiftTable[]) {
    int i;
    // Initialize all entries to pattern length m
    for (i = 0; i < 256; i++)
        shiftTable[i] = m;
    
    // Fill shift values for characters in pattern (except last)
    for (i = 0; i < m - 1; i++)
        shiftTable[(int)pattern[i]] = m - 1 - i;
}

void harspoolSearch(char text[], char pattern[], int shiftTable[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    
    cout << "\n=== Harspool's String Matching ===" << endl;
    cout << "Text:    " << text << endl;
    cout << "Pattern: " << pattern << endl;
    cout << "Pattern Length (m): " << m << endl;
    cout << string(20 + m, '-') << endl;
    
    int i = m - 1;  // Position of pattern's last character in text
    
    while (i <= n - 1) {
        int j = m - 1;
        
        // Match pattern from right to left
        while (j >= 0 && pattern[j] == text[i - (m - 1 - j)])
            j--;
        
        cout << "i=" << i << " ";
        for (int k = 0; k < i - m + 1; k++) cout << " ";
        cout << "|";
        
        // Print pattern alignment
        for (int k = 0; k < m; k++) {
            if (k <= j) cout << " ";
            else if (pattern[k] == text[i - (m - 1 - k)]) cout << pattern[k];
            else cout << "X";
        }
        cout << "| ";
        
        if (j == -1) {
            cout << "✓ MATCH FOUND at position " << (i - m + 1) << endl;
            i += shiftTable[(int)text[i]];
        } else {
            cout << "Mismatch, shift by " << shiftTable[(int)text[i]] << endl;
            i += shiftTable[(int)text[i]];
        }
    }
    cout << "Search completed.\n" << endl;
}

int main() {
    char text[100], pattern[50];
    int shiftTable[256];
    
    cout << "Enter the text: ";
    cin.getline(text, 100);
    
    cout << "Enter the pattern: ";
    cin.getline(pattern, 50);
    
    // Compute shift table
    computeShiftTable(pattern, strlen(pattern), shiftTable);
    
    cout << "\nShift Table for pattern '" << pattern << "':" << endl;
    cout << "Char\tShift" << endl;
    cout << "-----\t-----" << endl;
    for (int i = 0; i < strlen(pattern); i++) {
        cout << pattern[i] << "\t" << shiftTable[(int)pattern[i]] << endl;
    }
    cout << endl;
    
    // Perform search
    harspoolSearch(text, pattern, shiftTable);
    
    return 0;
}

ro
