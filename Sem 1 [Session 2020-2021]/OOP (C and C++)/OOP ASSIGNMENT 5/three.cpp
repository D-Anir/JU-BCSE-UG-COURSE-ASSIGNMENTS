#include<iostream>
using namespace std;


//stores employee details
class employee{
        int emp_id;
        char name[31];
        char designation[10];
        int basic_pay;
    public:
        virtual void getInfo(){
            cout<<"Enter Id: ";
            cin>>emp_id;
            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Enter Designation: ";
            cin>>designation;
            cout<<"Enter Basic Pay: ";
            cin>>basic_pay;
        }
        virtual float computeSalary(){
            return basic_pay;
        }
};


//permanent employees
class permanent:public employee{ //inherits from employee
        float salary;
    public: 
        float computeSalary(){  //calculates salary
            salary=employee::computeSalary();
            float hra = (salary*0.3);
            float da = (salary*0.8);
            salary += da+hra;
            return salary;
        }
};


//contractual employees
class contractual:public employee{ //inherits from employee
        float salary;
        float allowance;
    public:
        void getInfo(){
            employee::getInfo();
            cout<<"Enter Allowance: ";
            cin>>allowance;
        }
        float computeSalary(){  //calculates salary
            salary = employee::computeSalary();
            salary += allowance;
            return salary;
        }
};

int main(){
    employee *ob;
    float sal;

    ob = new permanent; //permanent employee instance
    ob->getInfo();
    sal = ob->computeSalary();
    cout<<"SALARY= "<<sal<<"\n";
    
    cout<<endl;
    
    ob = new contractual;  //contractual employee instance
    ob->getInfo();
    sal = ob->computeSalary();
    cout<<"SALARY= "<<sal<<"\n";
    
    return 0;
}