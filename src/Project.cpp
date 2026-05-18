#include<iostream>
#include<cstdlib>
#include<fstream>
#include<time.h>
#include<math.h>
#include<windows.h>
#include<conio.h>
using namespace std;
int c,b,d,e;
class Student
{
    public:
    string id_no_s,depaetment_s,fname_s,lname_s,passcode_s,mobile_no_s,b_date_s,salary_s;
    void printInformation()
    {
        printHeader();
        cout<<"\t\t\tWelcome Student"<<endl;
        cout<<"\t\t****Choose You Entry****"<<endl;
        cout<<"\t\t\t1->See your Attendance"<<endl;
        cout<<"\t\t\t2->See Your Data"<<endl;
        cout<<"\t\t\t3->Give feedback to Your Teacher"<<endl;
        cout<<"\t\t\t4->Log Out"<<endl;
        cout<<"\t\t\tEnter your Entry Here:";
        cin>>e;
    }
     void printHeader()
    {
        system("cls");
	    cout << endl;
	    cout << " \xC9";
	    for (int i = 0; i < 100; i++)
        cout << "\xCD";
	    cout << "\xBB";
        cout << endl;
	    cout << " \xBA";
	    cout << "                                       E governance System                                          ";
	    cout << "\xBA";
	    cout << endl;
	    cout << " \xC8";
	    for (int i = 0; i < 100; i++)
        cout << "\xCD";
	    cout << "\xBC";
	    cout << endl;
        cout << endl;
    }
     void addInformation()
    {
        ifstream ftempi;
        fstream f2,f4;
        printHeader();
        f4.open("Studentdata.txt",ios::out|ios::app);
        ftempi.open("Username.txt",ios::in);
                cout<<"\t\t\tEnter Student's first Name:";
                cin>>fname_s;
                cout<<"\t\t\tEnter Student's Last Name:";
                cin>>lname_s;
                q:
                cout<<"\t\t\tEnter Student's Id no:";
                cin>>id_no_s;
                ftempi.seekg(0,ios::beg);
                while(!ftempi.eof())
                {
                    string h;
                    string k;
                    getline(ftempi,k);
                    h=k;
                    getline(ftempi,k);
                    if(id_no_s==h)
                    {
                        cout<<"\t\t\tId Number is already exist"<<endl;
                        cout<<"\t\t\tEnter Again"<<endl;
                        break;
                    }
                }
               if(!ftempi.eof())
               {
                    goto q;
               }
               ftempi.close();
               f2.open("Username.txt",ios::app);
                f4<<id_no_s<<endl;
                f2<<id_no_s<<endl;
                cout<<"\t\t\tEnter Student's Birthday in the form of dd/mm/yyyy:";
                cin>>b_date_s;
                f4<<b_date_s<<endl;
                f2<<b_date_s<<endl;
                f4<<fname_s<<lname_s<<endl;
                cout<<"\t\t\tEnter Department of Student:";
                cin>>depaetment_s;
                f4<<depaetment_s<<endl;
                cout<<"\t\t\tEnter the mobile number of Student:";
                cin>>mobile_no_s;
                f4<<mobile_no_s<<endl;
                cout<<"\t\t\tEnter Result of Student:";
                cin>>salary_s;
                f4<<salary_s<<endl;
                cout<<"\t\t\tThe Password is:"<<b_date_s<<endl;
                passcode_s=b_date_s;
                f4.close();
                f2.close();
    }
    void seeData(string o,string q)
{
    fstream f4;
    string m1;
    string n1;
    string s,b,v,u;
    f4.open("Studentdata.txt");
    while(!f4.eof())
    {
     printHeader();
     getline(f4,m1);
     n1=m1;
     getline(f4,m1);
    if((n1==o)&&(m1==q))
      {
          getline(f4,m1);
          s=m1;
          cout<<"\n";
          cout<<"\t\tYour Name is:"<<s<<endl;
          cout<<"\t\tYour Id NO is:"<<n1<<endl;
          getline(f4,m1);
          b=m1;
          cout<<"\t\tYour Department is:"<<b<<endl;
          getline(f4,m1);
          v=m1;
          cout<<"\t\tYour Phone no is:"<<v<<endl;
          getline(f4,m1);
          u=m1;
          cout<<"\t\tYour Last Semester Result is:"<<u<<endl;
          break;
      }
    }
    f4.close();
}
void giveFeedback(string l)
{
    cout<<"\t\t\tName"<<"\t\tdepartment\t\tFeedback"<<endl;
    fstream f8,ftemp;
    string n1,m1,s,p,y,v,z,a1;
    f8.open("Feedback.txt",ios::app);
    ftemp.open("Teacherdata.txt");
    while(!ftemp.eof())
    {
     getline(ftemp,m1);
     n1=m1;
     getline(ftemp,m1);
     s=m1;
     getline(ftemp,m1);
     y=m1;
     getline(ftemp,m1);
     a1=m1;
     getline(ftemp,m1);
     v=m1;
     getline(ftemp,m1);
     z=m1;
     if(l==a1)
     {
         x:
        cout<<"\t\t\t"<<y<<"\t\t"<<l<<"\t\t";
        cin>>p;
        if(p=="1")
        {
            f8<<y<<"\t\t"<<l<<"\t\t"<<"Excellent"<<endl;
        }
        else if(p=="2")
        {
            f8<<y<<"\t\t"<<l<<"\t\t"<<"Good"<<endl;
        }
        else if(p=="3")
        {
            f8<<y<<"\t\t"<<l<<"\t\t"<<"Bad"<<endl;
        }
        else if(p=="4")
        {
            f8<<y<<"\t\t"<<l<<"\t\t"<<"Very Bad"<<endl;
        }
        else
        {
            goto x;
        }
     }
}
ftemp.close();
f8.close();
}
};
class HOD:public virtual Student
{
    string id_no_hod,depaetment_hod,fname_hod,lname_hod,passcode_hod,mobile_no_hod,b_date_hod,salary_hod;
    public:
    void printInformation()
    {
        printHeader();
        cout<<"\t\t\tWelcome Hod"<<endl;
        cout<<"\t\t****Choose You Entry****"<<endl;
        cout<<"\t\t\t1->Add Teacher Data"<<endl;
        cout<<"\t\t\t2->See Your Attendance"<<endl;
        cout<<"\t\t\t3->Add Attendance of Teacher"<<endl;
        cout<<"\t\t\t4->See Your Data"<<endl;
        cout<<"\t\t\t5->Log out"<<endl;
        cout<<"\t\t\tEnter your Entry Here:";
        cin>>b;
    }
    void addInformation()
    {  ifstream ftemp;
        fstream f2,f1;
        bool flag=1;
        printHeader();
        f1.open("HODdata.txt",ios::out|ios::app);
        ftemp.open("Username.txt",ios::app);
                //k123:
                cout<<"\t\t\tEnter HOD's first Name:";
                cin>>fname_hod;
                /*int i=0;
                while(flag){
                if(isalpha(fname_hod[i])){
                    i++;
                }
                else{
                    flag=0;
                    cout<<"\t\t\tYou Enter Number as First name";
                    goto k123;
                }
                }*/
                cout<<"\t\t\tEnter HOD's Last Name:";
                cin>>lname_hod;
                w:
                cout<<"\t\t\tEnter HOD's Id no:";
                cin>>id_no_hod;
                ftemp.seekg(0,ios::beg);
                while(!ftemp.eof())
                {
                    string a1;
                    string a2;
                    getline(ftemp,a2);
                    a1=a2;
                    getline(ftemp,a2);
                    if(id_no_hod==a1)
                    {
                        cout<<"\t\t\tId Number is already exist"<<endl;
                        cout<<"\t\t\tEnter Again"<<endl;
                        break;
                    }

                }
                if(!ftemp.eof())
                {
                        goto w;
                }
                ftemp.close();
                f2.open("Username.txt",ios::app);
                f1<<id_no_hod<<endl;
                f2<<id_no_hod<<endl;
                cout<<"\t\t\tEnter HOD's Birthday in the form of dd/mm/yyyy:";
                cin>>b_date_hod;
                f1<<b_date_hod<<endl;
                f2<<b_date_hod<<endl;
                f1<<fname_hod<<lname_hod<<endl;
                cout<<"\t\t\tEnter Department of HOD:";
                cin>>depaetment_hod;
                f1<<depaetment_hod<<endl;
                cout<<"\t\t\tEnter the mobile number of HOD:";
                cin>>mobile_no_hod;
                f1<<mobile_no_hod<<endl;
                cout<<"\t\t\tEnter Salary of HOD:";
                cin>>salary_hod;
                f1<<salary_hod<<endl;
                cout<<"\t\t\tThe Password is:"<<b_date_hod<<endl;
                passcode_hod=b_date_hod;
                f1.close();
                f2.close();
    }
void seeData(string o1,string q1)
{
    fstream f1;
    string m1;
    string n1;
    string s,b,v,u;
    f1.open("HODdata.txt");
    while(!f1.eof())
    {
     getline(f1,m1);
     n1=m1;
     getline(f1,m1);
    if((n1==o1)&&(m1==q1))
      {
          printHeader();
          getline(f1,m1);
          s=m1;
          cout<<"\n";
          cout<<"\t\tYour Name is:"<<s<<endl;
          cout<<"\t\tYour Id NO is:"<<n1<<endl;
          getline(f1,m1);
          b=m1;
          cout<<"\t\tYour Department is:"<<b<<endl;
          getline(f1,m1);
          v=m1;
          cout<<"\t\tYour Phone no is:"<<v<<endl;
          getline(f1,m1);
          u=m1;
          cout<<"\t\tYour Salary is:"<<u<<endl;
          break;
      }
    }
    f1.close();
}
void giveAttendance(string w,int a,int b,int c)
{
    fstream f12,f09;
    string n1,m1,s,y,p,v,z,a1;
    cout<<"\t\t\t"<<"UserName"<<"\t"<<"Department"<<"\tAttendance"<<endl;
    f12.open("Teacherattendance.txt",ios::app);
    f09.open("Teacherdata.txt");
     while(!f09.eof())
    {
     getline(f09,m1);
     n1=m1;
     getline(f09,m1);
     s=m1;
     getline(f09,m1);
     y=m1;
     getline(f09,m1);
     a1=m1;
     getline(f09,m1);
     v=m1;
     getline(f09,m1);
     z=m1;
     if(w==a1)
     {
         x:
        cout<<"\t\t\t"<<n1<<"\t\t"<<w<<"\t\t";
        cin>>p;
        if((p=="P")||(p=="NT")||(p=="A"))
        {
            f12<<n1<<"\t\t"<<w<<"\t"<<"Date is:"<<a<<"/"<<b<<"/"<<c<<"\t"<<p<<endl;
        }
        else
        {
            goto x;
        }
     }
    }
    f09.close();
    f12.close();
}
};
class Teacher:public virtual Student
{
    string id_no_t,depaetment_t,fname_t,lname_t,passcode_t,mobile_no_t,b_date_t,salary_t;
    public:
    void printInformation()
    {
        printHeader();
        cout<<"\t\t\tWelcome Teacher"<<endl;
        cout<<"\t\t****Choose You Entry****"<<endl;
        cout<<"\t\t\t1->Add Student Data"<<endl;
        cout<<"\t\t\t2->See  your Attendance"<<endl;
        cout<<"\t\t\t3->Add Attendance of Student"<<endl;
        cout<<"\t\t\t4->See Your Data"<<endl;
        cout<<"\t\t\t5->See Student's Attendance"<<endl;
        cout<<"\t\t\t6->Log Out"<<endl;
        cout<<"\t\t\tEnter your Entry Here:";
        cin>>d;
    }
     void addInformation()
    {
        ifstream ftempo;
        fstream f2,f3;
        printHeader();
        f3.open("Teacherdata.txt",ios::out|ios::app);
        ftempo.open("Username.txt",ios::out|ios::app);
                cout<<"\t\t\tEnter Teacher's first Name:";
                cin>>fname_t;
                cout<<"\t\t\tEnter Teacher's Last Name:";
                cin>>lname_t;
                r:
                cout<<"\t\t\tEnter Teacher's Id no:";
                cin>>id_no_t;
                ftempo.seekg(0,ios::beg);
                 while(!ftempo.eof())
                {
                    string a3;
                    string a4;
                    getline(ftempo,a4);
                    a3=a4;
                    getline(ftempo,a4);
                    if(id_no_t==a3)
                    {
                        cout<<"\t\t\tId Number is already exist"<<endl;
                        cout<<"\t\t\tEnter Again"<<endl;
                        break;
                    }

                }
                if(!ftempo.eof())
                {
                    goto r;
                }
                ftempo.close();
                f2.open("Username.txt",ios::app);
                f3<<id_no_t<<endl;
                f2<<id_no_t<<endl;
                cout<<"\t\t\tEnter Teacher's Birthday in the form of dd/mm/yyyy:";
                cin>>b_date_t;
                f3<<b_date_t<<endl;
                f2<<b_date_t<<endl;
                f3<<fname_t<<lname_t<<endl;
                cout<<"\t\t\tEnter Department of Teacher:";
                cin>>depaetment_t;
                f3<<depaetment_t<<endl;
                cout<<"\t\t\tEnter the mobile number of Teacher:";
                cin>>mobile_no_t;
                f3<<mobile_no_t<<endl;
                cout<<"\t\t\tEnter Salary of Teacher:";
                cin>>salary_t;
                f3<<salary_t<<endl;
                cout<<"\t\t\tThe Password is:"<<b_date_t<<endl;
                passcode_t=b_date_t;
                f3.close();
                f2.close();
    }
    void seeData(string o,string q)
{
    fstream f3;
    string m1;
    string n1;
    string s,b,v,u;
    f3.open("Teacherdata.txt");
    while(!f3.eof())
    {
     getline(f3,m1);
     n1=m1;
     getline(f3,m1);
    if((n1==o)&&(m1==q))
      {
          printHeader();
          getline(f3,m1);
          s=m1;
          cout<<"\n";
          cout<<"\t\tYour Name is:"<<s<<endl;
          cout<<"\t\tYour Id NO is:"<<n1<<endl;
          getline(f3,m1);
          b=m1;
          cout<<"\t\tYour Department is:"<<b<<endl;
          getline(f3,m1);
          v=m1;
          cout<<"\t\tYour Phone no is:"<<v<<endl;
          getline(f3,m1);
          u=m1;
          cout<<"\t\tYour Salary is:"<<u<<endl;
          break;
      }
    }
    f3.close();
}
void giveAttendance(string w,int a,int b,int c)
{
    fstream f10,f9;
    string n1,m1,s,y,p,v,z,a1;
    f10.open("Studentattendance.txt",ios::app);
    f9.open("Studentdata.txt");
    cout<<"\t\t\t"<<"UserName"<<"\t"<<"Department"<<"\t"<<"Attendance"<<endl;
     while(!f9.eof())
    {
     getline(f9,m1);
     n1=m1;
     getline(f9,m1);
     s=m1;
     getline(f9,m1);
     y=m1;
     getline(f9,m1);
     a1=m1;
     getline(f9,m1);
     v=m1;
     getline(f9,m1);
     z=m1;
     if(w==a1)
     {
         x:
        cout<<"\t\t\t"<<n1<<"\t\t"<<w<<"\t\t";
        cin>>p;
        if((p=="P")||(p=="NT")||(p=="A"))
        {
            f10<<n1<<"\t\t"<<w<<"\t"<<"Date is:"<<a<<"/"<<b<<"/"<<c<<"\t\t"<<p<<endl;
        }
        else
        {
            goto x;
        }
     }
    }
    f9.close();
    f10.close();
}
};
class Admin:public HOD,public Teacher
{
    public:
    int day,month,year,hr,Min,sec;
    void printInformation()
    {
        cout<<"\t\t****Choose You Entry****"<<endl;
        cout<<"\t\t\t1->Add HOD Data"<<endl;
        cout<<"\t\t\t2->See the History"<<endl;
        cout<<"\t\t\t3->Add Attendance of HOD"<<endl;
        cout<<"\t\t\t4->See the Attendance of HOD"<<endl;
        cout<<"\t\t\t5->See the  Attendance of Teacher"<<endl;
        cout<<"\t\t\t6->See Feedback of Teachers"<<endl;
        cout<<"\t\t\t7->log Out"<<endl;
        cout<<"\t\t\tEnter your Entry Here:";
        cin>>c;
    }
    void getSystemTime()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    day = st.wDay;
    month = st.wMonth;
    year = st.wYear;
    hr=st.wHour+5;
    Min=st.wMinute+30;
    sec=st.wSecond;
    if(Min>60){
      hr++;
      Min=fabs(Min-60);
    }
      if(hr>12)
    {
         hr=hr-12;
    }
}
void giveAttendance(string w,int a,int b,int c)
{
    fstream f50,f40;
    string n1,m1,s,y,p,v,z,a1;
    f50.open("HODattendance.txt",ios::app);
    f40.open("HODdata.txt");
    cout<<"\t\t\t"<<"UserName"<<"\t"<<"Department"<<"\tAttendance"<<endl;
     while(!f40.eof())
    {
     getline(f40,m1);
     n1=m1;
     getline(f40,m1);
     s=m1;
     getline(f40,m1);
     y=m1;
     getline(f40,m1);
     a1=m1;
     getline(f40,m1);
     v=m1;
     getline(f40,m1);
     z=m1;
     if(w==a1)
     {
         x:
        cout<<"\t\t\t"<<n1<<"\t\t"<<w<<"\t\t";
        cin>>p;
        if((p=="P")||(p=="NT")||(p=="A"))
        {
            f50<<n1<<"\t\t"<<w<<"\t\t"<<"Date is:"<<a<<"/"<<b<<"/"<<c<<"\t"<<p<<endl;
        }
        else
        {
            goto x;
        }
     }
    }
    f40.close();
    f50.close();
}
void printHistory()
{
    fstream f5;
    f5.open("History.txt");
    while(!f5.eof())
    {
        string  p;
        getline(f5,p);
        cout<<p<<endl;
    }
    f5.close();
}
};
string t()
{
cout<<"\t\t\tDepartment?:";
string as;
cin>>as;
return as;
}
int main()
{
        start:
        string user_name,password;
        string h;
        string m;
        int x;
        Admin A;
        HOD H[20];
        Teacher T[120];
        Student S[500];
        fstream f1,f2,f4,f5,f6,f7,f9;
        A.printHeader();
        cout<<"\t\t\tUser Name:";
        cin>>user_name;
        cout<<"\t\t\tPassword:";
        cin>>password;
        f2.open("Username.txt");
        if(user_name=="Admin"&&password=="pw")
        {
            h=user_name;
            m=password;
            x=1;
        }
        else
        {
              while(!f2.eof())
              {
                  string p;
                  string q;
                  getline(f2,q);
                  p=q;
                  getline(f2,q);
                if((user_name==p)&&(password==q))
                 {
                     x=2;
                     h=user_name;
                     m=password;
                     break;
                 }
                 }
                 while(f2.eof())
                 {
                     j:
                     system("cls");
                     A.printHeader();
                     cout<<"Error You Enter Wrong Id Password if you want to Reenter Id and password then Press 1 or Exit then Press 0:"<<endl;
                     int y;
                     cin>>y;
                     if(y==1)
                    {
                         goto start;
                    }
                     else if(y==0)
                    {
                         exit(0);
                    }
                    else
                    {
                        cout<<"\t\t\tYou Enter Wrong"<<endl;
                        goto j;
                    }
                 }

              }
        f2.close();
        switch(x)
        {
        case 1:
            A.printHeader();
            A.getSystemTime();
            f5.open("History.txt",ios::app);
            A.getSystemTime();
            f5<<h<<"     "<<"Time is:"<<A.hr<<":"<<A.Min<<":"<<A.sec<<"   "<<"Date is:"<<A.day<<"/"<<A.month<<"/"<<A.year<<endl;
            f5.close();
            A1:
            A.printInformation();
             switch(c)
              {
               case 1:
                   cout<<"\t\t\tEnter How many HOD detail you want to enter:";
                   int w;
                   cin>>w;
                   for(int i=1;i<(w+1);i++)
                    {
                     H[i].addInformation();
                    }
                    system("pause");
                    H[0].printHeader();
                    goto A1;
                 break;
             case 2:
                  A.printHeader();
                  cout<<"\t\t\tHistory"<<endl;
                  cout<<"UserName"<<endl;
                  A.printHistory();
                  system("pause");
                  A.printHeader();
                  goto A1;
                  break;
             case 3:
                  A.printHeader();
                  A.getSystemTime();
                  A.giveAttendance(t(),A.day,A.month,A.year);
                  system("pause");
                  A.printHeader();
                  goto A1;
                  break;
             case 4:
                 A.printHeader();
                cout<<"UserName";
                cout<<"\t\tAttendance"<<endl;
                f6.open("HODattendance.txt");
                  while(!f6.eof())
                  {
                     string g;
                     getline(f6,g);
                     cout<<g<<endl;
                  }
                  f6.close();
                  system("pause");
                  A.printHeader();
                  goto A1;
                  break;
             case 5:
                 A.printHeader();
                 cout<<"UserName";
                 cout<<"\t\tAttendance"<<endl;
                 f7.open("Teacherattendance.txt");
                 while(!f7.eof())
                  {
                    string k;
                    getline(f7,k);
                    cout<<k<<endl;
                  }
                  f7.close();
                  system("pause");
                  A.printHeader();
                  goto A1;
                  break;
             case 6:
                  A.printHeader();
                  cout<<"\t\t\tName"<<"\t\tDepartment\t\tFeedback"<<endl;
                  f9.open("Feedback.txt");
                  while(!f9.eof())
                  {
                    string w;
                    getline(f9,w);
                    cout<<"\t\t\t"<<w<<endl;
                  }
                  f9.close();
                  system("pause");
                  A.printHeader();
                  goto A1;
                  break;
             case 7:
               cout<<"\t\t\tLogging Off"<<endl;
               system("pause");
               goto start;
               break;
             default:
                cout<<"\t\t\tYou Enter Wrong Entry"<<endl;
                cout<<"\t\t\tEnter Again"<<endl;
                system("pause");
                A.printHeader();
                goto A1;
                break;
               }
            break;
        case 2:
            string m1,m2,m3;
            string n1,n2,n3;
            f1.open("HODdata.txt");
            while(!f1.eof())
            {
                getline(f1,m1);
                n1=m1;
                getline(f1,m1);
                if((n1==user_name)&&(m1==password))
                {
                    string d1,d2;
                    getline(f1,d2);
                    d1=d2;
                    A.printHeader();
                    cout<<"\t\t\tWelcome:"<<d1<<endl;
                    getline(f1,d2);
                    cout<<"\t\t\tHOD of Department:"<<d2<<endl;
                    system("pause");
                    fstream f5;
                    f5.open("History.txt",ios::app);
                    A.getSystemTime();
                    f5<<h<<"     "<<"Time is:"<<A.hr<<":"<<A.Min<<":"<<A.sec<<"   "<<"Date is:"<<A.day<<"/"<<A.month<<"/"<<A.year<<endl;
                    f5.close();
                    B1:
                    H[0].printInformation();
                    f1.close();
            switch(b)
            {
            case 1:
                    cout<<"\t\t\tEnter How many Teachers detail you want to enter:";
                    int l;
                    cin>>l;
                    for(int j=1;j<(l+1);j++)
                    {
                     T[j].addInformation();
                    }
                    system("pause");
                    A.printHeader();
                    goto B1;
                    break;
            case 2:
                  A.printHeader();
                  cout<<"UserName";
                  cout<<"\tDepartment";
                  cout<<"\t\t\tAttendance"<<endl;
                  f6.open("HODattendance.txt");
                  while(!f6.eof())
                  {
                     string g;
                     getline(f6,g);
                     cout<<g<<endl;
                  }
                   f6.close();
                   system("pause");
                   A.printHeader();
                   goto B1;
                  break;
            case 3:
                 A.getSystemTime();
                 A.printHeader();
                 H[0].giveAttendance(d2,A.day,A.month,A.year);
                 system("pause");
                 A.printHeader();
                 goto B1;
                 break;
            case 4:
                  A.printHeader();
                  H[5].seeData(user_name,password);
                   system("pause");
                   A.printHeader();
                   goto B1;
                  break;
            case 5:
                A.printHeader();
                cout<<"\t\t\tLogging Out"<<endl;
                system("pause");
                goto start;
                break;
            default:
                cout<<"\t\t\tYou Enter Wrong Entry"<<endl;
                cout<<"\t\t\tEnter Again"<<endl;
                system("pause");
                A.printHeader();
                goto B1;
                break;
                }
                break;
             }
            }
            while(f1.eof())
            {
                goto p;
            }
            p:
            fstream local;
            local.open("Teacherdata.txt");
            while(!local.eof())
            {
                getline(local,m2);
                n2=m2;
                getline(local,m2);
                if((n2==user_name)&&(m2==password))
                {
                    string d1,d2;
                    getline(local,d2);
                    d1=d2;
                    A.printHeader();
                    cout<<"\t\t\tWelcome:"<<d1<<endl;
                    getline(local,d2);
                    cout<<"\t\t\tTeacher of Department:"<<d2<<endl;
                    system("pause");
                    A.getSystemTime();
                    fstream f5;
                    A.getSystemTime();
                    f5.open("History.txt",ios::app);
                    f5<<h<<"     "<<"Time is:"<<A.hr<<":"<<A.Min<<":"<<A.sec<<"   "<<"Date is:"<<A.day<<"/"<<A.month<<"/"<<A.year<<endl;
                    f5.close();
                    C1:
                    T[0].printInformation();
                    string l;
                    local.close();
            switch(d)
                    {
                case 1:
                      cout<<"\t\t\tEnter How many Student detail you want to enter:";
                      int o;
                      cin>>o;
                      for(int z=1;z<(o+1);z++)
                      {
                         S[z].addInformation();
                      }
                       system("pause");
                       A.printHeader();
                       goto C1;
                      break;
                case 2:
                        A.getSystemTime();
                        A.printHeader();
                        cout<<"UserName";
                        cout<<"\tDepartment";
                        cout<<"\t\tAttendance"<<endl;
                        f7.open("Teacherattendance.txt");
                        while(!f7.eof())
                        {
                          string k;
                          getline(f7,k);
                         cout<<k<<endl;
                        }
                       f7.close();
                        system("pause");
                        A.printHeader();
                        goto C1;
                       break;

                case 3:
                      A.printHeader();
                      A.getSystemTime();
                      T[1].giveAttendance(d2,A.day,A.month,A.year);
                      system("pause");
                      A.printHeader();
                      goto C1;
                      break;
                case 4:
                      A.printHeader();
                      T[4].seeData(h,m);
                      system("pause");
                      A.printHeader();
                      goto C1;
                      break;
                case 5:
                     A.printHeader();
                     f6.open("Studentattendance.txt");
                     while(!f6.eof())
                     {
                         getline(f6,l);
                         cout<<"\t\t\t"<<l<<endl;
                     }
                     f6.close();
                      system("pause");
                      A.printHeader();
                      goto C1;
                      break;
                case 6:
                      A.printHeader();
                      cout<<"\t\t\tLogging Out"<<endl;
                      system("pause");
                      goto start;
                      break;
                default:
                      cout<<"\t\t\tYou Enter Wrong Entry"<<endl;
                      cout<<"\t\t\tEnter Again"<<endl;
                      system("pause");
                      A.printHeader();
                      goto C1;
                      break;
                    }
                    break;
                }
            }
             while(local.eof())
            {
                goto k;
            }
            k:
            fstream f4;
            f4.open("Studentdata.txt");
            while(!f4.eof())
            {
                getline(f4,m3);
                n3=m3;
                getline(f4,m3);
                if((n3==user_name)&&(m3==password))
                {
                    string d1,d2;
                    getline(f4,d2);
                    d1=d2;
                    A.printHeader();
                    cout<<"\t\t\tWelcome:"<<d1<<endl;
                    getline(f4,d2);
                    cout<<"\t\t\tStudent of Department:"<<d2<<endl;
                    system("pause");
                    f4.close();
                    A.getSystemTime();
                    fstream f5;
                    A.getSystemTime();
                    f5.open("History.txt",ios::app);
                    f5<<h<<"     "<<"Time is:"<<A.hr<<":"<<A.Min<<":"<<A.sec<<"   "<<"Date is:"<<A.day<<"/"<<A.month<<"/"<<A.year<<endl;
                    f5.close();
                    D1:
                    S[0].printInformation();
                    fstream f3;
                    switch(e)
                    {
               case 1:
                     A.printHeader();
                     A.getSystemTime();
                     f3.open("Studentattendance.txt");
                     cout<<"\t\t\t"<<"UserName"<<"\t"<<"Department"<<"\t\t\t"<<"Attendance"<<endl;
                     while(!f3.eof())
                      {
                         string m1;
                         getline(f3,m1);
                         cout<<"\t\t\t"<<m1<<endl;
                      }
                      f3.close();
                      system("pause");
                      A.printHeader();
                      goto D1;
                     break;
                case 2:
                    A.printHeader();
                      S[1].seeData(h,m);
                      system("pause");
                      A.printHeader();
                      goto D1;
                     break;
                case 3:
                     A.printHeader();
                     cout<<"\t\t\t\t\tGive Feedback"<<endl;
                     cout<<"\t\t\t1->Excellent 2->Good 3->Bad 4->Very Bad"<<endl;
                     S[1].giveFeedback(d2);
                     system("pause");
                     A.printHeader();
                      goto D1;
                     break;
                case 4:
                     cout<<"\t\t\tLogging Out"<<endl;
                     system("pause");
                     goto start;
                     break;
                default:
                     cout<<"\t\t\tYou Enter Wrong Entry"<<endl;
                     cout<<"\t\t\tEnter Again"<<endl;
                     system("pause");
                     A.printHeader();
                     goto D1;
                     break;
                    }

                    break;
                }
            }
            break;
            }
}



