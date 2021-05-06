//reference variables in cpp

#include<iostream>
using namespace std;

int& max(int &a, int &b){
    if(a>b)
        return a;
    return b;    
}

int main(){
    int a,b;
    cout<<"ENTER VALUE OF a AND b RESPECTIVELY:\n";
    cin>>a>>b;
    
    int x1=max(a,b);

    int &x2=max(a,b); //reference of either a or b is returned by max() and initialized to x2.
    
    cout<<"\nx1(of type int) and x2(of type int&):\n"<<x1<<"\t"<<x2<<endl;
    cout<<"Values of a and b before modifying x1&x2:\n"<<a<<"\t"<<b<<endl<<endl;
    x1++;x2++;
    cout<<"\nx1(of type int) and x2(of type int&) (after modifying):\n"<<x1<<"\t"<<x2<<endl;
    cout<<"Values of a and b after modifying x1&x2:\n"<<a<<"\t"<<b<<endl<<endl;
    return 0; 
}
