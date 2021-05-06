//function overloading in cpp

#include<iostream>
using namespace std;


void f(int x){ //function with integer argument
    cout<<"inside f(int)\n";
}

void f(float x){ //function with float argument
    cout<<"inside f(float)\n";
}


int main(){
    int a;
    char b;
    float c;
    double d;
    cout<<"ENTER\n1. an integer\n2. a character\n3. a float\n4. a double\n\nin order as mentioned above:\n";
    cin>>a>>b>>c>>d;
    f(a);
    f(b);
    f(c);
    // f(d);  //commented out to avoid ambiguity error
    return 0;
}