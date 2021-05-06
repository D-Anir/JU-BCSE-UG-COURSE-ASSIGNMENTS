#include<iostream>
using namespace std;

//class template for array of elements with type X
template < class X >
class Array{
        X *arr;
        int size;
    public:
        Array(int s=0){ //constructor
            if(s==0)
                arr=NULL;
            else
                arr = new X(s);
            size=s;
        }
        void getData(){
            cout<<"Enter Data:\n";
            for(int i=0;i<size;i++)
                cin>>arr[i];
        }
        X findMax(){  //finds max of all elements
            X max=arr[0];
            for(int i=1;i<size;i++){
                if(arr[i]>max)
                    max=arr[i];
            }
            return max;
        }
        X findSum();
};


//function template defined explicitly for return type T
template < class T >
T Array < T > ::findSum(){  //returns sum of all elements
    T sum=0;
    for(int i=0;i<size;i++)
        sum += arr[i];
    return sum;
}

int main(){
    
    cout<<"INTEGER ARRAY:\n";
    Array < int > ob1(5); //array of 5 integers
    ob1.getData();
    cout<<"Max Element is: "<<ob1.findMax()<<"\n";
    cout<<"Sum of elements is: "<<ob1.findSum()<<"\n";

    cout<<"\nFLOAT ARRAY:\n";
    Array < float > ob2(3); //array of 3 floats
    ob2.getData();
    cout<<"Max Element is: "<<ob2.findMax()<<"\n";
    cout<<"Sum of elements is: "<<ob2.findSum()<<"\n";    
    
    cout<<"\nCHARACTER ARRAY:\n";
    Array < char > ob3(4);  //array of 4 characters
    ob3.getData();
    cout<<"Max Element is: "<<ob3.findMax()<<"\n";
    cout<<"Sum of elements is: "<<(int)ob3.findSum()<<"\n";
    
    return 0;
}
