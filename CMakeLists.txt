cmake_minimum_required(VERSION 3.10)
project(campus-erp)

set(CMAKE_CXX_STANDARD 17)

# On Windows, link against necessary libs
if(WIN32)
    add_executable(campus-erp src/Project.cpp)
else()
    # Non-Windows: exclude windows.h / conio.h usage — see IMPROVEMENTS.md
    message(WARNING "This project uses Windows-specific headers. See IMPROVEMENTS.md for cross-platform roadmap.")
    add_executable(campus-erp src/Project.cpp)
endif()
