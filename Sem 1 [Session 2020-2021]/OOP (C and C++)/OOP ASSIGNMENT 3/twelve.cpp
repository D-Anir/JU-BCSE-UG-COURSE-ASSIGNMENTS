//student database in cpp

#include<iostream>
using namespace std;

class Student{
        static int last_roll;
        int roll;
        char name[31];
        string course;
        int dd;
        int mm;
        int yy;
        int marks[5];
    public:
        Student() //default constructor
        {
            roll = dd = mm = yy = -1;
            for (int i = 0; i < 5; ++i) {
                marks[i] = -1;
            }
        }
        void add();
	    void in_marks();
	    bool check_marks();
	    void marksheet();
	    static int numOfStudents(){ //to print the static variable
            return last_roll;
        }
};

int Student::last_roll = 0;

void Student::add(){  //add student details
    cout<<"\nEnter date of addmission:\n";
    cout<<"Day: ";
    cin>>dd;
    cout<<"Month: ";
    cin>>mm;
    cout<<"Year: ";
    cin>>yy;
    cout<<"Enter Name of Student: ";
    cin>>name;
    cout<<"Enter Course Name: ";
    cin>>course;
    Student::last_roll++;
    roll=Student::last_roll;
    cout<<"Allotted Roll No. of "<<name<<" is: "<<roll;
}

void Student::in_marks(){  //add mrks
    cout<<"Enter Marks in 5 subjects:\n";
    for(int i=0;i<5;i++){
        cout<<"Subject "<<i+1<<": ";
        cin>>marks[i];
    }
}


bool Student::check_marks(){  //check if marks entered or not
    for(int i=0;i<5;i++){
        if(marks[i]<0){
            return 0;
        }
    }
    return 1;
}

void Student::marksheet(){  //to create marksheet
    if(!check_marks()){
        cout<<"MARKS NOT ENTERED!!\n";
        return;
    }
    cout<<"\n\t\t\tMARKSHEET\n";
    cout<<"********************************************************************\n";
	cout<<"NAME - "<<name<<"\n";
	cout<<"Roll - "<<roll<<"\n";
	cout<<"Dept - "<<course<<"\n";
	cout<<"Date of admission(dd / mm / yyyy): "<<dd<<"/"<<mm<<"/"<<yy<<"\n";
	cout<<"Marks: \n";
	for(int i = 0; i < 5; ++i) {
		cout<<"\tSubject "<<(i + 1)<<": "<<marks[i]<<"\n";
	}
	cout<<"********************************************************************\n";
}

class batch{
        Student list[100];
    public:
        int enter_roll();
        void menu();
};

int batch::enter_roll(){  //check if student with entered roll exists
    cout<<"\nEnter roll of the student: ";
    int r;
    cin>>r;
    if (r>0 && r<=Student::numOfStudents()) {
		return r;
	}
    else{
		cout<<"Invalid Roll Entered!!\n";
		return 0;
	}
}

void batch::menu(){  //menu to display in the dashboard
    int ch;
    do {
		cout<<"\n\n\t***STUDENT MANAGEMENT SYSTEM***\n";
		cout<<"\n1. Admit Student.\n";
		cout<<"2. Number of Admitted Students.\n";
		cout<<"3. Enter Marks of an admitted student.\n";
		cout<<"4. Print Marksheet of an admitted student.\n";
		cout<<"5. Exit.\n";
        cout<<"Enter Your Choice: ";
		cin>>ch;
		int r;
		switch(ch){
		case 1:
            list[Student::numOfStudents()].add();
			break;
		case 2:
            cout<<"\nNumber of students currently admitted: "<<Student::numOfStudents()<<"\n";
			break;
		case 3:
            r=enter_roll();
			if(r){
				list[r - 1].in_marks();
			}
			break;
		case 4:
            r=enter_roll();
			if(r){
				list[r - 1].marksheet();
			}
			break;
		case 5:
            exit(0);
			break;
		}
	}while(ch!=5);
}

int main(){
    batch cse;
    cse.menu();
    return 0;
}