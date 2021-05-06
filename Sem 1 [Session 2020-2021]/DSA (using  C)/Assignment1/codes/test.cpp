#include<iostream>
using namespace std;

class S{
    static int j;
    int k;
    public:
        S(int i=0){
            k=i;
            S::j++;
        }
        void operator++(){
            k=k+1;
        }
        void Display(){
            cout <<"j="<<S::j;
            cout<<"\nK="<<k;
        }
};
int S::j=1;
int main(){
    S s1;
    ++s1;
    s1.Display();
    // S s2;
    // s2.Display();
    // S s3,s4,s5;
    // s4.Display();
    // s5.Display();
    // S s[10];
    // for(int i=0;i<10;i++)
    //     s[i].Display();
}