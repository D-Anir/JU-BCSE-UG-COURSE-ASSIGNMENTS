#include<iostream>
#include<map>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> roll_array;


//stores student details
class Student{
        int roll;
        string name;
        int score;
    public:
        
        int getInfo(){
            cout<<"Enter Roll: ";
            cin>>roll;
            
            vector<int>::iterator it;
            it = find(roll_array.begin(), roll_array.end(), roll);
            
            //check for duplicate roll
            if(it == roll_array.end())
                roll_array.push_back(roll);
            else{
                return -1;
            }

            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Enter Score: ";
            cin>>score;
            return roll;
        }
        
        void displayInfo(){
            cout<<"Name: "<<name<<"\n";
            cout<<"\tScore: "<<score<<"\n";
        }
        
        int returnRoll() const{ //accessor function to return roll of student
            return roll;
        }
        
        int returnScore() const{  //accessor function to return score of student
            return score;
        }
};

//overloading the < operator to make rolls of student the keys of map and store in ascnding order 
bool operator<(const Student& s1, const Student& s2){
    return s1.returnRoll() < s2.returnRoll() ;
}

class StudentMap{
        map<int, Student> M_stu;
    public:
        
        void addStudent(){
            Student s;
            int r = s.getInfo();
            
            //check for duplicate roll
            if(r < 0){
                cout<<"Roll Already Exists! Previous Data will be Lost!\n";
                return;
            }
            
            M_stu.insert(pair<int, Student>(r, s));
        }
        
        void displayAllStudents(){
            map<int, Student>::iterator it;
            cout<<"\nThe Student Map(with roll as key) looks like this:\n";
            cout<<"\nRoll\tDetails\n\n";
            
            for(it = M_stu.begin(); it != M_stu.end(); it++){
                cout<<it->first<<"\t";
                (it->second).displayInfo();
                cout<<"\n";
            }
            
            cout<<"\n";
        }
        
        //returns current size of the map
        int returnSize(){
            return M_stu.size();
        }
};

int main(){
    StudentMap SM;
    int ch;
    roll_array.clear();
    
    //menu
    do{
        cout<<"\n1. Add Student.\n";
        cout<<"2. Display All Students in Ascending Order of Roll.\n";
        cout<<"3. Exit.\n";
        cout<<"Enter Your Choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                SM.addStudent();
                break;
            case 2:
                //check for empty map
                if(!SM.returnSize()){
                    cout<<"No Student Added!\n";
                    break;
                }
                SM.displayAllStudents();
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