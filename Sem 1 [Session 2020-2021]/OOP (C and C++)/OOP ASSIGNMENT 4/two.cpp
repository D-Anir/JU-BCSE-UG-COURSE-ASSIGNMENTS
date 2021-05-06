#include<iostream>
using namespace std;

class complex{
        int real;
        int img;
    public:
        complex(int a=0, int b=0){  //parameterized constructor
            real=a;
            img=b;
        }
        complex operator+(complex c){  //overloading + operator
            complex t;
            t.real = real + c.real;
            t.img = img + c.img;
            return t;
        }
        complex operator-(complex c){  //overloading - operator
            complex t;
            t.real = real - c.real;
            t.img = img - c.img;
            return t;
        }
        friend ostream& operator<<(ostream &o, complex c){  //overloading << operator
            o<<"The resultant complex number is: "<<c.real<<" + "<<c.img<<"i\n";
            return o;
        }
        friend istream& operator>>(istream &i, complex &c){  //overloading >> operator
            cout<<"Real: ";
            i>>c.real;
            cout<<"Imag: ";
            i>>c.img;
            return i;
        }
};



int main(){
    int a,b;
    complex c1,c2;
    cout<<"Enter complex numbers:\n";
    cin>>c1;
    cin>>c2;
    complex c3;
    c3=c1+c2; //adds both complex number objects
    cout<<c3;
    c3=c1-c2; //subtracts c2 fro c1
    cout<<c3;
    return 0;
}
