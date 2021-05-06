#include<iostream>
using namespace std;

class sales;

class item{ //stores item detais
        static int last_code;
        int icode;
        int qnty;
        char iname[31];
        int rate;
    public:
        void getdata();
        void showdata();
        void update_rate();
        void updatestock(sales);
        int isavail();
        static int numOfitems(){  //to print static variable
            return last_code;
        }
};

int item::last_code=0;

void item::getdata(){  //accept item details
    cout<<"Enter Item Name: ";
    cin>>iname;
    cout<<"Enter Quantity: ";
    cin>>qnty;
    cout<<"Enter Item Rate: ";
    cin>>rate;
    ++item::last_code;
    icode=item::last_code;
    cout<<"Item Code: "<<icode<<"\n";
}

void item::showdata(){  //display iterm details
    cout<<"Item Code: "<<icode;
    cout<<"\nItem Name: "<<iname;
    cout<<"\nQuantity: "<<qnty;
    cout<<"\nItem Rate: "<<rate<<"\n";
}

void item::update_rate(){  //update rate of items
    cout<<"Enter new rate: ";
    cin>>rate;
    cout<<"Rate Changed Successfully!\n";
}

int item::isavail(){  //check if the item is in stock
    if(qnty>0)
        return 1;
    return 0;
}

class sales{  //stores sales details
        item list[100];
        int i;
        int qntysold;
    public:
        void menu();
        friend void item::updatestock(sales);
};

void item::updatestock(sales s){  //upadates stock
    qnty=qnty-s.qntysold;
}

void sales::menu(){  //menu for the dashboard
    int ch;
    do{
        cout<<"\n***ITEM SALES MANAGEMENT SYSTEM***\n";
        cout<<"1. ADD ITEM.\n";
        cout<<"2. ISSUE ITEM\n";
        cout<<"3. MODIFY ITEM RATE\n";
        cout<<"4. GET ITEM DETAILS\n";
        cout<<"5. EXIT\n";
        cout<<"\nEnter Your Choice: ";
        cin>>ch;
        int ic;
        switch(ch){
            case 1:
                list[item::numOfitems()].getdata();
                break;
            case 2:
                sales c;
                cout<<"Enter code of Item to be issued: ";
                cin>>c.i;
                if(c.i<=item::numOfitems() && c.i>0){
                    cout<<"Enter quantity to be sold: ";
                    cin>>c.qntysold;
                    list[c.i-1].updatestock(c);
                    if(list[c.i-1].isavail())
                        cout<<"Item issued!\n";
                    else
                        cout<<"Out Of Stock!!\n";
                }
                else
                    cout<<"Invalid Item Code!\n";
                break;
            case 3:
                cout<<"Enter code of Item to update rate: ";
                cin>>ic;
                list[ic-1].update_rate();
                break;
            case 4:
                cout<<"Enter code of Item to be issued: ";
                cin>>ic;
                list[ic-1].showdata();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout<<"INVALID CHOICE!!!\n";
        }
    }while(ch!=5);
}

int main(){
    sales b;
    b.menu();
    return 0;
}