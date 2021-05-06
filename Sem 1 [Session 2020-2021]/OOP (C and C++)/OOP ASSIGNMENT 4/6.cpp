#include<iostream>
#include<string>

#define MAX 100
using namespace std;

class SUBJECT
{
    int subcode;
    string name;

    public:
    SUBJECT()
    {
        subcode = 0;
        name = "";
    }

    SUBJECT(int scode, string sname)
    {
        subcode = scode;
        name = sname;
    }

    void operator=(SUBJECT s)
    {
        subcode = s.subcode;
        name = s.name;
    }

    friend class STUDENT;
    friend class SYSTEM;
    friend ostream & operator<<(ostream &out, SUBJECT &s);
};

class SYSTEM;

class STUDENT
{
    int roll;
    string name;
    string phone;
    SUBJECT subs[MAX];
    int n_subs;

    public:
    STUDENT()
    {
        roll = 0;
        name = "";
        phone = "";

        for (int i = 0; i < MAX; i ++)
        {
            SUBJECT temp;
            subs[i] = temp;
        }
    }

    STUDENT(int r, string n, string p)
    {
        roll = r;
        name = n;
        phone = p;
        
        for (int i = 0; i < MAX; i ++)
        {
            SUBJECT temp;
            subs[i] = temp;
        }
    }

    void pick_subs(SUBJECT * sub_list, int n)
    {
        int choice;
        for (int i = 0; i < n; i ++)
        {
            cout<<"Do you wish to take "<<sub_list[i].name<<"? Input 1 for YES and 0 for NO: ";
            cin>>choice;

            if (choice == 1)
            {
                subs[n_subs ++] = sub_list[i];
            }
        }
    }

    friend class SYSTEM;
    friend ostream & operator<<(ostream &out, STUDENT &s);
};

ostream & operator<<(ostream &out, STUDENT &s)
{
    out<<"Student Name: "<<s.name<<endl;
    out<<"Student Roll: "<<s.roll<<endl;
    out<<"Student Phone: "<<s.phone<<endl;
    
    return out;
}

ostream & operator<<(ostream &out, SUBJECT &s)
{
    out<<"Subject Name: "<<s.name<<endl;
    out<<"Subject Code: "<<s.subcode<<endl;

    return out;
}

class SYSTEM
{
    STUDENT students[MAX];
    SUBJECT subjects[MAX];

    int n_studs;
    int n_subs;

    public:
    SYSTEM()
    {
        for (int i = 0; i < MAX; i ++)
        {
            STUDENT temp;
            students[i] = temp;
        }

        for (int i = 0; i < MAX; i ++)
        {
            SUBJECT temp;
            subjects[i] = temp;
        }
        n_studs = 0;
        n_subs = 0;
    }

    void add_stud()
    {
        cout<<"Enter student roll: ";
        cin>>students[n_studs].roll;
        cout<<"Enter student name: ";
        cin>>students[n_studs].name;
        cout<<"Enter student phone: ";
        cin>>students[n_studs].phone;

        students[n_studs ++].pick_subs(subjects, n_subs);
    }
    
    void add_sub()
    {
        cout<<"Enter subject code: ";
        cin>>subjects[n_subs].subcode;
        cout<<"Enter subject name: ";
        cin>>subjects[n_subs ++].name;
    }

    void disp_subs_of(int roll)
    {
        for (int i = 0; i < n_studs; i ++)
        {
            if (students[i].roll == roll)
            {
                for (int j = 0; j < students[i].n_subs; j ++)
                {
                    cout<<students[i].subs[j]<<endl;
                }
            }
        }
    }

    void disp_studs_with(int scode)
    {
        for (int i = 0; i < n_studs; i ++)
        {
            for (int j = 0; j < students[i].n_subs; j ++)
            {
                if (students[i].subs[j].subcode == scode)
                {
                    cout<<students[i]<<endl;
                }
            }
        }
    }
};

int main()
{
    SYSTEM system;
    system.add_sub();
    system.add_sub();
    system.add_sub();
    system.add_stud();
    system.add_stud();

    system.disp_subs_of(1);
    system.disp_studs_with(1);
}