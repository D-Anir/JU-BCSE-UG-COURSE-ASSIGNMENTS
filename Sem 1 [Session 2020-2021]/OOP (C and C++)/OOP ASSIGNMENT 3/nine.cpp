//

#include<iostream>
using namespace std;

class TIME {  //class to store time
        int hour;
        int min;
        string time;
    public:
        void acceptTime(int);
        void dispTime();
        void addminute(int);
};


void TIME::acceptTime(int i){  //accepts time in desired format
    if(i==0){
        cout<<"ENTER TIME IN 12-hr FORMAT ( hh:mm:ssAM or hh:mm:ssPM where 01 <= hh <= 12 or 01 <= mm,ss <= 59 ):\n";
        cin>>time;
    }
    else{
        cout<<"ENTER TIME IN 24-hr FORMAT ( hh:mm:ss where 00 <= hh <= 23 or 01 <= mm,ss <= 59 ):\n";
        cin>>time;
    }
}

void TIME::dispTime(){  //displays time
    cout<<"THE TIME ENTERED BY THE USER IS: "<<time;
    cout<<"\n\n";
}

void TIME::addminute(int j){  //adds user-input minutes to the original time
    int k;
    cout<<"\nENTER THE MINUTES TO BE ADDED: ";
    cin>>k;
    string t=this->time;
    int min=((t[0] - '0') * 10 + (t[1] - '0'))*60 + ((t[3] - '0')*10 + (t[4] - '0'));
    min+=k;
    cout<<"THE UPDATED TIME IS: ";    
    
    int hour = (min / 60) % 24;   
    int minu = min % 60; 
    int sec= (t[6]-'0')*10 + (t[7]-'0');
    
    if(j==1){
        if (hour < 10)
            cout<<0<<hour<<":";  
        else
            cout<<hour<<":"; 

        if (minu < 10)
            cout << 0 << minu; 
        else
            cout << minu;

        cout<<":"<<sec<<endl;
    }
    else{
        if(hour<12){
            if (hour < 10)
                cout<<0<<hour<<":";  
            else
                cout<<hour<<":"; 

            if (minu < 10)
                cout << 0 << minu; 
            else
                cout << minu;

            cout<<":"<<sec<<"AM"<<endl;
        }
        else{
            if(hour!=12)
                hour=hour%12;
            if (hour < 10)
                cout<<0<<hour<<":";  
            else
                cout<<hour<<":";

            if (minu < 10)
                cout << 0 << minu; 
            else
                cout << minu;

            cout<<":"<<sec;
            if(t[8]=='A')
                cout<<"PM\n";
            else
                cout<<"AM\n";    
        }
    }
}



int main(){ //main
    TIME s;
    int ch,k=0;
    do{
        cout<<endl<<"***TIME STORING SYSTEM***\n\n";
        cout<<"1. ENTER TIME IN 24-hr FORMAT.\n";
        cout<<"2. ENTER TIME IN 12-hr(AM/PM) FORMAT.\n";
        cout<<"3. ADD MINNUTE TO EXISTING TIME.\n";
        cout<<"4. DISPLAY TIME.\n";
        cout<<"5. EXIT.\n";
        cout<<"\nENTER YOUR CHOICE: ";
        cin>>ch;
        switch(ch){
            case 1:
                s.acceptTime(1);
                k=1;
                break;
            case 2:
                s.acceptTime(0);
                k=0;
                break;
            case 3:
                s.addminute(k);
                break;
            case 4:
                s.dispTime();
                break;
            // default:
            //     cout<<"WRONG CHOICE!!\n\n";
        }
    }while(ch<=4);
    return 0;
}