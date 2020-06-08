#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include "student.h"
#include "staff.h"
#include "tt.h"
//#include "result.h"
//#include "fee.h"
using namespace std;
class manager:public staff,public student,public attendance
{
  int select_op;
public:
  int manage_student()
  {
    //int studentC;
    //cout <<endl;
    while(1){
    cout << " **STUDENT** "<< endl;
    cout << "1. New Registration"<< endl;
    cout << "2. Update student information"<< endl;
    cout << "3. Delete student information"<< endl;
    cout << "4. List All students"<< endl;
    cout << "5. Search Record"<< endl;
    cout<<  "6. Exit"<<endl;
    cout << "Enter your choice:"<< endl;
    cin>>select_op;
    switch(select_op)
    {
        case 1:
            newStudentRegistration();
            break;
        case 2:
            updateStudentInform();
            break;
        case 3:
            deleteStudentInform();
            break;
        case 4:
            listOfStudents();
            break;
        case 5:Searchstudent();
        case 6:

              return 0;
              break;
        default:
                cout<<"wrong option, please retry";
    }
  }
}
  int manage_teacher()
  {
    //int staffC;
    while(1){
    cout <<endl;
    cout << " **STAFF** "<< endl;
    cout << "1. New Registration"<< endl;
    cout << "2. Update staff information"<< endl;
    cout << "3. Delete staff information"<< endl;
    cout << "4. List All staffs"<< endl;
    cout << "5. Search record"<< endl;
    cout<<  "6. Exit"<<endl;
    cout << "Enter your choice:"<< endl;
    cin>>select_op;
    switch(select_op)
    {
    case 1:
        newStaffRegistration();
        break;
    case 2:
           updateStaffInform();
           break;
    case 3:
            deleteStaffInform();
            break;
    case 4:
            listOfStaffs();
            break;

    case 5: Searchstaff();

    break;
    case 6: return 0;

    default:
            cout<<"wrong option, please retry";
    }

  }
}

};
int main()
{
  //fstream file;
  //attendance at;
  manager m;
    int choice;
        string command, name, password, inName, inPassword, registerName, registerPassword;
    while (1)
    {
        x:cout<<"(register/exit/login)\n"<<"Command: ";
        getline(cin, command);
        if (command=="exit")
        {
            return 1;
        }
        if (command=="register")
        {
            ofstream g("registration.txt");
            if (!g.is_open())
            {
                cout<<"could not open file\n";
                return 0;
            }
            cout<<"\n\n\n"<<"New Username: ";
            getline(cin, registerName);
            cout<<"New Password: ";
            getline(cin, registerPassword);
            g<<registerName;
            g<<'\n';
            g<<registerPassword;
            g.close();
        }
        if (command=="login")
        {
            ifstream f("registration.txt");
            if (!f.is_open())
            {
                cout<<"could not open file\n";
                return 0;
            }
            getline(f, name, '\n');
            getline(f, password, '\n');
            f.close();
            int n=0;
            do
            {
                cout<<"\n\n\n"<<"Enter Username: ";
                getline(cin, inName);
                cout<<"Enter Password: ";
                getline(cin, inPassword);
                if (inName==name && inPassword==password)
                {
                    cout<<"Login Successful\n"<<"Welcome, "<<inName;
                for(;;)
             {
                cout <<endl<<endl;
                cout << "\t\t\t\t!...**WELCOME TO SCHOOL MANAGEMENT SYSTEM**...!"<< endl<<endl;
                cout << "1. Manage Student"<< endl;
                cout << "2. Manage Staff"<< endl;
                    //cout << "3. Result Information"<< endl;
                    //  cout << "4. Fee Structure"<< endl;
                cout << "3. Allotment"<< endl;
                cout << "4. Attendance"<< endl;
                cout<<  "5. Exit"<<endl;
                cout << "Enter your choice:"<< endl;
                cin>>choice;
                switch(choice)
                {
                    case 1:
                            m.manage_student();
                        break;
                    case 2:
                            m.manage_teacher();
                        break;
                    case 3:
                            allotment();
                        break;
                    case 4:
                          show_attendance();
                          break;

                    case 5:goto x;
                        break;
                    default:cout<<"wrong entry, please re-try";
                        }
                    }
                    break;
                }
                cout<<"incorrect name or password\n";
                n++;
            }while(n<=2);
        }
        cout<<"\n\n\n\n\n";
    }

}
