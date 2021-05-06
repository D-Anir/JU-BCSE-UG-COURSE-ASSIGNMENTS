//functions with default values in cpp 

#include<iostream>
using namespace std;

double tax(double income, int rate=10){  //rate is taken as 10% if its ot provided ny the user
    return ((income*rate)/100);
}

int main(){
    double income;
    int rate,ch;
    int k=1;
    do{
        cout<<"ENTER INCOME OF THE USER: ";
        cin>>income;
        cout<<"CALCULATE TAX WITH :\n";
        cout<<"1. rate of 10%.\n";
        cout<<"2. rate other than 10%.\n";
        cout<<"ENTER YOUR CHOICE: ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"\nThe tax amount is "<<tax(income)<<"."<<endl; //rate = 10%
                break;
            case 2:
                cout<<"\nENTER RATE OF TAX: ";
                cin>>rate;
                cout<<"\nThe tax amount is "<<tax(income, rate)<<"."<<endl; //rate = user entered value
                break;
            default:
                cout<<"WRONG CHOICE!";    
        }
        cout<<"WANT TO CALCULATE TAX AGAIN? PRESS 1 TO CONTINUE, 0 TO ABORT: ";
        cin>>k;
    } while(k!=0);
    return 0;
}