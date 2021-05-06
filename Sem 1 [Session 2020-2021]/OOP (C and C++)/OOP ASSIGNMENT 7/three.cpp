#include<iostream>
#include<queue>
using namespace std;

#define lroll StudentQueue::lastroll

//stores student details
class Student{
        int roll;
        string name;
        int score;
    public:
        void getInfo(int r){
            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Enter Score: ";
            cin>>score;
            roll = r;
            cout<<"Alotted Roll: "<<roll<<"\n";
        }
        void displayInfo(){
            cout<<"\t "<<roll;
            cout<<"\t "<<name;
            cout<<"\t "<<score<<"\n";
        }
        int returnScore() const{ //accessor function to return score of a student
            return score;
        }
};


//stores a queue of student objects
class StudentQueue{
        queue<Student> Q_stu;
        static int lastroll;
    public:
        void addStudent(){
            Student s;
            lroll++;
            s.getInfo(lroll);
            Q_stu.push(s);
        }
        void displayMarksheet(){
            bool proceed = 1;
            Student s;
            cout<<"Marksheet of Student in order of earliest enrollment:\n";
            while(proceed){
                s = Q_stu.front();  //gets the element at the top of the queue
                cout<<"\n\tRoll\tName\tScore";
                cout<<"\n.....................................\n";
                s.displayInfo();
                Q_stu.pop();  //pops (or removes) the element at the top of the queue
                cout<<"\nWant to see Marksheet of next enrolled Student? Press 1 to continue 0 for Top Menu.\n";
                cin>>proceed;

                //check for emoty queue
                if(!Q_stu.size()){
                    cout<<"No More Students Enrolled!\n";
                    return;
                }
            }
        }

        //returns current size of the queue
        int returnSize(){
            return Q_stu.size();
        }
};
int lroll=0;

int main(){
    StudentQueue SQ;
    int ch;
    
    //menu
    do{
        cout<<"\n1. Add Student.\n";
        cout<<"2. Display Marksheet of a Student.\n";
        cout<<"3. Exit.\n";
        cout<<"Enter Your Choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                SQ.addStudent();
                break;
            case 2:
                //check for empty queue
                if(!SQ.returnSize()){
                    cout<<"No Student Added!\n";
                    break;
                }
                SQ.displayMarksheet();
                break;
            case 3:
                exit(0);
                break;
            default:
                cout<<"Wrong Choice!\n";
        }
    }while(ch!=3);
    
    return 0;
}