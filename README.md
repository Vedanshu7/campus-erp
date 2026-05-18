# campus-erp

> A console-based ERP system for educational institutions, built in C++.

`campus-erp` is a Windows console application that manages students, teachers, and Head of Department (HOD) data for a college or university. Features a menu-driven interface with ASCII art UI, file-based persistence, attendance tracking, and feedback submission.

## Features

- **Role-based login** — separate portals for Admin, HOD, Teacher, and Student
- **Attendance management** — record and view attendance per department
- **Data management** — add and view student, teacher, and HOD records
- **Feedback system** — students can submit feedback for teachers
- **History log** — all logins are timestamped and logged to `data/History.txt`
- **ASCII UI** — styled console interface using box-drawing characters

## Tech Stack

- **Language:** C++ (C++17)
- **Platform:** Windows (uses `windows.h`)
- **Storage:** File-based (`.txt` files in `data/`)
- **Build:** CMake

## Project Structure

```
campus-erp/
├── src/
│   ├── main.cpp        — entry point (login loop + role dispatch)
│   ├── constants.h     — file path constants and data structs
│   ├── utils.h/.cpp    — UI helpers, timestamps, file utilities
│   ├── records.h/.cpp  — add/view records, attendance, feedback
│   └── menus.h/.cpp    — Admin, HOD, Teacher, Student menu loops
├── data/               — runtime data files (auto-created on first run)
├── CMakeLists.txt
└── README.md
```

## Build & Run

### Prerequisites

- Windows with Visual Studio or MinGW-w64
- CMake 3.10+

### Build

```bash
mkdir build && cd build
cmake ..
cmake --build .
./campus-erp.exe
```

> **Note:** The executable must be run from the project root so it can resolve paths under `data/`.

## Data Files

All runtime data is stored under `data/`:

| File | Purpose |
|------|---------|
| `data/HODdata.txt` | HOD records |
| `data/Teacherdata.txt` | Teacher records |
| `data/Studentdata.txt` | Student records |
| `data/Username.txt` | Credential index (auto-generated) |
| `data/History.txt` | Login audit log |
| `data/HODattendance.txt` | HOD attendance records |
| `data/Teacherattendance.txt` | Teacher attendance records |
| `data/Studentattendance.txt` | Student attendance records |
| `data/Feedback.txt` | Student feedback submissions |

Data files are created automatically on first use. `Username.txt` and `Studentdata.txt` are listed in `.gitignore`.

## Default Admin Login

| Field | Value |
|-------|-------|
| Username | `Admin` |
| Password | `pw` |

HOD, Teacher, and Student accounts are added through the Admin and HOD menus. Each account's password is set to their date of birth (`dd/mm/yyyy`).

## License

[MIT](LICENSE)
