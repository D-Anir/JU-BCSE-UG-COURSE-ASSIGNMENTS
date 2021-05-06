#include<iostream>
using namespace std;

#define nob booklist::noofbooks
#define nos studentlist::noofstudents
#define nof facultylist::nooffaculties
#define notra transactionlist::nooftransactions

class booklist;


//book details
class book{
        int serial;
        int bookid;
        char title[21];
        char author[31];
        char publisher[31];
        int price;
    public:
        book(){
            serial=1;
        }
        void getInfo(int id){
            cout<<"Enter Book Details:\n";
            cout<<"Title: ";
            cin>>title;
            cout<<"Author: ";
            cin>>author;
            cout<<"Publisher: ";
            cin>>publisher;
            cout<<"Price: ";
            cin>>price;
            id++;
            bookid=id;
            cout<<"Book-ID: "<<bookid<<endl;
        }
        int returnid(){ //returns book id
            return bookid;
        }
        int returnserial(){ //returns current number of copies
            return serial;
        }
        friend class booklist;
        friend class transactionlist;
};

//member details
class member{
    protected:
        int memberid;
        char name[31];
        char email[21];
        char address[51];
        int numberofbooks;
        int borrowed[11];
    public:
        void getInfo(){
            cout<<"Enter Member Details:\n";
            cout<<"Name: ";
            cin>>name;
            cout<<"Email: ";
            cin>>email;
            cout<<"Address: ";
            cin>>address;
        }
        
        int returnmemid(){  //returns member id
            return memberid;
        }
        friend class transactionlist;
};

//inherited from member
class student:public member{ 
    public:
        student(){ //constructor
            numberofbooks=0;
        }
        int checkIssue(){  //checks if anymore issue is possible
            if(numberofbooks>2){
                cout<<"NO MORE BOOKS CAN BE ISSUED!\n";
                return 0;
            }
            return 1;
        }
        friend class studentlist;
};


//inherited from member
class faculty:public member{ 
    public:
        faculty(){
            numberofbooks=0;
        }
        int checkIssue(){   //checks if anymore issue is possible
            if(numberofbooks>10){
                cout<<"NO MORE BOOKS CAN BE ISSUED!\n";
                return 0;
            }
            return 1;
        }
        friend class facultylist;
};

//stores transaction details
class transaction{
        char date[11];
        int memberid;
        int bookid;
        int isreturned;
    public:
        void getInfo(int nb, book L[]){  //gets transaction details
            cout<<"Enter Transaction Details:\n";
            cout<<"Member-Id: ";
            cin>>memberid;
            cout<<"Book-Id: ";
            cin>>bookid;
            int f=0;
            for(int i=0;i<nb;i++){  //to check if book exists or not, displays error if doesn't
                if(bookid==L[i].returnid()){
                    if(L[i].returnserial()<1){
                        f=1;
                        break;
                    }
                }
            }
            if(f==1){
                cout<<"Book Not Available!\n";
                return;
            }
            cout<<"Date: ";
            cin>>date;
            isreturned=0;
        }
        int returnbookid(){
            return bookid;
        }
        int memid(){ //returns member id of the user
            return memberid;
        }
};



//stores list of book objects
class booklist{
        static int noofbooks;
        book list[100];
    public:
        void addBook(){
            if(nob>100){
                cout<<"Book Limit Reached! Contact the Librarian.\n";
                return;
            }
            int f=0;
            list[nob].getInfo(nob);
            nob++;
            cout<<"Book Added!\n";
        }
        void addexisting(int id){  //updates stock of existing book
            if(id>nob){
                cout<<"INVALID ID!\n";
                return;
            }
            int qnty;
            cout<<"Enter Quantity to Stock Up: ";
            cin>>qnty;
            list[id].serial=list[id].serial+qnty;
            cout<<"Stocked Up!\n";
        }
        void showBook(int i){
            cout<<"SERIAL: "<<list[i].serial;
        }
        book* returnbooklist(){
            return list;
        }
        int returnnob(){  //returns number of books
            return nob;
        }
        void checkAvailable(int id){  //check if the book is in stock, displays appropriate message
            int flag=0;
            for(int i=0;i<nob;i++){
                if(list[i].bookid==id){
                    if(list[id].serial<1){
                        cout<<"Book Not Available! Kindly Re-stock.\n";
                        flag=1;
                        break;
                    }
                    else{
                        cout<<"Book Available! Copies Remmaining: "<<list[id].serial;
                        flag=1;
                        break;
                    }
                }
            }
            if(!flag)
                cout<<"Invalid Book-Id!\n";
        }
        void updatebooklist(int id, int isreturn){  //updates book stock
            if(isreturn)
                list[id].serial++;
            else
                list[id].serial--;
        }
        friend class book;
};
int booklist::noofbooks = 0;


//stores list of student objects
class studentlist{
        static int noofstudents;
        student list[100];
    public:
        void addStudent(){
            if(nos>100){
                cout<<"Student Limit Reached! Contact the Librarian.\n";
                return;
            }
            list[nos].getInfo();
            list[nos].memberid=nos+1;
            cout<<"Student Member Id: "<<list[nos].memberid<<endl;
            nos++;
            cout<<"Student Added!\n";
        }
        student* returnstudentlist(){
            return list;
        }

        void showborrowed(int id){  //displays borrow history of student
            for(int i=0;i<list[id].numberofbooks;i++){
                cout<<"BOOK-ID: "<<list[id].borrowed[i]<<endl;
            }
        }

        static int returnstudents(){
            return noofstudents;
        }
};
int studentlist::noofstudents=0;


//stores list of faculty objects
class facultylist{
        static int nooffaculties;
        faculty list[100];
    public:
        void addFaculty(){
            if(nof>100){
                cout<<"Faculty Limit Reached! Contact the Librarian.\n";
                return;
            }
            list[nof].getInfo();
            list[nof].memberid=nof+1;
            cout<<"Faculty Member Id: "<<list[nof].memberid<<endl;
            nof++;
            cout<<"Faculty Added!\n";
        }
        faculty* returnfacultylist(){
            return list;
        }

        void showborrowed(int id){  //displays borrow history of faculty
            for(int i=0;i<list[id].numberofbooks;i++){
                cout<<"BOOK-ID: "<<list[id].borrowed[i]<<endl;
            }
        }

        static int returnfaculties(){
            return nooffaculties;
        }
};
int facultylist::nooffaculties=0;


//stores list of transaction objects
class transactionlist{
        static int nooftransactions;
        transaction list[100];
        int canborrow;
    public:
        int addTransaction(booklist ob){
            if(notra>100){
                cout<<"Transaction Limit Reached! Contact the Librarian.\n";
                return -1;
            }
            int n=ob.returnnob();
            book *l;
            l=ob.returnbooklist();
            list[notra].getInfo(n, l);
            notra++;
            return (notra-1);
        }
        
        //issues book to student
        void studentissued(booklist ob, book L[], int n, int transNo, student l[]){
            int k=list[transNo].returnbookid();
            for(int i=0;i<n;i++){
                if(L[i].returnid()==k){
                    int j=list[transNo].memid();
                    if(l[j].numberofbooks<2 && L[k].serial>=1){
                        l[j].borrowed[l[j].numberofbooks]=k;
                        l[j].numberofbooks++;
                        L[k].serial--;
                    }
                    else{
                        cout<<"MAX ISSUE LIMIT REACHED!\n";
                        return;
                    }
                }
            }
            cout<<"Book Issued to Student!\n";
        }

        //returns book from student
        void studentreturned(booklist ob, book L[], int n, int transNo, student l[]){
            int k = list[transNo].returnbookid();
            for(int i=0;i<n;i++){
                if(L[i].returnid()==k){
                    int j=list[transNo].memid();
                    if(l[j].numberofbooks<1){
                        cout<<"No Books to Return!\n";
                        return;
                    }
                    l[j].numberofbooks--;
                    L[k].serial++;
                }
            }
            cout<<"Book Returned Successfully!\n";
        }
        
        //issues book to faculty
        void facultyissued(booklist ob, book L[], int n, int transNo, faculty l[]){
            int k = list[transNo].returnbookid();
            for(int i=0;i<n;i++){
                if(L[i].returnid()==k){
                    int j=list[transNo].memid();
                    if(l[j].numberofbooks<10){
                        l[j].borrowed[l[j].numberofbooks] = k;
                        l[j].numberofbooks++;
                        L[k].serial--;
                    }
                    else{
                        cout<<"MAX ISSUE LIMIT REACHED!\n";
                        return;
                    }
                }
            }
            cout<<"Book Issued to Faculty!\n";
        }

        //returns book from faculty
        void facultyreturned(booklist ob, book L[], int n, int transNo, faculty l[]){
            int k = list[transNo].returnbookid();
            for(int i=0;i<n;i++){
                if(L[i].returnid()==k){
                    int j=list[transNo].memid();
                    if(l[j].numberofbooks<1){
                        cout<<"No Books to Return!\n";
                        return;
                    }
                    l[j].numberofbooks--;
                    L[k].serial++;
                }
            }
            // ob.updatebooklist(list[transNo].returnbookid(), 1);
            cout<<"Book Returned Successfully!\n";
        }
};
int transactionlist::nooftransactions=0;


int main(){
    int c,n,transno,avl, bookflag=0, memberflag=0;
    int ch;
    book *l; //pointer to book object

    //objects for respecive lists
    booklist bl;
    studentlist sl;
    facultylist fl;
    transactionlist tl;
    
    //menu
    do{
        cout<<"\n\n***LIBRARY MANAGEMENT SYSTEM***\n\n";
        cout<<"1. Add New Book.\n";
        cout<<"2. Stock up Existing Book.\n";
        cout<<"3. Add Student.\n";
        cout<<"4. Add Faculty.\n";
        cout<<"5. Issue Book.\n";
        cout<<"6. Return Book.\n";
        cout<<"7. Check Book Availability.\n";
        cout<<"8. Show 'Borrow History' of Member.\n";
        cout<<"9. Exit.\n";
        cout<<"\nEnter Your Choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                bl.addBook();
                bookflag++;
                break;
            case 2:
                cout<<"Enter Book-Id: ";
                cin>>c;
                bl.addexisting(c);
                break;
            case 3:
                memberflag=1;
                sl.addStudent();
                break;
            case 4:
                memberflag=-1;
                fl.addFaculty();
                break;
            case 5:
                if(bookflag==0){
                    cout<<"NO BOOKS ADDED!!\n";
                    break;
                }
                transno = tl.addTransaction(bl);
                n=bl.returnnob();
                l=bl.returnbooklist();
                
                cout<<"\n1. Issue For Student.\n";
                cout<<"2. Issue For Faculty.\n";
                cout<<"Enter Your Choice: ";
                cin>>c;
                
                //menu for issue
                switch(c){
                    case 1:
                        student *LS;
                        LS = sl.returnstudentlist();
                        tl.studentissued(bl, l, n, transno, LS);
                        break;
                    case 2:
                        faculty *LF;
                        LF = fl.returnfacultylist();
                        tl.facultyissued(bl, l, n, transno, LF);
                        break;
                }
                break;
            case 6:
                if(bookflag==0){
                    cout<<"NO BOOKS ADDED!!\n";
                    break;
                }
                transno = tl.addTransaction(bl);
                n=bl.returnnob();
                l=bl.returnbooklist();
                
                cout<<"1. Return For Student.\n";
                cout<<"2. Return For Faculty.\n";
                cout<<"Enter Your Choice: ";
                cin>>c;
                //menu for return
                switch(c){
                    case 1:
                        student *LS;
                        LS = sl.returnstudentlist();
                        tl.studentreturned(bl, l, n, transno, LS);
                        break;
                    case 2:
                        faculty *LF;
                        LF = fl.returnfacultylist();
                        tl.facultyreturned(bl, l, n, transno, LF);
                        break;
                }
                break;
            case 7:
                cout<<"\nEnter Book-Id to be checked: ";
                int id;
                cin>>id;
                bl.checkAvailable(id);
                break;
            case 8:
                if(memberflag==0){
                    cout<<"NO MEMBERS ADDED!!\n";
                    break;
                }
                cout<<"Student(1) or Faculty(0): ";
                int k;
                cin>>k;
                cout<<"Enter Member-Id: ";
                int memid;
                cin>>memid;
                //checking if ny student / faculty has been entered brore, if not displaying error
                if(k==1 && memberflag==1){
                    sl.showborrowed(memid);
                }
                else if(k==1 && memberflag==-1){
                    cout<<"NO STUDENT ADDED!\n";
                }
                else if(k==0 && memberflag==-1){
                    fl.showborrowed(memid);
                }
                else{
                    cout<<"NO FACULTY ADDED!\n";
                }
                break;
            case 9:
                exit(0);
        }
    }while(ch!=9);

    return 0;
}