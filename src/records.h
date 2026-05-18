#pragma once
#include <string>

/**
 * @brief Search a data file for a matching id/password and print that record.
 * @param dataFile Path to the data file (HODdata.txt, Teacherdata.txt, or Studentdata.txt).
 * @param id       The user ID to search for.
 * @param pass     The password to match alongside the ID.
 * @param label    Label for the last field, either "Salary" or "Result".
 * @return true if a matching record was found and printed, false otherwise.
 */
bool showProfile(const std::string& dataFile, const std::string& id,
                 const std::string& pass, const std::string& label);

/**
 * @brief Search a data file for a matching id/password and extract name and department.
 * @param dataFile   Path to the data file to search.
 * @param id         User ID to look up.
 * @param pass       Password to match.
 * @param outName    Receives the full name of the matched record.
 * @param outDept    Receives the department of the matched record.
 * @return true if a matching record was found, false otherwise.
 */
bool tryLoginRole(const std::string& dataFile, const std::string& id, const std::string& pass,
                  std::string& outName, std::string& outDept);

/**
 * @brief Prompt for HOD details and append a new record to HODdata.txt and Username.txt.
 */
void addHod();

/**
 * @brief Prompt for Teacher details and append a new record to Teacherdata.txt and Username.txt.
 */
void addTeacher();

/**
 * @brief Prompt for Student details and append a new record to Studentdata.txt and Username.txt.
 */
void addStudent();

/**
 * @brief Record attendance for every person in a given department.
 * @param dataFile   Path to the role data file to iterate (e.g. HODdata.txt).
 * @param attFile    Path to the attendance output file.
 * @param department Only records whose department matches this value are processed.
 */
void recordAttendance(const std::string& dataFile, const std::string& attFile,
                      const std::string& department);

/**
 * @brief Let a student submit a feedback rating for each teacher in their department.
 * @param department The student's department; only teachers in this department are listed.
 */
void giveFeedback(const std::string& department);
