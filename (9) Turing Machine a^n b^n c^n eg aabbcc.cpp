#include <iostream>
#include <vector>
using namespace std;

void state2(vector<char> &, int);
void state3(vector<char> &, int);
void state4(vector<char> &, int);
void state5(vector<char> &, int);

void state1(vector<char> &tape, int i)
{
    if (i >= tape.size())
    { // if character reads = "Null"
        cout << "String is Rejected";
        return;
    }
    if (tape[i] == 'a')
    { // if character reads = "a"
        tape[i] = 'A';
        state2(tape, i + 1);
    }
    else if (tape[i] == 'B')
    { // if character reads = "b"
        state5(tape, i + 1);
    }
    else
    {
        cout << "String is Rejected";
        return;
    }
}

void state2(vector<char> &tape, int i)
{
    if (i >= tape.size())
    { // if character reads = "Null"
        cout << "String is Rejected";
        return;
    }
    if (tape[i] == 'b')
    { // if character reads = "b"
        tape[i] = 'B';
        state3(tape, i + 1);
    }
    else if (tape[i] == 'a' || tape[i] == 'B')
    { // if character reads = "a" or "B"
        state2(tape, i + 1);
    }
    else
    {
        cout << "String is Rejected";
        return;
    }
}

void state3(vector<char> &tape, int i)
{
    if (i >= tape.size())
    { // if character reads = "Null"
        cout << "String is Rejected";
        return;
    }
    if (tape[i] == 'c')
    { // if character reads = "c"
        tape[i] = 'C';
        state4(tape, i - 1);
    }
    else if (tape[i] == 'b' || tape[i] == 'C')
    { // if character reads = "b" or "C"
        state3(tape, i + 1);
    }
    else
    {
        cout << "String is Rejected";
        return;
    }
}

void state4(vector<char> &tape, int i)
{
    if (i >= tape.size())
    { // if character reads = "Null"
        cout << "String is Rejected";
        return;
    }
    if (tape[i] == 'A')
    { // if character reads = "A"
        state1(tape, i + 1);
    }
    else if (tape[i] == 'b' || tape[i] == 'C' || tape[i] == 'B' || tape[i] == 'a')
    { // if character reads = "b" or "C" or "B" or "a"
        state4(tape, i - 1);
    }
    else
    {
        cout << "String is Rejected";
        return;
    }
}

void state5(vector<char> &tape, int i)
{
    if (i >= tape.size())
    { // if character reads = "Null"
        cout << "String is Accepted";
        return;
    }
    if (tape[i] == 'B' || tape[i] == 'C')
    { // if character reads = "B" or "C"
        state5(tape, i + 1);
    }
    else
    {
        cout << "String is Rejected";
        return;
    }
}

int main()
{
    string w;
    vector<char> tape;
    cout << "Enter the string that you want to test (a's and b's): ";
    cin >> w;
    for (char ch : w)
    {
        tape.push_back(ch);
    }
    state1(tape, 0);
    return 0;
}