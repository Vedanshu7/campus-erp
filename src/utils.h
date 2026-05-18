#pragma once
#include <string>

/**
 * @brief Clear the screen and draw the application title banner.
 */
void printHeader();

/**
 * @brief Get the current local date and time as a formatted string.
 * @return String in the format "HH:MM:SS  DD/MM/YYYY".
 */
std::string getCurrentTimestamp();

/**
 * @brief Append a login event to History.txt.
 * @param username The ID of the user who just logged in.
 */
void logHistory(const std::string& username);

/**
 * @brief Print every line of a file to stdout with tab indentation.
 * @param filename Path to the file to display.
 */
void printFileContents(const std::string& filename);

/**
 * @brief Check whether a user ID already exists in Username.txt.
 * @param id The candidate ID to look up.
 * @return true if the ID is already registered, false if it is available.
 */
bool isIdTaken(const std::string& id);

/**
 * @brief Prompt the user to type a department name and return it.
 * @return The department string entered by the user.
 */
std::string promptDepartment();

/**
 * @brief Flush the input buffer and block until the user presses Enter.
 */
void waitForEnter();
