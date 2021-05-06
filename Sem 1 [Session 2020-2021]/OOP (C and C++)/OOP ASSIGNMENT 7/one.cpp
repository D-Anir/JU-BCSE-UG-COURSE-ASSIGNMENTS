#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

#define lroll  StudentList::lastroll   //macro to define number of students enrolled

//stores details of each student
class Student{
        int roll;
        string name;
        int score;
    public:
        void getInfo(int r){
            cout<<"\nEnter Name: ";
            cin>>name;
            cout<<"Enter Score: ";
            cin>>score;
            roll = r;
            cout<<"Alotted Roll: "<<roll<<"\n";
        }
        void showInfo(){
            cout<<"\nRoll: "<<roll<<"\n";
            cout<<"Name: "<<name<<"\n";
            cout<<"Score: "<<score<<"\n";
        }
        int returnScore() const{ //accessor function which returns score of student
            return score;
        }
        string returnName() const{ //accessor function which returns name of student
            return name;
        }

};


//overloaded function object to compare score before finding max from the list
class findmax{
    public:
        bool operator()(const Student& s1, const Student& s2){
            return (s1.returnScore() < s2.returnScore());
        }
};


//overloaded function object to check if a substring is present in a string, if present return true
class checkWithSubString{
        string s;
    public:
        checkWithSubString(string temp){
            s = temp;
        }
        bool operator()( const Student& S){
            int index;
            index = S.returnName().find(s, 0);
            if(index != string::npos)
                return true;
            return false;
        }
};


//overloaded function object to check if a substring is present in a string, if not present return true
class checkWithoutSubString{
        string s;
    public:
        checkWithoutSubString(string temp){
            s = temp;
        }
        bool operator()( const Student& S){
            int index;
            index = S.returnName().find(s, 0);
            if(index != string::npos)
                return false;
            return true;
        }
};


//stores an array of student objects
class StudentList{
        vector<Student> sl;
        static int lastroll;
    public:
        
        void addStudent(){
            Student s;
            lroll++;
            s.getInfo(lroll);
            sl.push_back(s);
        }

        void showTopperDetails(){
            vector<Student>::iterator it;

            //finds the reference for student with maximum score in the vector of students by using a function object
            it = max_element(sl.begin(), sl.end(), findmax());  
            (*it).showInfo();
        }

        void showStudentByName(string s){
            vector<Student>::iterator it;

            //finds the reference to the student(s) which has the substring
            it = find_if(sl.begin(), sl.end(), checkWithSubString(s));  
            if(it != sl.end()){
                cout<<"Match Found!\n\n";
                (*it).showInfo();
                while(it!=sl.end()){
                    it = find_if(it+1, sl.end(), checkWithSubString(s));
                    if(it != sl.end())
                        (*it).showInfo();
                }
            }
            else{
                cout<<"Match Not Found!!\n";
                return;
            }
        }

        void showStudentWithoutName(string s){
            vector<Student>::iterator it;

            //finds the reference to the student(s) which does not has the substring
            it = find_if(sl.begin(), sl.end(), checkWithoutSubString(s));
            if(it != sl.end()){
                cout<<"The Students not having this substring are:\n";
                (*it).showInfo();
                while(it!=sl.end()){
                    it = find_if(it+1, sl.end(), checkWithoutSubString(s));
                    if(it != sl.end())
                        (*it).showInfo();
                }
            }
            else{
                cout<<"Match Not Found!!\n";
                return;
            }
            
            
        }

        //returns current size of vector
        int showsize(){
            return sl.size();
        }

};
int lroll=0;

int main(){
    StudentList SL;
    int ch;
    string subs;
    cout<<"****STUDENT MANAGEMENT****\n\n";

    //menu of operations
    do{
        cout<<"\n1. Add Student.\n";
        cout<<"2. Show Current Number of Students.\n";
        cout<<"3. Show Topper Info.\n";
        cout<<"4. Find Student By Name.\n";
        cout<<"5. Find Student Without Name.\n";
        cout<<"6. Exit.\n";
        cout<<"Enter Your Choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                SL.addStudent();
                break;
            case 2:
                cout<<"Current Registered Number of Students: "<<SL.showsize()<<"\n";
                break;
            case 3:
                //checks if the vector is empty, prints appropriate message
                if(!SL.showsize()){
                    cout<<"No Students Added!\n";
                    break;
                }
                cout<<"Student with Highest Score:\n";
                SL.showTopperDetails();
                break;
            case 4:
                cout<<"\nEnter Sub-String to be Searched: ";
                cin>>subs;
                SL.showStudentByName(subs);
                break;
            case 5:
                cout<<"\nEnter Sub-String to be Searched: ";
                cin>>subs;
                SL.showStudentWithoutName(subs);
                break;
            case 6:
                exit(0);
                break;
            default:
                cout<<"Please enter a choice from the given menu!\n";
        }
    }while(ch!=6);

    return 0;
}