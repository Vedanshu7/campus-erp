#pragma once
#include <string>

// ============================================================
// Application-wide constants.
// ============================================================

const std::string ADMIN_USERNAME   = "Admin";
const std::string ADMIN_PASSWORD   = "pw";
const std::string FILE_HOD         = "data/HODdata.txt";
const std::string FILE_TEACHER     = "data/Teacherdata.txt";
const std::string FILE_STUDENT     = "data/Studentdata.txt";
const std::string FILE_USERNAME    = "data/Username.txt";
const std::string FILE_HISTORY     = "data/History.txt";
const std::string FILE_HOD_ATT     = "data/HODattendance.txt";
const std::string FILE_TEACHER_ATT = "data/Teacherattendance.txt";
const std::string FILE_STUDENT_ATT = "data/Studentattendance.txt";
const std::string FILE_FEEDBACK    = "data/Feedback.txt";

// ============================================================
// Data structures.
// ============================================================

/** Person fields shared by every role. */
struct Person {
    std::string id;
    std::string password;
    std::string fullName;
    std::string department;
    std::string mobile;
};

/** Student extends Person with an exam result field. */
struct Student : Person {
    std::string result;
};

/** Teacher extends Person with a salary field. */
struct Teacher : Person {
    std::string salary;
};

/** Hod extends Person with a salary field. */
struct Hod : Person {
    std::string salary;
};
