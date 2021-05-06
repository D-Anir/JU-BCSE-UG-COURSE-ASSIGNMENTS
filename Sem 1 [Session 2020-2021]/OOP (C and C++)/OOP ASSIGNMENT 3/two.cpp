//inline function in cpp

#include<bits/stdc++.h>

using namespace std;

inline int product(int a, int b){
    return a*b;
}

int main(){
    time_t start, end;
    time(&start); //time function to calculate time of execution
    ios_base::sync_with_stdio(false); 

    int a,b;
    cout<<"ENTER TWO NUMBERS:\n";
    cin>>a>>b;
    cout<<"THEIR PRODUCT IS: "<< product(a,b) <<"\n";
    cout<<"ENTER TWO NUMBERS:\n";
    cin>>a>>b;
    cout<<"THEIR PRODUCT IS: "<< product(a,b) <<"\n";
    cout<<"ENTER TWO NUMBERS:\n";
    cin>>a>>b;
    cout<<"THEIR PRODUCT IS: "<< product(a,b) <<"\n\n";   


    time(&end); 
    double time_taken = double(end - start); 
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cout << " sec " << endl;

    return 0; 
}