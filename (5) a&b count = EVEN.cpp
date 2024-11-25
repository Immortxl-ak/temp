#include <iostream>
using namespace std;

void state2(string, int);
void state3(string, int);
void state4(string, int);

void state1(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is accepted";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state2(w, i + 1);
        else
            state3(w, i + 1);
    }
}

void state2(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state1(w, i + 1);
        else
            state4(w, i + 1);
    }
}

void state3(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state4(w, i + 1);
        else
            state1(w, i + 1);
    }
}

void state4(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state3(w, i + 1);
        else
            state2(w, i + 1);
    }
}

int main()
{
    string w;
    cout << "Enter the string that you want to test (a's and b's): ";
    cin >> w;
    state1(w, 0);
    return 0;
}