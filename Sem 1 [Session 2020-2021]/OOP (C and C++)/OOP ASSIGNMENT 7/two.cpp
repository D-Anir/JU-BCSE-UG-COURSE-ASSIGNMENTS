#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

#define lroll1  StudentList::lastrollinlist1
#define lroll2  StudentList::lastrollinlist2

//stores details of each student
class Student{
        int roll;
        string name;
        int score;
        char section;
    public:
        void getInfo(int r, int s){
            cout<<"\nEnter Name: ";
            cin>>name;
            cout<<"Enter Score: ";
            cin>>score;
            roll = r;
            cout<<"Alotted Roll: "<<roll<<"\n";
            if(s==1)
                section='A';
            else
                section='B';
            cout<<"Section: "<<section<<endl;
        }
        void showInfo(){
            cout<<"\nRoll: "<<roll<<"\n";
            cout<<"Name: "<<name<<"\n";
            cout<<"Secton: "<<section<<"\n";
            cout<<"Score: "<<score<<"\n";
        }
        int returnScore() const{  //accessor function which returns score of student
            return score;
        }
        string returnName() const{  //accessor function which returns name of student
            return name;
        }
        int returnRoll() const{  //accessor function which returns roll of student
            return roll;
        }

};

//overloaded function object to sort in according to score
class findmax{
    public:
        bool operator()( const Student& s1, const Student& s2){
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
        bool operator()( const Student& S ){
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
        bool operator()(const Student& S){
            int index;
            index = S.returnName().find(s, 0);
            if(index != string::npos)
                return false;
            return true;
        }
};

//overloaded function object to find student with desired roll
class findStudentWithRoll{
        int r;
    public:
        findStudentWithRoll(int roll){
            r = roll;
        }
        bool operator()(const Student& s){
            return (s.returnRoll() == r) ;
        }
};

//overloaded function object compare students by roll
class sortByRoll{
    public:
        bool operator()(const Student& s1, const Student& s2){
            return s1.returnRoll() > s2.returnRoll();
        }
};

//overloaded function object to compare students by their score
class sortByScore{
    public:
        bool operator()(const Student& s1, const Student& s2){
            return s1.returnScore() > s2.returnScore();
        }
};

//stores arrays of student objects
class StudentList{
        vector<Student> sl1;
        vector<Student> sl2;
        static int lastrollinlist1;
        static int lastrollinlist2;
    public:
        
        void addStudent(int sec){
            Student s;
            if(sec==1){
                lroll1++;
                s.getInfo(lroll1, sec);
                sl1.push_back(s);
            }
            else{
                lroll2++;
                s.getInfo(lroll2, sec);
                sl2.push_back(s);
            }
        }

        void showTopperDetails(){
            vector<Student>::iterator it;

            //finds the reference for student with maximum score in the vector of students by using a function object
            it = max_element(sl1.begin(), sl1.end(), findmax());
            (*it).showInfo();
        }

        void showStudentByName(string s){
            vector<Student>::iterator it;

            //finds the reference to the student(s) which has the substring
            it = find_if(sl1.begin(), sl1.end(), checkWithSubString(s));
            if(it != sl1.end()){
                cout<<"Match Found!\n\n";
                (*it).showInfo();
            }
            else{
                cout<<"Match Not Found!!\n";
                return;
            }
        }

        void showStudentWithoutName(string s){
            vector<Student>::iterator it;

            //finds the reference to the student(s) which does not has the substring            
            it = find_if(sl1.begin(), sl1.end(), checkWithoutSubString(s));
            if(it != sl1.end()){
                cout<<"The Students not having this substring are:\n";
                (*it).showInfo();
                while(it!=sl1.end()){
                    it = find_if(it+1, sl1.end(), checkWithoutSubString(s));
                    if(it != sl1.end())
                        (*it).showInfo();
                }
            }
            else{
                cout<<"Match Not Found!!\n";
                return;
            }
            
            
        }


        //removes student with desired roll
        void removeStudent(int r){
            vector<Student>::iterator it;

            //finds the reference to the student with the given roll
            it = find_if(sl1.begin(), sl1.end(), findStudentWithRoll(r));
            if(it == sl1.end()){
                cout<<"Student Not Found!\n";
                return;
            }
            else{
                //physical deletion of the student object from the vector
                sl1.erase(it); 
                vector<Student>::iterator temp;
                cout<<"The Current List is:\n";
                for(temp = sl1.begin(); temp != sl1.end(); temp++){
                    (*temp).showInfo();
                    cout<<"\n";
                }
            }
        }

        //sorts the students according to their roll or score according to choice
        void sortListInDescending(int choice){
            if(choice==0){
                sort(sl1.begin(), sl1.end(), sortByRoll()); //calls the ovrloaded sortByRoll function object
            }
            else{
                sort(sl1.begin(), sl1.end(), sortByScore()); //calls the ovrloaded sortByScore function object
            }
            vector<Student>::iterator temp;
            cout<<"The Current List is:\n";
            for(temp = sl1.begin(); temp != sl1.end(); temp++){
                (*temp).showInfo();
                cout<<"\n";
            }
        }

        //combines both the sections and appends it to a single vector
        void combineSections(){
            vector<Student> combined;
            cout<<"The Combined List is:\n";
            sort(sl1.begin(), sl1.end(), sortByScore());
            sort(sl2.begin(), sl2.end(), sortByScore());

            combined.reserve( sl1.size() + sl2.size() ); //adjusts the size of the vector to keep both the sections
            combined.insert(combined.end(), sl1.begin(), sl1.end()); //students of section 1 are inserted
            combined.insert(combined.end(), sl2.begin(), sl2.end()); //students of section 2 are inserted
            
            vector<Student>::iterator temp;
            for(temp = combined.begin(); temp < combined.end(); temp++){
                (*temp).showInfo();
            }
            cout<<"\n";
        }

        //returns current size of vector
        int showsize(){
            return sl1.size();
        }

};
int lroll1=0;
int lroll2=0;

int main(){
    StudentList SL;
    int ch, roll, sortchoice, section;
    string subs;
    cout<<"****STUDENT MANAGEMENT****\n\n";
    
    //menu
    do{
        cout<<"\n1. Add Student.\n";
        cout<<"2. Show Current Number of Students.\n";
        cout<<"3. Show Topper Info.\n";
        cout<<"4. Find Student By Name.\n";
        cout<<"5. Find Student Without Name.\n";
        cout<<"6. Remove a Student.\n";
        cout<<"7. Sort the List.\n";
        cout<<"8. Combine Both Lists.\n";
        cout<<"9. Exit.\n";
        cout<<"Enter Your Choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"In Section 1 or In Section 2: ";
                cin>>section;
                SL.addStudent(section);
                break;
            case 2:
                cout<<"Current Registered Number of Students: "<<SL.showsize()<<"\n";
                break;
            case 3:
                //check for empty vector
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
                //check for empty vector
                if(!SL.showsize()){
                    cout<<"No Students Added!\n";
                    break;
                }
                cout<<"Enter Roll to be Removed: ";
                cin>>roll;
                SL.removeStudent(roll);
                break;
            case 7:
                cout<<"Sort By Score(1) or Roll(0): ";
                cin>>sortchoice;
                SL.sortListInDescending(sortchoice);
                break;
            case 8:
                SL.combineSections();
                break;
            case 9:
                exit(0);
                break;
            default:
                cout<<"Please enter a choice from the given menu!\n";
        }
    }while(ch!=9);
}