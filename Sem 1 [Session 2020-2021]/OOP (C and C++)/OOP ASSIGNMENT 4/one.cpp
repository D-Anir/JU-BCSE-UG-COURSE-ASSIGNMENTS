#include<iostream>
#include<string>
using namespace std;

#define an account_list::no_of_acc

class account{
    int acc_no;
    int balance;
    public:
        friend class account_list;
};

class account_list{
    static int no_of_acc;
    account list[100];
    public:
        void add_acc();
        void withdraw(int);
        void deposit(int);
        void display_acc(int);
        void const disp_count(){  //display static variable
            cout<<"Number of Active Accounts: "<<an<<"\n\n"; 
        }
};

int account_list::no_of_acc=0;

void account_list::add_acc(){ //add account
    if(an>100){
        cout<<"ACCOUNT LIMIT REACHED. PLEASE CONTACT THE MANAGER.\n";
        return;
    }
    ++an;
    list[an].acc_no=an;
    cout<<"Enter Account Balance: ";
    cin>>list[an].balance;
    cout<<"Alloted Account Number: A00"<<list[an].acc_no<<"\n";
}

void account_list::withdraw(int a){  //withdraw amount
    if(a<=0 || a>an){
        cout<<"Invalid Account Number!\n";
        return;
    }
    cout<<"Available Balance in account A00"<<a<<": Rs. "<<list[a].balance<<"\n";
    int amt;
    cout<<"Enter Amount to be Withdrawn: ";
    cin>>amt;
    if(amt>list[a].balance){
        cout<<"Withdraw Amount Exceeded!\n";
        return;
    }
    list[a].balance = list[a].balance - amt;
    cout<<"Account Updated!\n";
}

void account_list::deposit(int a){  //deposit amount
    if(a<=0 || a>an){
        cout<<"Invalid Account Number!\n";
        return;
    }
    cout<<"Available Balance in account A00"<<a<<": Rs. "<<list[a].balance<<"\n";
    int amt;
    cout<<"Enter Amount to be Deposit: ";
    cin>>amt;
    list[a].balance = list[a].balance + amt;
    cout<<"Account Updated!\n";
}

void account_list::display_acc(int a){  //display account
    if(a<=0 || a>an){
        cout<<"Invalid Account Number!\n";
        return;
    }
    cout<<"Account Number: A00"<<list[a].acc_no<<"\n";
    cout<<"Account Balance: "<<list[a].balance<<"\n";
}


int main(){
    account_list ob;
    int ch;
    string acc;
    do{
        cout<<"\n***BANK TRANSACTION SYSTEM***\n\n";
        cout<<"1. ADD ACCOUNT.\n";
        cout<<"2. WITHDRAW AMOUNT.\n";
        cout<<"3. DEPOSIT AMOUNT.\n";
        cout<<"4. DISPLAY ACCOUNT.\n";
        cout<<"5. DISPLAY NUMBER OF ACTIVE ACCOUNTS.\n";
        cout<<"6. EXIT.\n";
        cout<<"Enter Your Choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                ob.add_acc();
                break;
            case 2:
                cout<<"\nEnter Acoount Number(format A00X): ";
                cin>>acc;
                ob.withdraw(acc[3] - '0');
                break;
            case 3:
                cout<<"\nEnter Acoount Number(format A00X): ";
                cin>>acc;
                ob.deposit(acc[3] - '0');
                break;
            case 4:
                cout<<"\nEnter Acoount Number(format A00X): ";
                cin>>acc;
                ob.display_acc(acc[3] - '0');
                break;
            case 5:
                ob.disp_count();
                break;
            case 6:
                exit(0);
                break;
            default:
                cout<<"INVALID CHOICE!!!!\n\n";
        }
    }while(ch!=6);
    return 0;
}