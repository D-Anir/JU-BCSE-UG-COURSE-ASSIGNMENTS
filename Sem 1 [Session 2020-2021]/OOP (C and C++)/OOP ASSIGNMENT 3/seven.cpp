//function overloading in cpp

#include<iostream>
using namespace std;

void f(char c, int a){
    cout<<"function with argument list (char, int) is called.\n";
}

void f(int a, int b){
    cout<<"function with argument list (int, int) is called.\n";
}


int main(){
    int a;
    char c;
    float x,y;
    cout<<"ENTER AN INTEGER AND A CHARACTER RESPECTIVELY:\n";
    cin>>a>>c;
    cout<<"ENTER TWO FLOAT VALUES:\n";
    cin>>x>>y;
    f(a,c);
    f(c,c);
    // f(x,y);  //commented out to avoid ambiguity error
    return 0;
}