#include<iostream>
#include<queue>
using namespace std;

#define lroll StudentPriorityQueue::lastroll

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
            cout<<"\nRoll: "<<roll<<"\n";
            cout<<"Name: "<<name<<"\n";
            cout<<"Score: "<<score<<"\n";
        }
        int returnScore() const{  //accessor function to return score of the student
            return score;
        }
};


//overloading the < operator to make score of students the priority
bool operator<(const Student& s1, const Student& s2){
    return s1.returnScore() < s2.returnScore() ;
}


//stores a queue of student objects according to a priority
class StudentPriorityQueue{
        priority_queue<Student> PQ_stu;
        static int lastroll;
    public:
        void addStudent(){
            Student s;
            lroll++;
            s.getInfo(lroll);
            PQ_stu.push(s);
        }

        void displayQueue(){
            Student s;
            cout<<"\nThe list is in descending order of score:\n";
            while(!PQ_stu.empty()){
                s = PQ_stu.top();  //gets the element with highest priority
                s.displayInfo();
                PQ_stu.pop();  //removes the element with highest priority
            }
            cout<<"\nQueue Empty, Add More Students to continue!\n";
        }

        //returns current size of the queue
        int returnSize(){
            return PQ_stu.size();
        }
};
int lroll=0; 



int main(){
    StudentPriorityQueue SPQ;
    int ch;

    //menu
    do{
        cout<<"\n1. Add Student.\n";
        cout<<"2. Display All Students according to Priority (highest score first).\n";
        cout<<"3. Exit.\n";
        cout<<"Enter Your Choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                SPQ.addStudent();
                break;
            case 2:
                //check for empty queue
                if(!SPQ.returnSize()){
                    cout<<"No Students Added!\n";
                    break;
                }
                SPQ.displayQueue();
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