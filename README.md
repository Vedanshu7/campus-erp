# campus-erp

> A console-based ERP system for educational institutions, built in C++.

`campus-erp` is a Windows console application that manages students, teachers, and Head of Department (HOD) data for a college or university. Features a menu-driven interface with ASCII art UI, file-based persistence, attendance tracking, and feedback submission.

## Features

- **Role-based login** — separate portals for Students, Teachers, and HODs
- **Attendance management** — record and view attendance per student
- **Data management** — add, view, and update student/teacher records
- **Feedback system** — students can submit feedback to teachers
- **History log** — all actions are logged to `History.txt`
- **ASCII UI** — styled console interface using box-drawing characters

## Tech Stack

- **Language:** C++ (C++17)
- **Platform:** Windows (uses `windows.h`, `conio.h`)
- **Storage:** File-based (`.txt` files)
- **Build:** CMake

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

### Run pre-built (Windows only)

```bash
# From project root
./build/campus-erp.exe
```

## Data Files

| File | Purpose |
|------|---------|
| `HODdata.txt` | HOD records |
| `Teacherdata.txt` | Teacher records |
| `History.txt` | Action log |
| `Username.txt` | Auto-generated credential index |

> Data files are auto-created on first run. Never commit `Username.txt` (added to `.gitignore`).

## Default Login

On first run, an HOD account is auto-created. Follow the on-screen prompts to set credentials.

## License

[MIT](LICENSE)
