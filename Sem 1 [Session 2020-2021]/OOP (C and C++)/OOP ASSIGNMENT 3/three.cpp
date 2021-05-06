//reference variables in cpp

#include<bits/stdc++.h>

using namespace std;

void swap(int &p, int &q){ //p&q gets initialized with the actual parameters that are passed
    int k;
    k=p;
    p=q;
    q=k;
}


int main(){
    int a,b;
    cout<<"ENTER TWO NUMBERS:\n";
    cin>>a>>b;
    cout<<"\nBEFORE SWAPPING...\n";
    cout<<"FIRST NUMBER IS "<<a<<" and SECOND NUMBER IS "<<b<<"\n\n";
    swap(a,b);
    cout<<"AFTER SWAPPING...\n";
    cout<<"FIRST NUMBER IS "<<a<<" and SECOND NUMBER IS "<<b<<"\n\n";
    return 0;
}