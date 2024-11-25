#include<iostream>
#include<vector>
using namespace std;

void state2(vector<char>&,int);

void state1(vector<char>& tape, int i){
    if(tape[i]=='N'){       // if NULL character finds
        state2(tape,i-1);
    }
    else{
        state1(tape,i+1);       // Move to right untill find NULL character
    }
}

void state2(vector<char>& tape, int i){
    if(tape[i]=='1'){       // if rightmost character found 1 then make it 0 and check it's left character
        tape[i]='0';
        state2(tape,i-1);
    }
    else{
        tape[i]='1';      // if 0 or NULL character finds then make it 1 and hault
        return;
    }
}

int main(){
    string w;
    vector<char> tape;
    cout << "Enter the binary number to increment: ";
    cin >> w;
    tape.push_back('N');        // Pushing null character in the starting of tape for overflow bit
    for (char ch : w)
    {
        tape.push_back(ch);
    }
    tape.push_back('N');        // Pushing null character at the end to show the ending of tape
    state1(tape, 1);
    cout<<"The number after the binary incrementation: ";
    for(int i=0;i<tape.size();i++){
        if (tape[i]=='N') continue;
        cout<<tape[i];
    }
    return 0;
}