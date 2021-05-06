#include<iostream>
using namespace std;

class Node{
    public:
        int info;
        Node *adr;
};

class LINKED_LIST{
    public:
        Node *head;
        LINKED_LIST(){
            head=NULL;
        }
        void addNode(int);
        void display();
        void deleteNode(Node **, int);
};

void LINKED_LIST::addNode(int n){  //adds node
    Node* newnode=new Node;
    newnode->info=n;
    newnode->adr=NULL;
    if(head==NULL)
        head=newnode;
    else{
        Node* temp=head;
        while(temp->adr!=NULL)
            temp=temp->adr;
        temp->adr=newnode;
    }
}

void LINKED_LIST::deleteNode(Node **head, int key){  //deletes node
    Node* temp=*head;
    Node* prev=NULL;
    if(temp!=NULL && temp->info==key){
        *head=temp->adr;
        delete temp;
        return;
    }

    while (temp!=NULL && temp->info!=key) 
    { 
        prev = temp; 
        temp = temp->adr; 
    }

    if (temp == NULL) 
        return; 
  
    prev->adr = temp->adr; 
  
    delete temp; 
}

void LINKED_LIST::display(){  //display list
    if(head==NULL)
        cout<<"THE LIST IS EMPTY!"<<endl;
    else{
        Node* temp=head;
        cout<<"\nTHE CURRENT LIST LOOKS LIKE: ";
        while(temp!=NULL){
            cout<<temp->info<<" ";
            temp=temp->adr;
        }
        cout<<endl;
    }
}

int main(){
    LINKED_LIST* list=new LINKED_LIST;
    int n,ch,key;

    do{
        cout<<"\n***LINKED LIST***\n\n";
        cout<<"1. ADD ELEMENT.\n";
        cout<<"2. DELETE ELEMENT.\n";
        cout<<"3. DISPLAY LIST.\n";
        cout<<"4. EXIT.\n";
        cout<<"Enter Your Choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter the element to push: ";
                cin>>n;
                list->addNode(n);
                break;
            case 2:
                cout<<"Enter the element to be popped: ";
                cin>>key;
                list->deleteNode(&list->head,key);
                cout<<"\nDesired Node Deleted...\n";
                list->display();
                break;
            case 3:
                list->display();
                break;
            case 4:
                cout<<"*PROGRAM ENDED*\n";
                break;
            default:
                cout<<"Invalid Choice!!\n";
        }
    }while(ch!=4);

    return 0;
}