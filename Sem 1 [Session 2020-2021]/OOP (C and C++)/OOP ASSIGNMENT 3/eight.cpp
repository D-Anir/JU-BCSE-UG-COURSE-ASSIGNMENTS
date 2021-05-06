//structures in cpp

#include<iostream>
using namespace std;

struct student{
    int roll;
    char name[31];
    int score;
    void getdata();
    void showdata();
};

void student::getdata(){  //to get input from the user
    cout<<"\nENTER ROLL: ";
    cin>>roll;
    cout<<"ENTER NAME: ";
    cin>>name;
    cout<<"ENTER SCORE: ";
    cin>>score;
}

void student::showdata(){  //to display details of student
    cout<<"\nROLL: "<<roll;
    cout<<"\nNAME: "<<name;
    cout<<"\nSCORE: "<<score<<"\n";
}

void modifyscore(int *s){  //global function to modify score
    *s += 10;
}

int main(){
    int n;
    cout<<"ENTER NUMBER OF STUDENTS: ";
    cin>>n;
    student arr[n];
    for(int i=0;i<n;i++)
        arr[i].getdata();
    for(int i=0;i<n;i++)
        arr[i].showdata();
    modifyscore(&arr[1].score);
    arr[1].showdata();
    return 0;
}