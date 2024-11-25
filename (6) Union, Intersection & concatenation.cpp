#include <iostream>
#include <string>

using namespace std;

// Example FA for language L1: Strings over {a, b} starting and ending with 'a'
bool isInL1(const string& str) {
    return !str.empty() && str.front() == 'a' && str.back() == 'a';
}

// Example FA for language L2: Strings over {a, b} with an even number of 'b's
bool isInL2(const string& str) {
    int bCount = 0;
    for (char c : str) {
        if (c == 'b') {
            bCount++;
        }
    }
    return bCount % 2 == 0;
}

// Union of L1 and L2
bool isInUnion(const string& str) {
    return isInL1(str) || isInL2(str);
}

// Intersection of L1 and L2
bool isInIntersection(const string& str) {
    return isInL1(str) && isInL2(str);
}

// Concatenation of L1 and L2
bool isInConcatenation(const string& str) {
    int n = str.length();
    for (int i = 1; i < n; ++i) {
        string part1 = str.substr(0, i);
        string part2 = str.substr(i);
        if (isInL1(part1) && isInL2(part2)) {
            return true;
        }
    }
    return false;
}

int main() {
    string input;

    cout << "Enter a string over {a, b} to test for union, intersection, and concatenation: ";
    cin >> input;

    cout << "\nResults for the string: " << input;
    cout << "\n  In L1: " << (isInL1(input) ? "Yes" : "No");
    cout << "\n  In L2: " << (isInL2(input) ? "Yes" : "No");
    cout << "\n  In Union (L1 ∪ L2): " << (isInUnion(input) ? "Yes" : "No");
    cout << "\n  In Intersection (L1 ∩ L2): " << (isInIntersection(input) ? "Yes" : "No");
    cout << "\n  In Concatenation (L1L2): " << (isInConcatenation(input) ? "Yes" : "No");

    return 0;
}
