#include "records.h"
#include "constants.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <windows.h>

using namespace std;

bool showProfile(const string& dataFile, const string& id,
                 const string& pass, const string& label) {
    ifstream f(dataFile);
    if (!f.is_open()) {
        cerr << "Cannot open " << dataFile << "." << endl;
        return false;
    }
    string fId, fPass, fName, fDept, fMobile, fExtra;
    while (getline(f, fId) && getline(f, fPass)) {
        getline(f, fName);
        getline(f, fDept);
        getline(f, fMobile);
        getline(f, fExtra);
        if (fId != id || fPass != pass) continue;
        printHeader();
        cout << "\n";
        cout << "\t\tYour Name is: "      << fName   << endl;
        cout << "\t\tYour Id NO is: "      << fId     << endl;
        cout << "\t\tYour Department is: " << fDept   << endl;
        cout << "\t\tYour Phone no is: "   << fMobile << endl;
        cout << "\t\tYour " << label << " is: " << fExtra << endl;
        return true;
    }
    return false;
}

bool tryLoginRole(const string& dataFile, const string& id, const string& pass,
                  string& outName, string& outDept) {
    ifstream f(dataFile);
    if (!f.is_open()) return false;
    string fId, fPass, fName, fDept, fMobile, fExtra;
    while (getline(f, fId) && getline(f, fPass)) {
        getline(f, fName);
        getline(f, fDept);
        getline(f, fMobile);
        getline(f, fExtra);
        if (fId != id || fPass != pass) continue;
        outName = fName;
        outDept = fDept;
        return true;
    }
    return false;
}

void addHod() {
    printHeader();
    string fname, lname, id, birthDate, department, mobile, salary;
    cout << "\t\t\tEnter HOD's first Name: ";
    cin >> fname;
    cout << "\t\t\tEnter HOD's Last Name: ";
    cin >> lname;
    while (true) {
        cout << "\t\t\tEnter HOD's Id no: ";
        cin >> id;
        if (!isIdTaken(id)) break;
        cout << "\t\t\tId Number already exists. Enter Again." << endl;
    }
    cout << "\t\t\tEnter HOD's Birthday in the form of dd/mm/yyyy: ";
    cin >> birthDate;
    cout << "\t\t\tEnter Department of HOD: ";
    cin >> department;
    cout << "\t\t\tEnter the mobile number of HOD: ";
    cin >> mobile;
    cout << "\t\t\tEnter Salary of HOD: ";
    cin >> salary;
    ofstream fData(FILE_HOD, ios::app);
    if (!fData.is_open()) {
        cerr << "Cannot open " << FILE_HOD << " for writing." << endl;
        return;
    }
    ofstream fUser(FILE_USERNAME, ios::app);
    if (!fUser.is_open()) {
        cerr << "Cannot open " << FILE_USERNAME << " for writing." << endl;
        return;
    }
    fData << id                    << endl;
    fData << birthDate             << endl;
    fData << fname << " " << lname << endl;
    fData << department            << endl;
    fData << mobile                << endl;
    fData << salary                << endl;
    fUser << id                    << endl;
    fUser << birthDate             << endl;
    cout << "\t\t\tThe Password is: " << birthDate << endl;
}

void addTeacher() {
    printHeader();
    string fname, lname, id, birthDate, department, mobile, salary;
    cout << "\t\t\tEnter Teacher's first Name: ";
    cin >> fname;
    cout << "\t\t\tEnter Teacher's Last Name: ";
    cin >> lname;
    while (true) {
        cout << "\t\t\tEnter Teacher's Id no: ";
        cin >> id;
        if (!isIdTaken(id)) break;
        cout << "\t\t\tId Number already exists. Enter Again." << endl;
    }
    cout << "\t\t\tEnter Teacher's Birthday in the form of dd/mm/yyyy: ";
    cin >> birthDate;
    cout << "\t\t\tEnter Department of Teacher: ";
    cin >> department;
    cout << "\t\t\tEnter the mobile number of Teacher: ";
    cin >> mobile;
    cout << "\t\t\tEnter Salary of Teacher: ";
    cin >> salary;
    ofstream fData(FILE_TEACHER, ios::app);
    if (!fData.is_open()) {
        cerr << "Cannot open " << FILE_TEACHER << " for writing." << endl;
        return;
    }
    ofstream fUser(FILE_USERNAME, ios::app);
    if (!fUser.is_open()) {
        cerr << "Cannot open " << FILE_USERNAME << " for writing." << endl;
        return;
    }
    fData << id                    << endl;
    fData << birthDate             << endl;
    fData << fname << " " << lname << endl;
    fData << department            << endl;
    fData << mobile                << endl;
    fData << salary                << endl;
    fUser << id                    << endl;
    fUser << birthDate             << endl;
    cout << "\t\t\tThe Password is: " << birthDate << endl;
}

void addStudent() {
    printHeader();
    string fname, lname, id, birthDate, department, mobile, result;
    cout << "\t\t\tEnter Student's first Name: ";
    cin >> fname;
    cout << "\t\t\tEnter Student's Last Name: ";
    cin >> lname;
    while (true) {
        cout << "\t\t\tEnter Student's Id no: ";
        cin >> id;
        if (!isIdTaken(id)) break;
        cout << "\t\t\tId Number already exists. Enter Again." << endl;
    }
    cout << "\t\t\tEnter Student's Birthday in the form of dd/mm/yyyy: ";
    cin >> birthDate;
    cout << "\t\t\tEnter Department of Student: ";
    cin >> department;
    cout << "\t\t\tEnter the mobile number of Student: ";
    cin >> mobile;
    cout << "\t\t\tEnter Result of Student: ";
    cin >> result;
    ofstream fData(FILE_STUDENT, ios::app);
    if (!fData.is_open()) {
        cerr << "Cannot open " << FILE_STUDENT << " for writing." << endl;
        return;
    }
    ofstream fUser(FILE_USERNAME, ios::app);
    if (!fUser.is_open()) {
        cerr << "Cannot open " << FILE_USERNAME << " for writing." << endl;
        return;
    }
    fData << id                    << endl;
    fData << birthDate             << endl;
    fData << fname << " " << lname << endl;
    fData << department            << endl;
    fData << mobile                << endl;
    fData << result                << endl;
    fUser << id                    << endl;
    fUser << birthDate             << endl;
    cout << "\t\t\tThe Password is: " << birthDate << endl;
}

void recordAttendance(const string& dataFile, const string& attFile,
                      const string& department) {
    ifstream fData(dataFile);
    if (!fData.is_open()) {
        cerr << "Cannot open " << dataFile << "." << endl;
        return;
    }
    ofstream fAtt(attFile, ios::app);
    if (!fAtt.is_open()) {
        cerr << "Cannot open " << attFile << " for writing." << endl;
        return;
    }
    SYSTEMTIME st;
    GetLocalTime(&st);
    char dateBuf[16];
    sprintf(dateBuf, "%02d/%02d/%04d", st.wDay, st.wMonth, st.wYear);
    cout << "\t\t\tUserName\tDepartment\tAttendance" << endl;
    string fId, fPass, fName, fDept, fMobile, fExtra;
    while (getline(fData, fId) && getline(fData, fPass)) {
        getline(fData, fName);
        getline(fData, fDept);
        getline(fData, fMobile);
        getline(fData, fExtra);
        if (fDept != department) continue;
        string status;
        do {
            cout << "\t\t\t" << fId << "\t\t" << department << "\t\t";
            cin >> status;
        } while (status != "P" && status != "NT" && status != "A");
        fAtt << fId << "\t\t" << department << "\tDate is: " << dateBuf << "\t" << status << endl;
    }
}

void giveFeedback(const string& department) {
    ifstream fTeacher(FILE_TEACHER);
    if (!fTeacher.is_open()) {
        cerr << "Cannot open " << FILE_TEACHER << "." << endl;
        return;
    }
    ofstream fFeedback(FILE_FEEDBACK, ios::app);
    if (!fFeedback.is_open()) {
        cerr << "Cannot open " << FILE_FEEDBACK << " for writing." << endl;
        return;
    }
    cout << "\t\t\tName\t\tdepartment\t\tFeedback" << endl;
    string fId, fPass, fName, fDept, fMobile, fSalary;
    while (getline(fTeacher, fId) && getline(fTeacher, fPass)) {
        getline(fTeacher, fName);
        getline(fTeacher, fDept);
        getline(fTeacher, fMobile);
        getline(fTeacher, fSalary);
        if (fDept != department) continue;
        string choice;
        do {
            cout << "\t\t\t" << fName << "\t\t" << department << "\t\t";
            cin >> choice;
        } while (choice != "1" && choice != "2" && choice != "3" && choice != "4");
        string rating;
        if      (choice == "1") rating = "Excellent";
        else if (choice == "2") rating = "Good";
        else if (choice == "3") rating = "Bad";
        else                    rating = "Very Bad";
        fFeedback << fName << "\t\t" << department << "\t\t" << rating << endl;
    }
}
