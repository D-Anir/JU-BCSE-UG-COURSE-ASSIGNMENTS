#include<iostream>
#include<fstream>
using namespace std;


//stores student details
class student{
        int roll;
        char name[31];
        int score;
    public:
        void getData(int r) {  //accepts student data
            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Enter Score: ";
            cin>>score;
            roll = r;
            cout<<"Roll Alloted: "<<roll<<endl;
        }
        void showData(){  //prints student data
            cout<<"\nRoll: "<<roll;
            cout<<"\nName: "<<name;
            cout<<"\nScore: "<<score;
        }
};


//stores list of student objects
class list{
        static int numberofstudents;
        student array[100];
    public:
        void addStudent(){  //adds a student to the list
            array[numberofstudents].getData(numberofstudents+1);
            numberofstudents++;
        }
        void displayStudent(int r) throw(int){
            if(r>100 || r<1 || r>numberofstudents)  //throws error if roll goes out of bound
                throw -1;
            array[r-1].showData();
        }
};
int list::numberofstudents=0; //static variable initialilised outside

int main(){
    list ob; 
    int ch, roll;
    do{
        cout<<"\n1. Add Student.\n";
        cout<<"2. Display Student.\n";
        cout<<"3. Exit.\n";
        cout<<"Enter Your Choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                ob.addStudent();
                break;
            case 2:
                cout<<"Enter Roll to be displayed: ";
                cin>>roll;
                //try-catch block
                try{
                    ob.displayStudent(roll);
                }
                catch(int i){
                    cout<<"INVALID ROLL NUMBER!\n";
                }
                break;
            case 3:
                exit(0);
                break;
            default:
                cout<<"Invalid Choice!\n";
        }
    }while(ch!=3);
    return 0;
}