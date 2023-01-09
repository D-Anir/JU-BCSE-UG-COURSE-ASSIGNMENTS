#include<iostream>
#include<string>

using namespace std;
string input_string = "";

// function declarations
int E();
int F();
int EP();
int T();
int TP();

/*
Grammar Used

E -> TE'
E' -> +TE' / #
T -> FT'
T' -> *FT' / #
F -> (E)/id

(# => NULL CHARACTER)
*/

// global variables
int i,l;

int EP(){
    if(input_string[i] == '+'){
        i++;
        if(T()){
            if(EP()){
                return 1;
            } else{
                return 0;
            }
        } else{
            return 0;
        }
    } else {
        return 1;
    }
}

int T() {
    if(F()){
        if(TP()){
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int TP(){
    if(input_string[i] == '*'){
        i++;
        if(F()){
            if(TP()){
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 1;
    }
}

int F() {
    if(input_string[i]=='('){
        i++;
        if(E()) {
            if(input_string[i]==')') {
                i++;
                return(1);
            } else{
                return(0);
            }
        } else{
            return(0);
        }
    } else if(input_string[i]>='a'&&input_string[i]<='z'||input_string[i]>='A'&&input_string[i]<='Z'){
        i++;
        return(1);
    } else{
        return(0);
    }
}

// definition of E as per given production
int E(){
    if(T()){
        if(EP()){
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int main(){
    cout<<"Recursive Descent Parsing of the given grammar is as follows:\n";
    cout<<"Enter Input String to be checked/parsed:\n";
    cin>>input_string;
    
    if(E()){
        if(input_string[i+1] == '\0'){
            cout<<"Input String IS accepted by given grammar.\n";
        } else {
            cout<<"Input String IS NOT accepted by given grammar.\n";
        }
    } else {
        cout<<"Input String IS NOT accepted by given grammar.\n";
    }
    
    return 0;
}