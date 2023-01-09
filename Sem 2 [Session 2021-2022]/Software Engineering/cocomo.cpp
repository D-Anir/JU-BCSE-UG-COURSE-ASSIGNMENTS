#include "bits/stdc++.h"

using namespace std;

class Cocomo {
    float a, b, c, d;

    public:
        Cocomo() {

        }

        Cocomo(float aa, float bb, float cc, float dd){
            a = aa;
            b = bb;
            c = cc;
            d = dd;
        }

        float estimateEffortByBasicCocomo(int linesOfCode){
            float result = pow((a * linesOfCode),b);
            return result; 
        }

        float estimateEffortByIntermediateCocomo(int linesOfCode, float EAF){
            float result = (pow((a * linesOfCode),b)) * EAF;
            return result;
        }

        float estimateDuration(float effort){
            float result = pow((c * effort), d);
            return result;
        }

        int noOfPeople(float effort, float duration){
            return (int) effort / duration;
        }
};

void menu(Cocomo *basic_organic, Cocomo *basic_semi_detached, Cocomo *basic_embeded, Cocomo *intermediate_organic, Cocomo *intermediate_semi_detached, Cocomo *intermediate_embeded) {
    cout<<"**Welcome to Software Estimation By COCOMO I**\n";
    
    cout<<"Enter Lines Of Code: ";
    int lines;
    cin>>lines;
    lines = lines / 1000;
    
    int choice;
    cout<<"1. Basic Cocomo.\n2. Intermediate Cocomo.\nEnter Your Choice: ";
    cin>>choice;
    switch(choice) {
        case 1: {
            cout<<"Effort to develop Software: ";
            float effort;
            Cocomo type;

            if(lines <= 50){
                type = *(basic_organic);
                effort = basic_organic->estimateEffortByBasicCocomo(lines);
                cout << effort <<" PM.\n";
            } else if(lines > 50 && lines <= 300){
                type = *(basic_semi_detached);
                effort = basic_semi_detached->estimateEffortByBasicCocomo(lines);
                cout << effort <<" PM.\n";
            } else {
                type = *(basic_embeded);
                effort = basic_embeded->estimateEffortByBasicCocomo(lines);
                cout << effort <<" PM.\n";
            }
            float duration = type.estimateDuration(effort);
            cout<<"Duration to develop Software: " << duration <<" Months.\n";
            cout<<"Number of People engaged to develop Software: "<< type.noOfPeople(effort, duration) << ".\n";
            break;
        }

        case 2: {
            cout<<"Enter Effort Adjustment Factor: ";
            float EAF;
            cin>>EAF;
            cout<<"Effort to develop Software: ";
            float effort;
            Cocomo type;

            if(lines <= 50){
                type = *(intermediate_organic);
                effort = intermediate_organic->estimateEffortByIntermediateCocomo(lines, EAF);
                cout << effort <<" PM.\n";
            } else if(lines > 50 && lines <= 300){
                type = *(intermediate_semi_detached);
                effort = intermediate_semi_detached->estimateEffortByIntermediateCocomo(lines, EAF);
                cout << effort <<" PM.\n";
            } else {
                type = *(intermediate_embeded);
                effort = intermediate_embeded->estimateEffortByIntermediateCocomo(lines, EAF);
                cout << effort <<" PM.\n";
            }
            float duration = type.estimateDuration(effort);
            cout<<"Duration to develop Software: " << duration <<" Months.\n";
            cout<<"Number of People engaged to develop Software: "<< type.noOfPeople(effort, duration) << ".\n";
            break;
        }
    }
}

int main(){
    Cocomo basic_organic = Cocomo(2.4, 1.05, 2.5, 0.38);
    Cocomo basic_semi_detached = Cocomo(3.0, 1.12, 2.5, 0.35);
    Cocomo basic_embeded = Cocomo(3.6, 1.20, 2.5, 0.32);

    Cocomo intermediate_organic = Cocomo(3.2, 1.05, 2.5, 0.38);
    Cocomo intermediate_semi_detached = Cocomo(3.0, 1.12, 2.5, 0.35);
    Cocomo intermediate_embeded = Cocomo(2.8, 1.20, 2.5, 0.32);

    bool again = 1;
    while(again == 1){
        menu(&basic_organic, &basic_semi_detached, &basic_embeded, &intermediate_organic, &intermediate_semi_detached, &intermediate_embeded);
        cout<<"\nWish to continue? 1 for Yes, 0 for No.\n";
        cin>>again;
    }

    return 0;
}