#include <iostream>
#include <stack>
using namespace std;

void read_state2(string &, int, stack<char> &);
void pop_state1(string &, int, stack<char> &);
void pop_state2(string &, int, stack<char> &);
void pop_state3(string &, int, stack<char> &);

void read_state1(string &w, int i, stack<char> &stk_AB)
{
    if (i >= w.length())
    { // if character reads = "∆"
        cout << "String is Rejected";
        return;
    }
    if (w[i] == 'a' || w[i] == 'b')
    { // // if character reads = "a" or "b"
        stk_AB.push(w[i]);
        read_state1(w, i + 1, stk_AB);
    }
    else
    { // if character reads = "X"
        read_state2(w, i+1, stk_AB);
    }
}

void pop_state1(string &w, int i, stack<char> &stk_AB)
{
    if (stk_AB.empty())
    { // if character poped = "∆"
        cout << "String is Accepted";
        return;
    }
    else{   // if character poped = "a" or "b" or "X"
        cout<<"String is Rejected";
        return;
    }
}

void read_state2(string &w, int i, stack<char> &stk_AB)
{
    if (i >= w.length())
    { // if character reads = "∆"
        pop_state1(w, i, stk_AB);
        return;
    }
    if (w[i] == 'a')
    { // if character reads = "a"
        pop_state2(w, i, stk_AB);
    }
    else if (w[i]=='b'){    // if character reads = "b"
        pop_state3(w,i,stk_AB);
    }
    else
    { // if character reads = "X"
        cout<<"String is Rejected";
        return;
    }
}

void pop_state2(string &w, int i, stack<char> &stk_AB)
{
    if (stk_AB.empty())
    { // if character poped = "∆"
        cout << "String is Rejected";
        return;
    }

    char pop_ch = stk_AB.top();
    if (pop_ch == 'a')
    { // if character poped from stack = "a"
        stk_AB.pop();
        read_state2(w, i + 1, stk_AB);
    }
    else
    { // if character poped from stack ="b" or "X"
        cout << "String is Rejected";
        return;
    }
}

void pop_state3(string &w, int i, stack<char> &stk_AB)
{
    if (stk_AB.empty())
    { // if character poped = "∆"
        cout << "String is Rejected";
        return;
    }

    char pop_ch = stk_AB.top();
    if (pop_ch == 'b')
    { // if character poped from stack = "b"
        stk_AB.pop();
        read_state2(w, i + 1, stk_AB);
    }
    else
    { // if character poped from stack ="a" or "X"
        cout << "String is Rejected";
        return;
    }
}

int main()
{
    string w;
    stack<char> stk_AB;
    cout << "Enter the string that you want to test (a's and b's): ";
    cin >> w;
    read_state1(w, 0, stk_AB);
    return 0;
}