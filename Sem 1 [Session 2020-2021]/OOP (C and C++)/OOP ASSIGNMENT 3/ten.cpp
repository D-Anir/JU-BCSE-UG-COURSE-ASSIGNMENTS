//implenting stack using array in cpp

#include<iostream>

#define SIZE 100
 
using namespace std;
 
class STACK
{
        int num[SIZE];
        int top;
    public:
        STACK();    
        int push(int);
        int pop();
        int isEmpty();
        int isFull();
        void displayItems();
};
STACK::STACK(){ //default constructor
    top=-1;
}
 
int STACK::isEmpty(){ //to check if the stack is empty
    if(top==-1)
        return 1;
    else
        return 0;   
}
 
int STACK::isFull(){  //to check if the stack is full
    if(top==(SIZE-1))
        return 1;
    else
        return 0;
}
 
int STACK::push(int n){ //push an element in stack
    if(isFull()){
        return 0;
    }
    ++top;
    num[top]=n;
    return n;
}
 
int STACK::pop(){ //to pop the top element from the stack
    int temp;
    if(isEmpty())
        return 0;
    temp=num[top];
    --top;
    return temp;
     
}
 
void STACK::displayItems(){ //to display stack
    int i;
    cout<<"STACK is: ";
    for(i=(top); i>=0; i--)
        cout<<num[i]<<" ";
    cout<<endl;
}
 
int main(){
    STACK stk;
    int ch, n,temp;
     
    do{
        cout<<endl;
        cout<<"1. Push Item."<<endl;
        cout<<"2. Pop Item."<<endl;
        cout<<"3. Display Items."<<endl;
        cout<<"4. EXIT."<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
         
        switch(ch){
            case 0: break;
             
            case 1:
                cout<<"Enter item to insert: ";
                cin>>n;
                temp=stk.push(n);
                if(temp==0)
                    cout<<"STACK is FULL."<<endl;
                else
                    cout<<temp<<" inserted."<<endl;
                break;
                 
            case 2:
                temp=stk.pop();
                if(temp==0)
                    cout<<"STACK IS EMPTY."<<endl;
                else
                    cout<<temp<<" is removed (popped)."<<endl;
                break;
             
            case 3:
                stk.displayItems();
                break;
            
            case 4:
                exit(0);
                break;
                
            default:
                cout<<"An Invalid choice."<<endl;
        }   
    }while(ch!=0);
 
    return 0;    
}