cmake_minimum_required(VERSION 3.10)
project(campus-erp)

set(CMAKE_CXX_STANDARD 17)

if(NOT WIN32)
    message(WARNING "This project uses Windows-specific headers (windows.h). Build on Windows only.")
endif()

add_executable(campus-erp
    src/main.cpp
    src/utils.cpp
    src/records.cpp
    src/menus.cpp
)

target_include_directories(campus-erp PRIVATE src)
