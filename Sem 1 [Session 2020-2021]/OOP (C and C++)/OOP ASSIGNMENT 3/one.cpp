//to test macro in cpp 

#include<iostream>

using namespace std;

#define max(a,b) (((a)>(b))?(a):(b)) //macro to find maximum from the arguments

int main(){
    int a,b;
    cout<<"ENTER TWO NUMBERS:\n";
    cin>>a>>b;
    cout<<"MAXIMUM OF THE TWO IS "<<max(a,b)<<endl;
    cout<<"FOR char*:\n";
    string c="HELLO";
    string d="WORLD";
    cout<<"MAXIMUM OF THE TWO IS '"<<max(c,d)<<"'"<<endl;
    return 0;
}