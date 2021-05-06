#include<iostream>
#include<string.h>
using namespace std;

class String{
    char* c;
    int size;
    int *p;
    public:
        String(int s=0){ //constructor
            size=s;
            if(s==0)
                c=NULL;
            else{
                c=new char[size];
                c[0]='\0';
            }
            p=new int;
            *p=1;
        }
        String(const String& s){ //copy constructor
            size=s.size;
            c=s.c;
            p=s.p;
            (*p)++;
        }
        void operator=(String s){ //overloading operator =
            if(c!=NULL)
                (*p)--;
            if((*p)==0){
                delete[] c;
                delete p;
            }
            c=s.c;
            size=s.size;
            p=s.p;
            (*p)++;
        }
        ~String(){ //destructor
            (*p)--;
            if((*p)==0){
                delete p;
                delete[] c;
            }
        }
        void const showInstanceCount(){  //to print number of active instances
            cout<<"ACTIVE: "<<(*p)<<endl;
        }
};

int main(){
    String s1(10);
    String s2(s1);
    String s4(3);
    s1.showInstanceCount();
    s2.showInstanceCount();
    s4.showInstanceCount();
}