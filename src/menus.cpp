#include "menus.h"
#include "constants.h"
#include "utils.h"
#include "records.h"
#include <iostream>

using namespace std;

void runAdminMenu() {
    while (true) {
        printHeader();
        cout << "\t\t****Choose You Entry****" << endl;
        cout << "\t\t\t1->Add HOD Data" << endl;
        cout << "\t\t\t2->See the History" << endl;
        cout << "\t\t\t3->Add Attendance of HOD" << endl;
        cout << "\t\t\t4->See the Attendance of HOD" << endl;
        cout << "\t\t\t5->See the Attendance of Teacher" << endl;
        cout << "\t\t\t6->See Feedback of Teachers" << endl;
        cout << "\t\t\t7->Log Out" << endl;
        cout << "\t\t\tEnter your Entry Here: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            int n;
            cout << "\t\t\tEnter How many HOD detail you want to enter: ";
            cin >> n;
            for (int i = 0; i < n; i++) addHod();
            waitForEnter();
        } else if (choice == 2) {
            printHeader();
            cout << "\t\t\tHistory" << endl;
            printFileContents(FILE_HISTORY);
            waitForEnter();
        } else if (choice == 3) {
            printHeader();
            recordAttendance(FILE_HOD, FILE_HOD_ATT, promptDepartment());
            waitForEnter();
        } else if (choice == 4) {
            printHeader();
            cout << "UserName\t\tAttendance" << endl;
            printFileContents(FILE_HOD_ATT);
            waitForEnter();
        } else if (choice == 5) {
            printHeader();
            cout << "UserName\t\tAttendance" << endl;
            printFileContents(FILE_TEACHER_ATT);
            waitForEnter();
        } else if (choice == 6) {
            printHeader();
            cout << "\t\t\tName\t\tDepartment\t\tFeedback" << endl;
            printFileContents(FILE_FEEDBACK);
            waitForEnter();
        } else if (choice == 7) {
            cout << "\t\t\tLogging Off" << endl;
            waitForEnter();
            return;
        } else {
            cout << "\t\t\tYou Enter Wrong Entry" << endl;
            cout << "\t\t\tEnter Again" << endl;
            waitForEnter();
        }
    }
}

void runHodMenu(const string& id, const string& pass, const string& department) {
    while (true) {
        printHeader();
        cout << "\t\t\tWelcome Hod" << endl;
        cout << "\t\t****Choose You Entry****" << endl;
        cout << "\t\t\t1->Add Teacher Data" << endl;
        cout << "\t\t\t2->See Your Attendance" << endl;
        cout << "\t\t\t3->Add Attendance of Teacher" << endl;
        cout << "\t\t\t4->See Your Data" << endl;
        cout << "\t\t\t5->Log out" << endl;
        cout << "\t\t\tEnter your Entry Here: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            int n;
            cout << "\t\t\tEnter How many Teachers detail you want to enter: ";
            cin >> n;
            for (int i = 0; i < n; i++) addTeacher();
            waitForEnter();
        } else if (choice == 2) {
            printHeader();
            cout << "UserName\tDepartment\t\t\tAttendance" << endl;
            printFileContents(FILE_HOD_ATT);
            waitForEnter();
        } else if (choice == 3) {
            printHeader();
            recordAttendance(FILE_TEACHER, FILE_TEACHER_ATT, department);
            waitForEnter();
        } else if (choice == 4) {
            showProfile(FILE_HOD, id, pass, "Salary");
            waitForEnter();
        } else if (choice == 5) {
            cout << "\t\t\tLogging Out" << endl;
            waitForEnter();
            return;
        } else {
            cout << "\t\t\tYou Enter Wrong Entry" << endl;
            cout << "\t\t\tEnter Again" << endl;
            waitForEnter();
        }
    }
}

void runTeacherMenu(const string& id, const string& pass, const string& department) {
    while (true) {
        printHeader();
        cout << "\t\t\tWelcome Teacher" << endl;
        cout << "\t\t****Choose You Entry****" << endl;
        cout << "\t\t\t1->Add Student Data" << endl;
        cout << "\t\t\t2->See  your Attendance" << endl;
        cout << "\t\t\t3->Add Attendance of Student" << endl;
        cout << "\t\t\t4->See Your Data" << endl;
        cout << "\t\t\t5->See Student's Attendance" << endl;
        cout << "\t\t\t6->Log Out" << endl;
        cout << "\t\t\tEnter your Entry Here: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            int n;
            cout << "\t\t\tEnter How many Student detail you want to enter: ";
            cin >> n;
            for (int i = 0; i < n; i++) addStudent();
            waitForEnter();
        } else if (choice == 2) {
            printHeader();
            cout << "UserName\tDepartment\t\tAttendance" << endl;
            printFileContents(FILE_TEACHER_ATT);
            waitForEnter();
        } else if (choice == 3) {
            printHeader();
            recordAttendance(FILE_STUDENT, FILE_STUDENT_ATT, department);
            waitForEnter();
        } else if (choice == 4) {
            showProfile(FILE_TEACHER, id, pass, "Salary");
            waitForEnter();
        } else if (choice == 5) {
            printHeader();
            cout << "\t\t\tUserName\tDepartment\t\tAttendance" << endl;
            printFileContents(FILE_STUDENT_ATT);
            waitForEnter();
        } else if (choice == 6) {
            cout << "\t\t\tLogging Out" << endl;
            waitForEnter();
            return;
        } else {
            cout << "\t\t\tYou Enter Wrong Entry" << endl;
            cout << "\t\t\tEnter Again" << endl;
            waitForEnter();
        }
    }
}

void runStudentMenu(const string& id, const string& pass, const string& department) {
    while (true) {
        printHeader();
        cout << "\t\t\tWelcome Student" << endl;
        cout << "\t\t****Choose You Entry****" << endl;
        cout << "\t\t\t1->See your Attendance" << endl;
        cout << "\t\t\t2->See Your Data" << endl;
        cout << "\t\t\t3->Give feedback to Your Teacher" << endl;
        cout << "\t\t\t4->Log Out" << endl;
        cout << "\t\t\tEnter your Entry Here: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            printHeader();
            cout << "\t\t\tUserName\tDepartment\t\t\tAttendance" << endl;
            printFileContents(FILE_STUDENT_ATT);
            waitForEnter();
        } else if (choice == 2) {
            showProfile(FILE_STUDENT, id, pass, "Result");
            waitForEnter();
        } else if (choice == 3) {
            printHeader();
            cout << "\t\t\t\t\tGive Feedback" << endl;
            cout << "\t\t\t1->Excellent 2->Good 3->Bad 4->Very Bad" << endl;
            giveFeedback(department);
            waitForEnter();
        } else if (choice == 4) {
            cout << "\t\t\tLogging Out" << endl;
            waitForEnter();
            return;
        } else {
            cout << "\t\t\tYou Enter Wrong Entry" << endl;
            cout << "\t\t\tEnter Again" << endl;
            waitForEnter();
        }
    }
}
