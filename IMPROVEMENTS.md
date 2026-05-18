# campus-erp — Improvement Roadmap

## Near-term

- **SQLite backend** — replace `.txt` file storage with SQLite for proper relational data and concurrent access
- **Password hashing** — hash passwords with bcrypt or SHA-256 instead of storing plaintext
- **Input validation** — sanitize all user inputs to prevent buffer overflow and injection

## Cross-platform

- **Remove `windows.h` / `conio.h`** — replace `system("cls")`, `getch()`, and box-drawing characters with portable alternatives (`ncurses` on Linux/macOS)
- **CMake cross-compile** — add Linux and macOS targets to CMakeLists.txt

## Architecture

- **REST API layer** — expose ERP operations as HTTP endpoints using `cpp-httplib` or Crow framework
- **Web frontend** — React dashboard consuming the REST API
- **Docker** — containerize the application for easy deployment

## Security

- **Role-based access control (RBAC)** — enforce permissions at the function level, not just login
- **Session tokens** — replace simple password checks with token-based sessions
- **Audit log** — cryptographically signed history log to prevent tampering
