#include<iostream>
using namespace std;


//stores cricketer details
class cricketer{
        char name[31];
        char dob[9];
        int matches;
        int flag;
    public:
        cricketer(){
            flag=0;
        }

        virtual void getInfo(){
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter dob: ";
            cin>>dob;
            cout<<"Enter Matches: ";
            cin>>matches;
            flag=1;
        }      

        virtual void dispInfo(){
            cout<<"Name: "<<name<<"\n";
            cout<<"DOB: "<<dob<<"\n";
            cout<<"Matches: "<<matches<<"\n";
        }

        int returnMatches(){
            return matches;
        }
        int returnFlag(){
            return flag;
        }
};

//stores batsman details
class batsman:public virtual cricketer{ //inhetrits from cricketer
        int totalRuns;
        int avg;
    public:
        void getInfo(){
            if(cricketer::returnFlag()==0)
                cricketer::getInfo();
            cout<<"Enter Total Runs Scored: ";
            cin>>totalRuns;
            avg=totalRuns/cricketer::returnMatches();
        }
        void dispInfo(){
            cricketer::dispInfo();
            cout<<"Total Runs: "<<totalRuns<<"\n";
            cout<<"Average: "<<avg<<"\n";
        }
};

//stores bowler details
class bowler:public virtual cricketer{  //inherits from cricketer
        int totalWickets;
        int runsConceeded;
        int oversBowled;
        int avg;
    public:
        void getInfo(){
            if(cricketer::returnFlag()==0)            
                cricketer::getInfo();
            cout<<"Enter Runs Connceeded: ";
            cin>>runsConceeded;
            cout<<"Enter Total Wickets Taken: ";
            cin>>totalWickets;
            cout<<"Enter Overs Bowled: ";
            cin>>oversBowled;
            avg=runsConceeded/oversBowled;
        }
        void dispInfo(){
            cricketer::dispInfo();
            cout<<"Total Runs Conceeded: "<<runsConceeded<<"\n";
            cout<<"Total Wickets Taken: "<<totalWickets<<"\n";
            cout<<"Overs Bowled: "<<oversBowled<<"\n";
            cout<<"Average: "<<avg<<"\n";
        }
};

//stores allrounder details
class allrounder:public batsman, public bowler{  //inherits from both batsman and bowler
    public:
        void getInfo(){
            batsman::getInfo();
            bowler::getInfo();
        }
        void dispInfo(){
            batsman::dispInfo();
            bowler::dispInfo();
        }
};


//stores pair details
class doublewicket_pair{
        batsman bt;
        bowler bw;
    public:
        void get(){
            cout<<"Enter Batsman Details:\n";
            bt.getInfo();
            cout<<"\nEnter Bowler Details:\n";
            bw.getInfo();
        }
        void disp(){
            cout<<"BATSMAN DETAILS:\n";
            bt.dispInfo();
            cout<<"\nBOWLER DETAILS:\n";
            bw.dispInfo();
        }
};



int main(){
    cricketer *ob;

    cout<<"Enter Batsman Details:\n";
    ob = new batsman; //batsman instance
    ob->getInfo();
    cout<<"\n";
    ob->dispInfo();

    cout<<"\nEnter Bowler Details:\n";
    ob = new bowler;  //bowler instance
    ob->getInfo();
    cout<<"\n";
    ob->dispInfo();

    cout<<"\nEnter All-Rounder Details:\n";
    ob = new allrounder;  //allrounder instance
    ob->getInfo();
    cout<<"\n";
    ob->dispInfo();

    cout<<"\nEnter Pair Details:\n";
    doublewicket_pair p;  //pair object
    p.get();
    cout<<"\n";
    p.disp();
    return 0;
}