#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to simulate the PDA
bool simulatePDA(const string& input) {
    stack<char> pdaStack;
    int state = 0; // Initial state is q0

    for (char symbol : input) {
        if (state == 0) { // State q0: Reading 'a' and pushing onto the stack
            if (symbol == 'a') {
                pdaStack.push('a');
            } else if (symbol == 'b') {
                if (pdaStack.empty()) {
                    // No matching 'a' for this 'b', reject the string
                    return false;
                }
                pdaStack.pop(); // Match 'b' with 'a'
                state = 1; // Move to state q1
            } else {
                // Invalid symbol
                return false;
            }
        } else if (state == 1) { // State q1: Matching remaining 'b's with 'a's
            if (symbol == 'b') {
                if (pdaStack.empty()) {
                    // No matching 'a' for this 'b', reject the string
                    return false;
                }
                pdaStack.pop(); // Match 'b' with 'a'
            } else {
                // Invalid symbol or 'a' after 'b'
                return false;
            }
        }
    }

    // Accept if the stack is empty after processing all input
    return pdaStack.empty();
}

int main() {
    string input;

    cout << "Enter a string over {a, b}: ";
    cin >> input;

    if (simulatePDA(input)) {
        cout << "Accepted: The string belongs to the language {a^n b^n | n > 0}.\n";
    } else {
        cout << "Rejected: The string does not belong to the language {a^n b^n | n > 0}.\n";
    }

    return 0;
}
