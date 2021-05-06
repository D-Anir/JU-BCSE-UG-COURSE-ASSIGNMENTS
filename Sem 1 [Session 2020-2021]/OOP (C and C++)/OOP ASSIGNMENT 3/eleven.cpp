#include<iostream>
using namespace std;


class Applicant{
        static int last_roll;
        int roll;
        int score;
        char name[31];
    public:
        void acceptData();
        void showData() const; 
        static void showStudentCount(){ //to print the static variables
            cout<<"The current number of students is "<<Applicant::last_roll<<".\n";
        }   
};
int Applicant::last_roll=0;

void Applicant::acceptData(){ //accept data  from the user
    Applicant::last_roll++;
    roll=Applicant::last_roll;
    cout<<"Enter Name of Student: ";
    cin>>name;
    cout<<"Enter Score of Student: ";
    cin>>score;
}

void Applicant::showData() const{  //accessor function to show student data
    cout<<"Roll: "<<roll<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Score: "<<score<<endl;
}


int main(){
    Applicant s;
    int ch;
    do{
        cout<<"\n***STUDENT DATABASE***\n";
        cout<<"1. ADD STUDENT DETAILS.\n";
        cout<<"2. SHOW LAST STUDENT DETAILS.\n";
        cout<<"3. DISPLAY CURRENT COUNT OF STUDENTS.\n";
        cout<<"4. EXIT.\n";
        cout<<"\nENTER YOUR CHOICE: ";
        cin>>ch;
        switch(ch){
            case 1:
                s.acceptData();
                break;
            case 2:
                s.showData();
                break;
            case 3:
                Applicant::showStudentCount();
                break;    
        }
    }while(ch!=4);
    return 0;
}