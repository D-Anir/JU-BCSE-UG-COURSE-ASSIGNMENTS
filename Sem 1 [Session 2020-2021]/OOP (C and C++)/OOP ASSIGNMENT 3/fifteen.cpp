#include<iostream>
using namespace std;

class TRANSACTION;

class BALANCE{
        static int last;
        int accno;
        int balance;
        int dd;
        int mm;
        int yy;
    public:
        void input();
        void show();
        void update(TRANSACTION);
        static int numOfitems(){  //print static variable
            return last;
        }
};

int BALANCE::last=0;

class TRANSACTION{
        BALANCE b;
        int acc;
        int amt;
        char type;
        int d;
        int m;
        int y;
    public:
        void input();
        friend void BALANCE::update(TRANSACTION);
        void menu();
};

void BALANCE::input(){  //takes input from the user
    cout<<"Enter Account Number: ";
    cin>>accno;
    cout<<"Enter Balance: ";
    cin>>balance;
    cout<<"Enter Date: ";
    cout<<"\nDay: ";cin>>dd;
    cout<<"Month: ";cin>>mm;
    cout<<"Year: ";cin>>yy;
    ++BALANCE::last;
}

void BALANCE::show(){  //display account details
    cout<<"Acoount No.: "<<accno;
    cout<<"\nBalance: "<<balance;
    cout<<"\nLast Updated: "<<dd<<"/"<<mm<<"/"<<yy<<"\n";
}

void TRANSACTION::input(){  //take transaction input
    cout<<"Enter Account No.: ";
    cin>>acc;
    cout<<"Enter Transaction Type (W-WITHDRAWL, D-DEPOSIT): ";
    cin>>type;
    cout<<"Enter Amount: ";
    cin>>amt;
    cout<<"Enter Date: ";
    cout<<"\nDay: ";cin>>d;
    cout<<"Month: ";cin>>m;
    cout<<"Year: ";cin>>y;
}

void BALANCE::update(TRANSACTION s){  //update balance remainning in account
    if(s.type=='W')
        balance=balance-s.amt;
    else
        balance=balance+s.amt;
    dd=s.d;mm=s.m;yy=s.y;
}

void TRANSACTION::menu(){ //menu for dashboard
    int ch;
    do{
        cout<<"\n***BANK TRANSACTION SYSTEM***\n\n";
        cout<<"1. ADD ACCOUNT.\n";
        cout<<"2. UPDATE ACCOUNT.\n";
        cout<<"3. SHOW ACCOUNT DETAILS.\n";
        cout<<"4. EXIT.\n";
        cout<<"Enter YOur Choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                b.input();
                break;
            case 2:
                TRANSACTION c;
                c.input();
                b.update(c);
                break;
            case 3:
                b.show();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout<<"INVALID CHOICE!!\n";
        }
    }while(ch!=4);
}

int main(){
    TRANSACTION k;
    k.menu();
    return 0;
}