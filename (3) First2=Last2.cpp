#include <iostream>
using namespace std;

void state2(string, int);
void state3(string, int);
void state4(string, int);
void state5(string, int);
void state6(string, int);
void state7(string, int);
void state8(string, int);
void state9(string, int);
void state10(string, int);
void state11(string, int);
void state12(string, int);
void state13(string, int);
void state14(string, int);
void state15(string, int);

void state1(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state2(w, i + 1);
        else
            state9(w, i + 1);
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
            state3(w, i + 1);
        else
            state6(w, i + 1);
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
            state3(w, i + 1);
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
            state5(w, i + 1);
        else
            state3(w, i + 1);
    }
}

void state5(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is accepted";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state5(w, i + 1);
        else
            state3(w, i + 1);
    }
}

void state6(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state7(w, i + 1);
        else
            state6(w, i + 1);
    }
}

void state7(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state7(w, i + 1);
        else
            state8(w, i + 1);
    }
}

void state8(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is accepted";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state7(w, i + 1);
        else
            state6(w, i + 1);
    }
}

void state9(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state10(w, i + 1);
        else
            state13(w, i + 1);
    }
}

void state10(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state10(w, i + 1);
        else
            state11(w, i + 1);
    }
}

void state11(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state12(w, i + 1);
        else
            state11(w, i + 1);
    }
}

void state12(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is accepted";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state10(w, i + 1);
        else
            state11(w, i + 1);
    }
}

void state13(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state13(w, i + 1);
        else
            state14(w, i + 1);
    }
}

void state14(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is rejected";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state13(w, i + 1);
        else
            state15(w, i + 1);
    }
}

void state15(string w, int i)
{
    if (i == w.length())
    {
        cout << "String is accepted";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state13(w, i + 1);
        else
            state15(w, i + 1);
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