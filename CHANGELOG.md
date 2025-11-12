# 📋 CHANGELOG

## Version 2.1.0 - Crash Isolation Release 🛡️

### New Features ⭐

#### Process Isolation (Safe Mode)
- **NEW**: Safe mode with process isolation (`./libft_tester -s` or `--safe`)
- **NEW**: Each test runs in its own child process via `fork()`
- **NEW**: Crashes (segfaults, aborts, etc.) don't crash the entire program
- **NEW**: Timeout protection - tests exceeding 5 seconds are automatically killed
- **NEW**: Graceful error handling and reporting
- **NEW**: Detailed crash reports showing which test failed and why

#### Isolation System (`isolation.c`, `isolation.h`)
- Process forking and child process management
- Signal handling for timeouts (SIGALRM)
- Child status monitoring via `waitpid()`
- Support for multiple signal types:
  - SIGSEGV (segmentation fault)
  - SIGABRT (abort signal)
  - SIGBUS (bus error)
  - SIGFPE (floating point error)
  - SIGILL (illegal instruction)

#### Isolated Test Runners (`isolated_tests.c`)
- `run_all_tests_isolated()` - Run all tests in isolated mode
- `run_part1_tests_isolated()` - Run Part 1 in isolated mode
- `run_part2_tests_isolated()` - Run Part 2 in isolated mode
- Each test function wrapped with crash protection

### Improvements 🔧

#### Core System
- **IMPROVED**: Main.c now supports three modes:
  - Interactive mode (`-i`, `--interactive`)
  - Safe mode (`-s`, `--safe`)
  - Batch mode (default)
- **IMPROVED**: Better command-line help messages
- **IMPROVED**: Error recovery - test suite continues even if a function crashes

#### Build System
- **IMPROVED**: Makefile includes new source files (isolation.c, isolated_tests.c)
- **IMPROVED**: Clean target removes any stray processes/traces

### Files Added 📁
- `isolation.h` - Isolation system header and declarations
- `isolation.c` - Process forking and crash handling implementation
- `isolated_tests.c` - Wrapper functions for isolated test execution

### Files Modified 📝
- `tester.h` - Added isolation.h include and isolated test declarations
- `main.c` - Added safe mode support with command-line flag `-s`
- `Makefile` - Added isolation.c and isolated_tests.c to build
- `README.md` - Added Safe Mode section with detailed documentation
- `CHANGELOG.md` - Updated with new features

### Technical Details

**How Crash Isolation Works:**
1. Parent process forks a child for each test
2. Child executes the test function in isolation
3. Signal handler (SIGALRM) enforces 5-second timeout
4. Parent waits for child status
5. If child crashes: reports the crash, continues to next test
6. If child hangs: timeout kills it, continues to next test
7. Parent maintains statistics across all tests

**Exit Codes:**
- 0 = All tests passed
- 1 = Some tests failed or crashed
- 139 = Segmentation fault
- 134 = Abort signal
- 124 = Timeout exceeded
- 127 = Other crash

### Usage Examples

**Run with crash protection:**
```bash
./libft_tester -s
```

**Run specific mode:**
```bash
./libft_tester              # Batch mode (no isolation)
./libft_tester -i           # Interactive mode
./libft_tester -s           # Safe mode (with isolation)
./libft_tester --safe       # Safe mode (long form)
```

---

## Version 2.0.0 - Interactive Mode Release 🎉

### New Features ⭐

#### Interactive Menu System
- **NEW**: Interactive mode with menu interface (`./libft_tester -i`)
- **NEW**: Six menu options for flexible testing
  - Run all tests
  - Run Part 1 tests only
  - Run Part 2 tests only
  - View last test results
  - Clear trace history
  - Help & documentation
- **NEW**: Beautiful menu UI with emojis and clear descriptions
- **NEW**: Press Enter to continue between operations

#### Advanced Trace System
- **NEW**: Automatic failure logging with detailed information
- **NEW**: Persistent trace storage in `.libft_test_traces.log`
- **NEW**: View past failures without re-running tests
- **NEW**: Contextual advice for fixing common issues
- **NEW**: Timestamp tracking for each failure
- **NEW**: Function context tracking (shows which function failed)

#### Offline Capabilities
- **NEW**: Fully functional without internet connection
- **NEW**: All traces stored locally
- **NEW**: No external dependencies required

### Improvements 🔧

#### Build System
- **IMPROVED**: Makefile now compiles `trace.c` and `menu.c`
- **IMPROVED**: `make clean` now removes `.libft_test_traces.log`
- **IMPROVED**: Updated help message to mention interactive mode
- **IMPROVED**: Better error handling and user feedback

#### Code Architecture
- **IMPROVED**: Main.c refactored with separate test runner functions:
  - `run_all_tests()` - Execute complete test suite
  - `run_part1_tests()` - Execute Part 1 only
  - `run_part2_tests()` - Execute Part 2 only
- **IMPROVED**: Global function context tracking for accurate error reporting
- **IMPROVED**: Integration of trace system into existing test framework

#### Documentation
- **UPDATED**: README.md with interactive mode instructions
- **UPDATED**: QUICK_START.md with 4 different usage methods
- **UPDATED**: Added trace system section to README
- **UPDATED**: Makefile help command now shows both modes
- **NEW**: This CHANGELOG.md file

### Files Added 📁
- `trace.h` - Trace system header and declarations
- `trace.c` - Trace system implementation
- `menu.c` - Interactive menu system
- `CHANGELOG.md` - This file

### Files Modified 📝
- `tester.h` - Added trace.h include and g_current_function extern
- `main.c` - Complete refactor for dual-mode operation
- `utils.c` - Integrated trace logging into print_test_result()
- `Makefile` - Added new source files and updated targets
- `README.md` - Added interactive mode and trace system documentation
- `QUICK_START.md` - Added interactive mode as primary option

---

## Version 1.0.0 - Initial Release

### Core Features
- Comprehensive testing suite for all 34 Libft functions
- 200+ individual test cases
- Beautiful color-coded output
- Detailed statistics tracking
- Support for BSD functions (strlcpy, strlcat)
- Automatic libft.a compilation
- Professional Makefile with multiple targets
- Automated bash script for easy execution

### Test Coverage
- Part 1: 21 libc functions (133 tests)
- Part 2: 13 additional functions (82+ tests)
- Edge case testing for all functions
- Boundary value testing
- Memory leak prevention tests

### Documentation
- README.md with comprehensive instructions
- QUICK_START.md for rapid deployment
- PROJECT_SUMMARY.md with statistics
- PROJECT_STRUCTURE.md for code organization
- EXAMPLE_OUTPUT.md with visual samples

---

**For the complete documentation, see README.md**
