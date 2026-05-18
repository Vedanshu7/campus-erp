#pragma once
#include <string>

/**
 * @brief Run the Admin menu until the user chooses to log out.
 */
void runAdminMenu();

/**
 * @brief Run the HOD menu until the user chooses to log out.
 * @param id         The logged-in HOD's user ID.
 * @param pass       The logged-in HOD's password.
 * @param department The logged-in HOD's department.
 */
void runHodMenu(const std::string& id, const std::string& pass, const std::string& department);

/**
 * @brief Run the Teacher menu until the user chooses to log out.
 * @param id         The logged-in Teacher's user ID.
 * @param pass       The logged-in Teacher's password.
 * @param department The logged-in Teacher's department.
 */
void runTeacherMenu(const std::string& id, const std::string& pass, const std::string& department);

/**
 * @brief Run the Student menu until the user chooses to log out.
 * @param id         The logged-in Student's user ID.
 * @param pass       The logged-in Student's password.
 * @param department The logged-in Student's department.
 */
void runStudentMenu(const std::string& id, const std::string& pass, const std::string& department);
