#include<iostream>
using namespace std;

#define nstu student_list::no_of_students
#define nsub subject_list::no_of_subjects
#define nsubstu subject::no_of_students 

class subject{  //stores details of each subject
    static int no_of_students;
    int code;
    char name[11];
    public:
        void displayStudents(int);
        friend class subject_list;
        friend class student;
        friend class student_list;
};

class subject_list{  //maintains a list for each student
    static int no_of_subjects;
    subject list[100];
    public:
        void addSubject();
        friend class student;
        friend class student_list;

};

class student{ //stores details of each student
    int roll;
    char name[31];
    char phone[11];
    subject_list subs;
    public:
        friend class student_list;
};

class student_list{ //maintains a student list
    static int no_of_students;
    student list[100];
    public:
        void addStudent();
        void displaySub(int);
        void displayStudents(string);

};

int student_list::no_of_students = 0;
int subject_list::no_of_subjects=0;
int subject::no_of_students=0;


void student_list::addStudent(){ //adds student
    if(nstu>100){
        cout<<"STUDENT LIMIT REACHED. PLEASE CONTACT DEAN.\n";
        return;
    }
    ++nstu;
    int ch;
    list[nstu].roll=nstu;
    cout<<"Enter Student Details:\n";
    cout<<"Name: ";
    cin>>list[nstu].name;
    cout<<"Phone No.: ";
    cin>>list[nstu].phone;
    do{
        list[nstu].subs.addSubject();
        cout<<"Press 1 to add another subject, 0 to end: ";
        cin>>ch;
    }while(ch!=0);
    cout<<"Alloted Roll of Student: A00"<<list[nstu].roll<<"\n";
}

void subject_list::addSubject(){  //adds subject for student
    if(nsub>100){
        cout<<"SUBJECT LIMIT EXCEEDED. PLEASE CONTACT DEAN.\n";
        return;
    }
    ++nsub;
    list[nsub].code=nsub;
    cout<<"Enter Subject Name: ";
    cin>>list[nsub].name;
    cout<<"Subject Code: S00"<<list[nsub].code<<"\n";
}



void student_list::displaySub(int a){  //display subjects of a student
    if(a<=0 || a>nstu){
        cout<<"Invalid Roll Number!\n";
        return;
    }
    cout<<"Subjects chosen by the student are:\n";
    for(int i=1;i<=list[a].subs.no_of_subjects;i++)
        cout<<list[a].subs.list[i].name<<"\n";
}


void student_list::displayStudents(string a){ //displays students for a subject
    cout<<"Students are:\n";
    for(int i=1;i<=nstu;i++){
        for(int j=1;j<=nsub;j++)
            if(list[i].subs.list[j].name==a)
                cout<<list[i].name<<"\n";
    }
}

int main(){
    student_list ob; //student list
    int ch;
    string stu_code;
    string sub;
    //menu
    do{
        cout<<"\n***STUDENT ADMISSION SYSTEM***\n\n";
        cout<<"1. ADD STUDENT.\n";
        cout<<"2. DISPLAY STUDENT'S SUBJECTS.\n";
        cout<<"3. DISPLAY STUDENTS AGAINST A SUBJECT.\n";
        cout<<"4. EXIT.\n";
        cout<<"Enter Your Choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                ob.addStudent();
                break;
            case 2:
                cout<<"Enter Roll (in format A00X): ";
                cin>>stu_code;
                ob.displaySub(stu_code[3] - '0');
                break;
            case 3:
                cout<<"Enter Subject Name: ";
                cin>>sub;
                ob.displayStudents(sub);
                break;
            case 4:
                exit(0);
                break;
            default:
                cout<<"INVALID CHOICE!!\n";
        }
    }while(ch!=4);

    return 0;
}